#ifndef TNODEN_H
#define TNODEN_H

#include "../../Figures/Headers/Figure.h"
#include "../../TStack/TStack.h"
#include <memory>

using std::ostream;
using std::shared_ptr;

template <typename T>
class TNTree;

template <typename T>
class TNodeN {
    friend class TNTree<T>;
private:
    shared_ptr<T> item;
    shared_ptr<TNodeN<T>> parent;
    shared_ptr<TNodeN<T>> brother;
    shared_ptr<TNodeN<T>> son;

//    shared_ptr<TNodeN<T>> left;

    static TStack<shared_ptr<TNodeN<T>>> stackOfTNode;

public:
    explicit TNodeN(const shared_ptr<T> & i);

    shared_ptr<T> GetValue() const { return item; };
    shared_ptr<TNodeN<T>> GoFarLeft(shared_ptr<TNodeN<T>> current);
    shared_ptr<TNodeN<T>> GetNext();
    virtual ~TNodeN<T>();

    template <typename K>
    friend ostream & operator<<(ostream & os, TNodeN<K> & i );
};

template <typename T>
TStack<shared_ptr<TNodeN<T>>> TNodeN<T>::stackOfTNode;

template <typename T>
TNodeN<T>::TNodeN(const shared_ptr<T> & i) : item(i) {
    parent = brother = son = nullptr;
}
template <typename T>
shared_ptr<TNodeN<T>> TNodeN<T>::GoFarLeft(shared_ptr<TNodeN<T>> current) {
    if (current == nullptr) {
        return nullptr;
    }
    while (current->son != nullptr) {
        stackOfTNode.Push(current);
        current = current->son;
    }
    return current;
};
template <typename T>
shared_ptr<TNodeN<T>> TNodeN<T>::GetNext(){
    shared_ptr<TNodeN<T>> temp;
    if (this->brother != nullptr) {
        temp = GoFarLeft(this->brother);
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
TNodeN<T>::~TNodeN() {

}

template <typename T>
ostream & operator<<(ostream & os, TNodeN<T> & i ) {
//    ((i.item).get())->Print();
    return os;
}

#endif /* TNODEN_H */