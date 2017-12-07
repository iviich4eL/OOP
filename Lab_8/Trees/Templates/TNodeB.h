#ifndef TNODEB_H
#define TNODEB_H


#include "../../Figures/Headers/Figure.h"
#include "../../TStack/TStack.h"
#include <memory>

using std::ostream;
using std::shared_ptr;

template <typename T>
class TBinTree;
template <typename T>
class TBinTreeReverse;

template <typename T>
class TNodeB {
    friend class TBinTree<T>;
    friend class TBinTreeReverse<T>;
private:
    shared_ptr<T> item;
    shared_ptr<TNodeB<T>> right;
    shared_ptr<TNodeB<T>> left;

    static TStack<shared_ptr<TNodeB<T>>> stackOfTNode;

public:
    explicit TNodeB(const shared_ptr<T> & i);

    shared_ptr<T> GetValue() const { return item; };
    shared_ptr<TNodeB<T>> GoFarLeft(shared_ptr<TNodeB<T>> current);
    shared_ptr<TNodeB<T>> GetNext();
    virtual ~TNodeB<T>();

    template <typename K>
    friend ostream & operator<<(ostream & os, TNodeB<K> & i );
};

template <typename T>
TStack<shared_ptr<TNodeB<T>>> TNodeB<T>::stackOfTNode;

template <typename T>
TNodeB<T>::TNodeB(const shared_ptr<T> & i) : item(i) {
    right = left = nullptr;
}
template <typename T>
shared_ptr<TNodeB<T>> TNodeB<T>::GoFarLeft(shared_ptr<TNodeB<T>> current) {
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
shared_ptr<TNodeB<T>> TNodeB<T>::GetNext(){
    shared_ptr<TNodeB<T>> temp;
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
TNodeB<T>::~TNodeB() {

}
template <typename T>
ostream & operator<<(ostream & os, TNodeB<T> & i ) {
    ((i.item).get())->Print();
    return os;
}
#endif /* NODEB_H */
