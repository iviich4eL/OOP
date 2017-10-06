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
    PTNode root;

    bool ToLeft(const Item & i1, const Item & i2);
    bool ToRight(const Item & i1, const Item & i2);
    void AddTNode(PTNode newTNode,PTNode root);
    void WalkTree(PTNode n, int count);
    void PrintTree();
    TNodePair SeekTNode(const Item & figure );
    void DeleteTNode(PTNode* parentTNode);
public:
    explicit TBinaryTree();

    bool InsertInTree(Item && i);
    bool DeleteFromTree(const Item & figure);
    friend ostream & operator<<(ostream & os, TBinaryTree & Tr);
    virtual ~TBinaryTree();
};

#endif /* TBINARYTREE_H */
