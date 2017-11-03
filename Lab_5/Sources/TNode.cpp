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
shared_ptr<TNode<T>> TNode<T>::GoFarLeft(shared_ptr<TNode<T>> current) {
    if (current == nullptr) {
        return nullptr;
    }
    while (current->left != nullptr) {
        stackOfTNode.Push(current);
        current = current->left;
    }
    return current;
};

template <typename T>
shared_ptr<TNode<T>> TNode<T>::GetNext(){
    shared_ptr<TNode<T>> temp;
    if (this->right != nullptr) {
        temp = GoFarLeft(this->right);
    }
    else if(!stackOfTNode.IsEmpty()){
        temp = stackOfTNode.Pop();
    }
    else {
        temp = nullptr;
    }
    return temp;
};

template <typename T>
ostream & operator<<(ostream & os, TNode<T> & i ) {
    ((i.item).get())->Print();
    return os;
}


template class TNode<Figure>;
template ostream & operator<<(ostream & os, TNode<Figure> & i );