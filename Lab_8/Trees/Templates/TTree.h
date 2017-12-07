#ifndef TTREE_H
#define TTREE_H

#include "../../TIterator/TIterator.h"
#include <memory>

using std::ostream;
using std::shared_ptr;

template <typename T>
class TTree {
public:
    virtual bool Insert(shared_ptr<T> && value) = 0;
    virtual bool Delete(shared_ptr<T> && value) = 0;
    virtual void Print() = 0;
    virtual ~TTree() {};
};

#endif /* TTREE_H */
