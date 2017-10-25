#include "../Headers/TNode.h"


template <typename T>
TNode<T>::TNode(const shared_ptr<T> & i) : item(i) {
    right = left = nullptr;
}

template <typename T>
TNode<T> & TNode<T>::operator=(const TNode<T> & Tn) {
    if (this == &Tn) {
        return *this;
    } else {
        item = Tn.item;
        right = Tn.right;
        left = Tn.left;
        return *this;
    }
}
template <typename T>
TNode<T>::~TNode() {

}

template <typename T>
ostream & operator<<(ostream & os, TNode<T> & i ) {
    ((i.item).get())->Print();
    return os;
}


template class TNode<Figure>;
template ostream & operator<<(ostream & os, TNode<Figure> & i );