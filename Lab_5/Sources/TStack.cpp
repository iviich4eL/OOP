#include "../Headers/TStack.h"
template <typename T>
void TStack<T>::Push(const T & itm) {
    if (top == MAX_TSTACK_SIZE) {
        std::cerr << "TStack is full!\n";
        exit(1);
    }
    else {
        items[top++] = itm;
    }
}

template <typename T>
T TStack<T>::Pop() {
    T temp(0);
    if (top > 0) {
        temp = items[--top];
        return temp;
    }
    else {
        std::cerr << "TStack is empty!\n";
        exit(1);
    }
}

#include "../Headers/Figure.h"
#include "../Headers/TNode.h"
template class TStack<shared_ptr<TNode<Figure>>>;