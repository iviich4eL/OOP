#ifndef TSTACK_H
#define TSTACK_H

#include <iostream>
#include <memory>
using std::shared_ptr;
const int MAX_TSTACK_SIZE = 20;

template <typename T>
class TStack {
private:
    T items[MAX_TSTACK_SIZE];
    int top;
public:
    TStack() : top(0) {};
    bool IsEmpty() const { return  top == 0; };
    bool IsFull() const { return top == MAX_TSTACK_SIZE; };
    void Push(const T & itm);
    T Pop();
    void ClearStack() { top = 0; };
};

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


#endif /* TSTACK_H */
