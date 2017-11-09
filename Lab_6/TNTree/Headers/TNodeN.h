#ifndef TNODEN_H
#define TNODEN_H

#include "../../Figures/Headers/Figure.h"
#include "../../TStack/TStack.h"
#include <iostream>
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

    static TStack<shared_ptr<TNodeN<T>>> stackOfTNodeN;

public:
    explicit TNodeN (const shared_ptr<T> & i);

    template <typename K>
    friend ostream & operator<<(ostream & os, TNodeN<K> & i );

    shared_ptr<T> GetValue() const { return item; }
    shared_ptr<TNodeN<T>> GoFarLeft(shared_ptr<TNodeN<T>> cur);
    shared_ptr<TNodeN<T>> GetNext();
};

template <typename T>
TStack<shared_ptr<TNodeN<T>>> TNodeN<T>::stackOfTNodeN;

#endif /* TNODEN_H */
