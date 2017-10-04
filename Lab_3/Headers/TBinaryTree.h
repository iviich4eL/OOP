#ifndef TBINARYTREE_H
#define TBINARYTREE_H
#include "TNode.h"
#include <memory>

using std::ostream;
using std::shared_ptr;

typedef struct TNodePair{
    shared_ptr<TNode> parent;
    shared_ptr<TNode> child;
} TNodePair;

class TBinaryTree {
private:
    shared_ptr<TNode> root;

    bool ToLeft(const Item & i1, const Item & i2);
    bool ToRight(const Item & i1, const Item & i2);
    void AddTNode(shared_ptr<TNode> newTNode, shared_ptr <TNode> root);
    void WalkTree(shared_ptr<TNode> n, int count);
    void PrintTree();
//    TNodePair SeekItem(const Item & i);
//    void DeleteTNode(shared_ptr<TNode>,shared_ptr<TNode> parentTNode);

public:
    explicit TBinaryTree();

    bool InsertInTree(Item i);
//    bool DeleteFromTree(const Item & i);
    friend ostream & operator<<(ostream & os, TBinaryTree & Tr);
    virtual ~TBinaryTree();
};

#endif /* TBINARYTREE_H */
