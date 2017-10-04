#ifndef TNODE_H
#define TNODE_H

#include "Octagon.h"
#include <memory>

using std::ostream;
using std::shared_ptr;

typedef Octagon Item;
class TNode {
    friend class TBinaryTree;
private:
    Item item;
    std::shared_ptr<TNode> right;
    std::shared_ptr<TNode> left;

public:
    explicit TNode(const Item & i);
    TNode & operator=(const TNode & Tn);
    virtual ~TNode();

    friend ostream & operator<<(ostream & os, TNode & i );
};

#endif /* TNODE_H */
