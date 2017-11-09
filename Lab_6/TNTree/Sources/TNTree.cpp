#include "../Headers/TNTree.h"

const int MAX_ITEM = 4;

template <typename T>
TNTree<T>::TNTree() : root(nullptr) {
    std::cout << "Tree: " << this
              << " created " << std::endl;
}

template<> bool TNTree<Figure>::SquareIsEqual(const shared_ptr<Figure> & i1,
                                        const shared_ptr<Figure> & i2) {
    return ( (i1.get())->Square() == (i2.get())->Square() );
}

template <typename T>
shared_ptr<TNodeN<T>> TNTree<T>::FindSame(shared_ptr<T> parentFigure){

    shared_ptr<TNodeN<T>> temp = nullptr;
    temp = temp->GoFarLeft(root);
    while (temp != nullptr) {
//        std::cout << (((temp.get())->item).get())->Square() << " ";
        if (SquareIsEqual((temp.get())->item, parentFigure)) {
//            std::cout << "|" <<(((temp.get())->item).get())->Square() << "|; ";

            /* Очищаем стек, иначе в него могут попасть те же переменные,
               но из разного вызова функции */
            temp->stackOfTNodeN.ClearStack();
            return temp;
        }
        temp = temp->GetNext();
    }
    return temp;
}

template <typename T>
bool TNTree<T>::Insert(shared_ptr<T> && parentFigure, shared_ptr<T> && insertFigure) {
    shared_ptr<TNodeN<T>> current = nullptr;
    if (parentFigure == nullptr) {
        if (root == nullptr) {
            shared_ptr<TNodeN<T>> newNode(new TNodeN<T>(insertFigure));
            root = newNode;
            root->parent = nullptr;
            return true;
        } else {
            std::cout << "ERROR; Enter parent!" << std::endl;
            return false;
        }
    } else {
        current = FindSame(parentFigure);
        if (current == nullptr) {
            std::cout << "ERROR; No such parent in tree!" << std::endl;
        } else {
            if (!FindSame(insertFigure)) {
                if (current->son == nullptr) {
                    shared_ptr<TNodeN<T>> newNode(new TNodeN<T>(insertFigure));
                    current->son = newNode;
                    current->son->parent = current;
                    return true;
                } else if (current->son != nullptr) {
                    shared_ptr<TNodeN<T>> temp = current;
                    current = current->son;
                    int count = 0;
                    while (current->brother != nullptr) {
                        current = current->brother;
                        if (++count == MAX_ITEM - 1) {
                            std::cout << "ERROR; Node already have 4 sons!" << std::endl;
                            return false;
                        }
                    }
                    shared_ptr<TNodeN<T>> newNode(new TNodeN<T>(insertFigure));
                    current->brother = newNode;
                    newNode->parent = temp;
                    return true;
                }
            } else {
                std::cout << "No same items!" << std::endl;
                return false;
            }
        }
    }
}

template <typename T>
bool TNTree<T>::Delete(shared_ptr<T> && deleteFigure) {
    shared_ptr<TNodeN<T>> current = nullptr;
    current = FindSame(deleteFigure);
    if (current == nullptr) {
        std::cout << "No such item!" << std::endl;
    } else {
        current = current->parent;
        if (current )
        current->son = current->son->brother;
    }
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
    WalkTree(current->brother, offset);
}

template <typename T>
void TNTree<T>::PrintTree() {
    std::cout << "Print Tree: " << this << std::endl;
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
    TNTree.PrintTree();
    return os;
}

template class TNTree<Figure>;
template ostream & operator<<(ostream & os, TNTree<Figure> & Tr);