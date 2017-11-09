#ifndef TNTREE_H
#define TNTREE_H

#include "TNodeN.h"
#include "../../TIterator/TIterator.h"
#include <iostream>
#include <memory>

using std::shared_ptr;

template <typename T>
class TNTree {
private:
    shared_ptr <TNodeN<T>> root;

    bool SquareIsEqual(const shared_ptr<T> & i1, const shared_ptr<T> & i2);
    shared_ptr<TNodeN<T>> FindSame(shared_ptr<T> parentFigure);
    void WalkTree(shared_ptr<TNodeN<T>> cur, int offset = 0);

public:
    explicit TNTree();

    bool Insert(shared_ptr<T> && parentFigure, shared_ptr<T> && insertFigure);
    bool Delete(shared_ptr<T> && deleteFigure);
    void PrintTree();

    TIterator<TNodeN<T>, T> begin();
    TIterator<TNodeN<T>, T> end();

    template <typename K>
    friend ostream & operator<<(ostream & os, TNTree<K> & Tr);
};

#endif /* TNTREE_H */
