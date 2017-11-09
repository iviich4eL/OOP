#ifndef TNODE_H
#define TNODE_H

#include "../../Figures/Headers/Figure.h"
#include "../../TStack/TStack.h"
#include <memory>

using std::ostream;
using std::shared_ptr;

template <typename T>
class TBinaryTree;

template <typename T>
class TNode{
    friend class TBinaryTree<T>;
private:
    shared_ptr<T> item;
    shared_ptr<TNode<T>> right;
    shared_ptr<TNode<T>> left;

    static TStack<shared_ptr<TNode<T>>> stackOfTNode;


public:
    explicit TNode(const shared_ptr<T> & i);
    TNode & operator=(const TNode & Tn);
    virtual ~TNode<T>();

    shared_ptr<T> GetValue() const { return item; };
    shared_ptr<TNode<T>> GetNext();
    shared_ptr<TNode<T>> GoFarLeft(shared_ptr<TNode<T>> current);

    template <typename K>
    friend ostream & operator<<(ostream & os, TNode<K> & i );
};

template <typename T>
TStack<shared_ptr<TNode<T>>> TNode<T>::stackOfTNode;

#endif /* TNODE_H */


