#ifndef TNTREE_H
#define TNTREE_H

#include "TNodeN.h"
#include "../../TIterator/TIterator.h"
#include "TTree.h"

#include <iostream>
#include <memory>

using std::shared_ptr;
typedef std::function<void(void)> cmd;

template <typename T>
class TNTree : public TTree<T>{
private:
    int size;
    shared_ptr<TNodeN<T>> root;

    bool SquareIsEqual(const shared_ptr<T> & i1, const shared_ptr<T> & i2);
    bool ToRight(const shared_ptr<T> & i1, const shared_ptr<T> & i2);

    bool SquareIsEqual( shared_ptr<T> & i1, shared_ptr<T> & i2);
    bool ToRight( shared_ptr<T> &i1,  shared_ptr<T> &i2);
    shared_ptr<TNodeN<T>> FindSame(shared_ptr<T> find);
    void WalkTree(shared_ptr<TNodeN<T>> cur, int offset = 0);

public:
    explicit TNTree() : root(nullptr), size(0) {
//        std::cout << "Tree: " << this
//                  << " created " << std::endl;
    };

    int Size() { return  size; };
    bool Insert(shared_ptr<T> && value) override;
    bool Delete(shared_ptr<T> && value) override;
    void Print();

    TIterator<TNodeN<T>, T> begin();
    TIterator<TNodeN<T>, T> end();

    template <typename K>
    friend ostream & operator<<(ostream & os, TNTree<K> & Tr);
    virtual ~TNTree();
};

const int MAX_ITEM = 4;

template<> bool TNTree<Figure>::SquareIsEqual(const shared_ptr<Figure> & i1,
                                              const shared_ptr<Figure> & i2) {
    return ( (i1.get())->Square() == (i2.get())->Square() );
}
template <> bool TNTree<Figure>::ToRight(const shared_ptr<Figure> &i1,
                                         const shared_ptr<Figure> &i2) {
    return (i1.get())->Square() > (i2.get())->Square();
}

template <> bool TNTree<cmd>::SquareIsEqual(shared_ptr<cmd> & i1, shared_ptr<cmd> & i2) {
    return false;
}
template <> bool TNTree<cmd>::ToRight(shared_ptr<cmd> &i1, shared_ptr<cmd> &i2) {
    return true;
}


template <typename T>
shared_ptr<TNodeN<T>> TNTree<T>::FindSame(shared_ptr<T> find){
    shared_ptr<TNodeN<T>> temp = nullptr;
    temp = temp->GoFarLeft(root);
    while (temp != nullptr) {
        if (SquareIsEqual((temp.get())->item, find)) {
            /* Очищаем стек, иначе в него могут попасть те же переменные,
               но из разного вызова функции */
            temp->stackOfTNode.ClearStack();
            return temp;
        }
        temp = temp->GetNext();
    }
    return temp;
}
template <typename T>
void TNTree<T>::WalkTree(shared_ptr<TNodeN<T>> current, int offset) {
    if (current == nullptr) {
        return;
    }
    for (int i = 0; i < offset; i++) {
        std::cout << "|--";
    }
    std::cout << *current << std::endl;
    WalkTree(current->son, offset + 1);
    WalkTree(current->brother, 1);
}

template <typename T>
bool TNTree<T>::Insert(shared_ptr<T> && value) {
    shared_ptr<TNodeN<T>> newNode(new TNodeN<T>(value));
    shared_ptr<TNodeN<T>> current = nullptr;
    current = FindSame(value);
    if (current != nullptr) {
        std::cout << "ERROR: no same items!" << std::endl;
        return false;
    }

    if (root == nullptr) {
        root = newNode;
        size++;
        return true;
    } else {
        current = root;
        shared_ptr<TNodeN<T>> temp = root;
        int ins = 0;

        while (current->brother != nullptr) {
            if (!ToRight(value, (current.get())->item )) {
                // Случай когда добавляемый элемент -- корень (наименьший)
                if (ins == 0) {
                    newNode->brother = root;
                    root = newNode;
                    size++;
                    return true;
                } else {
                    // вставка где-то в середине дерева
                    newNode->brother = temp->brother;
                    temp->brother = newNode;
//                newNode->parent = root;
                    size++;
                    return true;
                }
//                inserted = true;
            }
            current = current-> brother;
            if (ins > 0) {
                temp = temp->brother;
            }
            ins++;
        }
        // Вставка на краю дерева
        if (!ToRight(value, (current.get())->item )) {
            // Новый элемент -- предпоследний
            temp->brother = newNode;
            newNode->brother = current;
            size++;
            return true;
        } else {
            // Вставка в самый конец дерева
            current->brother = newNode;
            newNode->parent = root;
            size++;
            return true;
        }
    }
}
template <typename T>
bool TNTree<T>::Delete(shared_ptr<T> && value) {
    shared_ptr<TNodeN<T>> current = nullptr;
    current = FindSame(value);
    if (current == nullptr) {
        std::cout << "No such item!" << std::endl;
        return false;
    } else {
        if (SquareIsEqual((root.get())->item, value)) {
            root = root->brother;
            size--;
            return true;
        }
        current = root;
        // Тут не будет nullptr так как мы знаем что элемент точно есть
        while (!SquareIsEqual( (((current.get())->brother).get())->item, value)) {
            current = current->brother;
        }
        current->brother = current->brother->brother;
        size--;
        return true;
    }
}
template <typename T>
void TNTree<T>::Print() {
//    std::cout << "Print Tree: " << this << std::endl;
    std::cout << std::endl;
    WalkTree(root, 0);
}

template <typename T>
TIterator<TNodeN<T>, T> TNTree<T>::begin() {
    return TIterator<TNodeN<T>, T>(root);
};
template <typename T>
TIterator<TNodeN<T>, T> TNTree<T>::end() {
    return TIterator<TNodeN<T>, T>(nullptr);
};

template <typename K>
ostream & operator<<(ostream & os, TNTree<K> & TNTree) {
    TNTree.Print();
    return os;
}
template <typename T>
TNTree<T>::~TNTree() {
//    std::cout << "Tree: " << this
//              << " deleted " << std::endl;
}

#endif /* TNTREE_H */
