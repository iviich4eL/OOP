#ifndef TNODE_H
#define TNODE_H

#include "Octagon.h"

using std::ostream;

typedef Octagon Item;
class TNode {
    friend class TBinaryTree;
private:
    Item item;
    TNode * right;
    TNode * left;

public:
    explicit TNode(const Item & i);
    TNode & operator=(const TNode & Tn);
    virtual ~TNode();

    friend ostream & operator<<(ostream & os, TNode & i );
};

#endif /* TNODE_H */
