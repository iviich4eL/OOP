#include "../Headers/TNodeN.h"


template <typename T>
TNodeN<T>::TNodeN(const shared_ptr<T> &i) : item(i) {
   parent = brother = son = nullptr;
}

template <typename K>
ostream & operator<<(ostream & os, TNodeN<K> & i ) {
    ((i.item).get())->Print();
    return os;
}

template <typename T>
shared_ptr<TNodeN<T>> TNodeN<T>::GoFarLeft(shared_ptr<TNodeN<T>> current) {
    if (current == nullptr) {
        return nullptr;
    }
    while (current->son != nullptr) {
        stackOfTNodeN.Push(current);
        current = current->son;
    }
    return current;
}

template <typename T>
shared_ptr<TNodeN<T>> TNodeN<T>::GetNext() {
    shared_ptr<TNodeN<T>> temp = nullptr;
    if (this->brother != nullptr) {
        temp = GoFarLeft(this->brother);
    } else if (!stackOfTNodeN.IsEmpty()) {
        temp = stackOfTNodeN.Pop();
    } else {
        temp = nullptr;
    }
    return temp;
}

template class TStack<shared_ptr<TNodeN<Figure>>>;
template class TNodeN<Figure>;
template ostream & operator<<(ostream & os, TNodeN<Figure> & i );