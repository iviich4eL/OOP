#include "../Headers/TBinaryTree.h"

using std::ostream;
const int MY_SPECIAL_NUMBER = -1;

bool TBinaryTree::ToLeft(const Item &i1, const Item &i2) {
    return i1 < i2;
}
bool TBinaryTree::ToRight(const Item &i1, const Item &i2) {
    return i1 > i2;
}
void TBinaryTree::AddTNode(TNode * newTNode, TNode * root) {
    if (ToLeft(newTNode->item, root->item)) {
        if (root->left == nullptr) {
            root->left = newTNode;
        } else {
            AddTNode(newTNode, (root->left));
        }
    } else if (ToRight(newTNode->item, root->item)) {
        if (root->right== nullptr) {
            root->right = newTNode;
        } else {
            AddTNode(newTNode, (root->right));
        }
    } else {
        std::cout << "No same items!" << std::endl;
        return;
    }
}
void TBinaryTree::WalkTree(TNode * n, int count) {
    if(n == nullptr) return;
    WalkTree(n->right, count+=1);
    for (int i = 0; i < count; i++) {
        std::cout << "|--";
    }
    std::cout <<*n << std::endl;
    WalkTree(n->left,count++);
}
void TBinaryTree::PrintTree() {
    std::cout << "Print Tree: " << this << std::endl;
    WalkTree(root, MY_SPECIAL_NUMBER);
}
TNodePair TBinaryTree::SeekItem(const Item & i) {
    TNodePair look{nullptr, root};

    if (look.child == nullptr) {
        std::cout << this <<" tree is empty!" << std::endl;
        return look;
    } else {
        while(look.child != nullptr) {
            if (ToLeft(i, look.child->item)) {
                look.parent = look.child;
                look.child = look.child->left;
            } else if (ToRight(i, look.child->item)) {
                look.parent = look.child;
                look.child = look.child->right;
            } else {
                break;
            }
        }
    }
    return look;
}
void TBinaryTree::DeleteTNode(TNode ** parentTNode) {
    TNode * temp;

    if ( (*parentTNode)->left == nullptr){
        std::cout << (*parentTNode)->item << " was deleted " << std::endl;
        *parentTNode = (*parentTNode)->right;
    } else if( (*parentTNode)->right == nullptr){
        std::cout << (*parentTNode)->item << " was deleted " << std::endl;
        *parentTNode = (*parentTNode)->left;
    } else {
        for(temp = (*parentTNode)->left; temp->right != nullptr;
                temp = temp->right)
            continue;
        (temp)->right = (*parentTNode)->right;
        std::cout << (*parentTNode)->item << " was deleted " << std::endl;
        *parentTNode = (*parentTNode)->left;
    }
}

TBinaryTree::TBinaryTree(){
    root = nullptr;
    std::cout << "Tree: " << this
              << " created " << std::endl;
}

bool TBinaryTree::InsertInTree(Item i) {
    TNode *newNode = new TNode(i);
    if ( root == nullptr) {
        root = newNode;
        return true;
    } else {
        AddTNode(newNode, root);
        return true;
    }
}
bool TBinaryTree::DeleteFromTree(const Item & i) {
    TNodePair look = this->SeekItem(i);

    if (look.child == nullptr){
        std::cout << "No such item!" << std::endl;
        return false;
    }
    if(look.parent == nullptr) {
        this->DeleteTNode(&root);
    } else if (look.parent->left == look.child) {
        this->DeleteTNode( &(look.parent->left) );
    } else {
        this->DeleteTNode( &(look.parent->right) );
    }
    return true;
}

ostream & operator<<(ostream & os, TBinaryTree & Tr) {
    Tr.PrintTree();
    return os;
}

TBinaryTree::~TBinaryTree() {
    std::cout << "Tree: " << this
              << " deleted " << std::endl;
    delete root;
}