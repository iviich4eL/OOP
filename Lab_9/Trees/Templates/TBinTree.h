#ifndef TBINARYTREE_H
#define TBINARYTREE_H

#include "../../TIterator/TIterator.h"
#include "TNodeB.h"
#include "TTree.h"
#include <iostream>
#include <memory>
#include <mutex>
#include <future>
#include <functional>


using std::ostream;
using std::shared_ptr;

const int RIGHT = 0;
const int LEFT = 1;

template <typename T>
class TNodePair {
public:
    shared_ptr<TNodeB<T>> parent;
    shared_ptr<TNodeB<T>> child;
};

template <typename T>
class TBinTree : public TTree<T> {
private:
    shared_ptr<TNodeB<T>> root;
    int size;
    std::mutex TBinaryTreeMutex;

    bool ToLeft(const shared_ptr<Figure> & i1, const shared_ptr<Figure> & i2);
    bool ToRight(const shared_ptr<Figure> & i1, const shared_ptr<Figure> & i2);

    void AddTNode(shared_ptr<TNodeB<T>> newTNode,shared_ptr<TNodeB<T>> root);
    void InsertTNodeB(shared_ptr<TNodeB<T>> newTNode, shared_ptr<TNodeB<T>>* root, int node);

    void WalkTree(shared_ptr<TNodeB<T>> current, int offset);
    TNodePair<T> SeekTNode(const shared_ptr<T> & figure );
    void DeleteTNode(shared_ptr<TNodeB<T>>* parentTNode);

public:
    explicit TBinTree() : root(nullptr), size(0){
    };

    bool Insert(shared_ptr<T> && value) override;
    bool Delete(shared_ptr<T> && value) override;
    void Print() override;

    TIterator<TNodeB<T>, T> begin();
    TIterator<TNodeB<T>, T> end();

    int Size() { return size; }
    template <typename K>
    friend ostream & operator<<(ostream & os, TBinTree<K> & Tr);
    virtual ~TBinTree();
};

//using std::ostream;
const int MY_SPECIAL_NUMBER = -1;

// Используем явную специализацию шаблонов
template <> bool TBinTree<Figure>::ToLeft(const shared_ptr<Figure> & i1,
                                          const shared_ptr<Figure> & i2) {
    return (i1.get())->Square() < (i2.get())->Square();
}
template <> bool TBinTree<Figure>::ToRight(const shared_ptr<Figure> & i1,
                                           const shared_ptr<Figure> & i2) {
    return (i1.get())->Square() > (i2.get())->Square();
}

template <typename T>
TNodePair<T> TBinTree<T>::SeekTNode(const shared_ptr<T> & figure ) {
    TNodePair<T> look;
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
void TBinTree<T>::AddTNode(shared_ptr<TNodeB<T>> newTNode, shared_ptr<TNodeB<T>> root) {
    if (ToLeft(newTNode->item, root->item)) {
        if (root->left == nullptr) {
            InsertTNodeB(newTNode, &root, LEFT);
        } else {
            AddTNode(newTNode, (root->left));
        }
    } else if (ToRight(newTNode->item, root->item)) {
        if (root->right == nullptr) {
            InsertTNodeB(newTNode, &root, RIGHT);
        } else {
            AddTNode(newTNode, (root->right));
        }
    } else {
        std::cout << "No same items!" << std::endl;
        return;
    }
}
template <typename T>
void TBinTree<T>::InsertTNodeB(shared_ptr<TNodeB<T>> newTNode, shared_ptr<TNodeB<T>>* root, int node) {
    std::lock_guard<std::mutex> TBinaryTreeLock(TBinaryTreeMutex);
    if (node == LEFT) {
        (*root)->left = newTNode;
    } else if (node == RIGHT) {
        (*root)->right = newTNode;
    }
}

template <typename T>
void TBinTree<T>::WalkTree(shared_ptr<TNodeB<T>> current, int offset) {
    if(current == nullptr) return;
    WalkTree(current->right, offset+=1);
    for (int i = 0; i < offset; i++) {
        std::cout << "|--";
    }
    std::cout << *current << std::endl;
    WalkTree(current->left,offset++);
}
template <typename T>
void TBinTree<T>::DeleteTNode(shared_ptr<TNodeB<T>>* parentTNode) {
    shared_ptr<TNodeB<T>> temp;

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
bool TBinTree<T>::Insert(shared_ptr<T> && value) {
    shared_ptr<TNodeB<T>> newNode(new TNodeB<T>(value));
    if ( root == nullptr) {
        root = newNode;
//        this->Print();
        size++;
        return true;
    } else {
        AddTNode(newNode, root);
//        this->Print();
        size++;
        return true;
    }
}
template <typename T>
bool TBinTree<T>::Delete(shared_ptr<T> && value) {
    TNodePair<T> look = this->SeekTNode(value);
    if (look.child == nullptr){
        std::cout << "No such item!" << std::endl;
        return false;
    }
    if(look.parent == nullptr) {
        this->DeleteTNode(&root);
    } else if (look.parent->left == look.child) {
        this->DeleteTNode(&(look.parent->left) );
    } else {
        this->DeleteTNode(&(look.parent->right) );
    }
//    this->Print();
    size--;
    return true;
}
template <typename T>
void TBinTree<T>::Print() {
    WalkTree(root, MY_SPECIAL_NUMBER);
}

template <typename T>
TIterator<TNodeB<T>, T> TBinTree<T>::begin() {
    return TIterator<TNodeB<T>, T>(root);
};
template <typename T>
TIterator<TNodeB<T>, T> TBinTree<T>::end() {
    return TIterator<TNodeB<T>, T>(nullptr);
};

template <typename T>
ostream & operator<<(ostream & os, TBinTree<T> & Tr) {
    Tr.Print();
    return os;
}
template <typename T>
TBinTree<T>::~TBinTree() {
}

#endif /* TBINARYTREE_H */
