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

#endif /* TSTACK_H */
