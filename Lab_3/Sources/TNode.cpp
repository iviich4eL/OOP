#include "../Headers/TNode.h"
#include "../Headers/Figure.h"
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

}
ostream & operator<<(ostream & os, TNode & i ) {
    ((i.item).get())->Print();
    return os;
}