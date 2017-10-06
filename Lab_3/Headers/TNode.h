#ifndef TNODE_H
#define TNODE_H

#include "Octagon.h"
#include <memory>

using std::ostream;
using std::shared_ptr;

class TNode; //forward declaration
typedef shared_ptr<Figure> Item;
typedef shared_ptr<TNode> PTNode;

class TNode {
    friend class TBinaryTree;
private:
    Item item;
    PTNode right;
    PTNode left;

public:
    explicit TNode(const Item & i);
    TNode & operator=(const TNode & Tn);
    virtual ~TNode();

    friend ostream & operator<<(ostream & os, TNode & i );
};

#endif /* TNODE_H */


