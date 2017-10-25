#ifndef TNODE_H
#define TNODE_H

#include "Octagon.h"
#include <memory>

using std::ostream;
using std::shared_ptr;

//template <typename T>
//class TNode; //forward declaration
//
//typedef shared_ptr<Figure> Item;
//typedef shared_ptr<TNode<Figure>> PTNode;

template <typename T>
class TBinaryTree;

template <typename T>
class TNode{
    friend class TBinaryTree<T>;
private:
    shared_ptr<T> item;
    shared_ptr<TNode<T>> right;
    shared_ptr<TNode<T>> left;

public:
    explicit TNode(const shared_ptr<T> & i);
    TNode & operator=(const TNode & Tn);
    virtual ~TNode<T>();
    template <typename K>
    friend ostream & operator<<(ostream & os, TNode<K> & i );
};

#endif /* TNODE_H */


