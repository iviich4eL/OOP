#ifndef TBINARYTREE_H
#define TBINARYTREE_H
#include "TNode.h"

using std::ostream;

typedef struct TNodePair{
    TNode * parent;
    TNode * child;
} TNodePair;

class TBinaryTree {
private:
    TNode * root;

    bool ToLeft(const Item & i1, const Item & i2);
    bool ToRight(const Item & i1, const Item & i2);
    void AddTNode(TNode * newTNode, TNode * root);
    void WalkTree(TNode * n, int count);
    void PrintTree();
    TNodePair SeekItem(const Item & i);
    void DeleteTNode(TNode ** parentTNode);

public:
    explicit TBinaryTree();

    bool InsertInTree(Item i);
    bool DeleteFromTree(const Item & i);
    friend ostream & operator<<(ostream & os, TBinaryTree & Tr);
    virtual ~TBinaryTree();
};

#endif /* TBINARYTREE_H */
