#include "../Headers/TNode.h"
#include <iostream>
#include <cmath>

TNode::TNode(const Item & i) {
    item = i;
    right = left = nullptr;
//    std::cout << "Tree item: " << this
//              << " created: " << std::endl;
}
TNode & TNode::operator=(const TNode & Tn) {
    if (this == &Tn) {
        return *this;
    } else {
        item = Tn.item;
        right = Tn.right;
        left = Tn.left;
//            std::cout << " Octagon copied" << std::endl;
        return *this;
    }
}
TNode::~TNode() {
//    std::cout << "TNode " << this << " deleted" << std::endl;
//    delete left;
//    delete right;
}
ostream & operator<<(ostream & os, TNode & i ) {
    os << i.item;
    return os;
}