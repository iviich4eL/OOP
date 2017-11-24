#ifndef TITERATOR_H
#define TITERATOR_H

#include "../TStack/TStack.h"
using std::shared_ptr;
using std::endl;

template <typename node, typename T>
class TIterator {
private:
    shared_ptr<node> current;
public:
    explicit TIterator(shared_ptr<node> root){
        current = current->GoFarLeft(root);
    }
    shared_ptr<T> operator *() {
        return current->GetValue();
    }
    shared_ptr<T> operator->() {
        return current->GetValue();
    }
    void operator++() {
        current = current->GetNext();
    }
    TIterator operator ++ (int) {
        TIterator iter (*this);
        ++(*this);
        return iter;
    }
    bool operator == (TIterator const & i) {
        return (current == i.current);
    }
    bool operator != (TIterator const & i) {
        return !(*this == i);
    }
};

#endif /* TITERATOR_H */