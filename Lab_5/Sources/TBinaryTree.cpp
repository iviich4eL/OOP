#include "../Headers/TBinaryTree.h"

using std::ostream;
const int MY_SPECIAL_NUMBER = -1;

// Используем явную специализацию шаблонов
template <> bool TBinaryTree<Figure>::ToLeft(const shared_ptr<Figure> & i1,
                                             const shared_ptr<Figure> &i2) {
    return (i1.get())->Square() < (i2.get())->Square();
}

template <> bool TBinaryTree<Figure>::ToRight(const shared_ptr<Figure> &i1,
                                              const shared_ptr<Figure> &i2) {
    return (i1.get())->Square() > (i2.get())->Square();
}

template <typename T>
TNodePair TBinaryTree<T>::SeekTNode(const shared_ptr<T> & figure ) {
    TNodePair look;
    look.parent = nullptr;
    look.child = root;

    if (look.child == nullptr) {
        std::cout << this <<" tree is empty!" << std::endl;
        return look;
    } else {
        while(look.child != nullptr) {
            if ( ToLeft(figure, ((look.child).get())->item) ) {
                look.parent = look.child;
                look.child = look.child->left;
            } else if ( ToRight(figure, ((look.child).get())->item) ) {
                look.parent = look.child;
                look.child = look.child->right;
            } else {
                break;
            }
        }
    }
    return look;
}

template <typename T>
void TBinaryTree<T>::AddTNode(shared_ptr<TNode<T>> newTNode, shared_ptr<TNode<T>> root) {
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

template <typename T>
void TBinaryTree<T>::WalkTree(shared_ptr<TNode<T>> n, int count) {
    if(n == nullptr) return;
    WalkTree(n->right, count+=1);
    for (int i = 0; i < count; i++) {
        std::cout << "|--";
    }
    std::cout << *n << std::endl;
    WalkTree(n->left,count++);
}

template <typename T>
void TBinaryTree<T>::PrintTree() {
    std::cout << "Print Tree: " << this << std::endl;
    WalkTree(root, MY_SPECIAL_NUMBER);
}

template <typename T>
void TBinaryTree<T>::DeleteTNode(shared_ptr<TNode<T>>* parentTNode) {
    shared_ptr<TNode<T>> temp;

    if ( (*parentTNode)->left == nullptr){
        *parentTNode = (*parentTNode)->right;
    } else if( (*parentTNode)->right == nullptr){
        *parentTNode = (*parentTNode)->left;
    } else {
        for(temp = (*parentTNode)->left; temp->right != nullptr;
            temp = temp->right)
            continue;
        (temp)->right = (*parentTNode)->right;
        *parentTNode = (*parentTNode)->left;
    }
}

template <typename T>
TBinaryTree<T>::TBinaryTree() : root(nullptr){
    root = nullptr;
    std::cout << "Tree: " << this
              << " created " << std::endl;
}

template <typename T>
bool TBinaryTree<T>::InsertInTree(shared_ptr<T> && i) {
    shared_ptr<TNode<T>> newNode(new TNode<T>(i));
    if ( root == nullptr) {
        root = newNode;
        this->PrintTree();
        return true;
    } else {
        AddTNode(newNode, root);
        this->PrintTree();
        return true;
    }
}

template <typename T>
bool TBinaryTree<T>::DeleteFromTree(const shared_ptr<T> & figure) {
    TNodePair look = this->SeekTNode(figure);
    if (look.child == nullptr){
        std::cout << "No such item!" << std::endl;
        return false;
    }
    if(look.parent == nullptr) {
        this->DeleteTNode(&root);
    } else if (look.parent->left == look.child) {
        this->DeleteTNode(& (look.parent->left) );
    } else {
        this->DeleteTNode( &(look.parent->right) );
    }
    this->PrintTree();
    return true;
}

template <typename T>
TIterator<TNode<T>, T> TBinaryTree<T>::begin() {
    return TIterator<TNode<T>, T>(root);
};

template <typename T>
TIterator<TNode<T>, T> TBinaryTree<T>::end() {
    return TIterator<TNode<T>, T>(nullptr);
};

template <typename K>
ostream & operator<<(ostream & os, TBinaryTree<K> & Tr) {
    Tr.PrintTree();
    return os;
}

template <typename T>
TBinaryTree<T>::~TBinaryTree() {
    std::cout << "Tree: " << this
              << " deleted " << std::endl;
}

template class TBinaryTree<Figure>;
template class  TIterator<TNode<Figure> ,Figure>;
template ostream & operator<<(ostream & os, TBinaryTree<Figure> & Tr);