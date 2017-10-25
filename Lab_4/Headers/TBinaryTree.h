#ifndef TBINARYTREE_H
#define TBINARYTREE_H
#include "TNode.h"
#include <memory>

using std::ostream;
using std::shared_ptr;

typedef struct TNodePair{
    shared_ptr<TNode<Figure>> parent;
    shared_ptr<TNode<Figure>> child;
}TNodePair;

template <typename T>
class TBinaryTree {
private:
    shared_ptr<TNode<T>> root;

    bool ToLeft(const shared_ptr<T> & i1, const shared_ptr<T> & i2);
    bool ToRight(const shared_ptr<T> & i1, const shared_ptr<T> & i2);
    void AddTNode(shared_ptr<TNode<T>> newTNode,shared_ptr<TNode<T>> root);
    void WalkTree(shared_ptr<TNode<T>> n, int count);
    void PrintTree();
    TNodePair SeekTNode(const shared_ptr<T> & figure );
    void DeleteTNode(shared_ptr<TNode<T>>* parentTNode);
public:
    explicit TBinaryTree();

    bool InsertInTree(shared_ptr<T> && i);
    bool DeleteFromTree(const shared_ptr<T> & figure);
    template <typename K>
    friend ostream & operator<<(ostream & os, TBinaryTree<K> & Tr);
    virtual ~TBinaryTree();
};

#endif /* TBINARYTREE_H */
