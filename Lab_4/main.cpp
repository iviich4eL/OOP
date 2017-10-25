#include <cstdlib>
#include <iostream>
#include "./Headers/Figure.h"
#include "./Headers/Octagon.h"
#include "./Headers/Triangle.h"
#include "./Headers/TSquare.h"
#include "Headers/TBinaryTree.h"
#include <memory>

const int NUMBER = 10;
template <typename T>
void addToTree(TBinaryTree<T> & tree);
template <typename T>
void removeFromTree(TBinaryTree<T> & tree);
int main() {
    TBinaryTree<Figure> myTree;
    std::string answer;

    std::cin >> answer;
    while (answer != "q") {
        if (answer == "a") {
            addToTree(myTree);
        } else if(answer == "d"){
            removeFromTree(myTree);
        } else if (answer == "p") {
            std::cout << myTree << std::endl;
        }
        std::cin >> answer;
    }
    std::cout << std::endl;
}
template <typename T>
void addToTree(TBinaryTree<T> & tree) {
    std::string answer;
    std::cout << "What figure (o,s,t): ";
    std::cin >> answer;

    std::cout << "Enter size: ";
    size_t number;
    std::cin >> number;
    if(answer == "o") {
        tree.InsertInTree(shared_ptr<T>(new Octagon(number)));
    } else if (answer == "s") {
        tree.InsertInTree(shared_ptr<T>(new TSquare(number)));
    } else if (answer == "t") {
        tree.InsertInTree(shared_ptr<T>(new Triangle(number)));
    }
}

template <typename T>
void removeFromTree (TBinaryTree<T> & tree) {
    std::string answer;
    std::cout << "What figure (o,s,t): ";
    std::cin >> answer;

    std::cout << "Enter size: ";
    size_t number;
    std::cin >> number;
    if(answer == "o") {
        tree.DeleteFromTree(shared_ptr<T>(new Octagon(number)));
    } else if (answer == "s") {
        tree.DeleteFromTree(shared_ptr<T>(new TSquare(number)));
    } else if (answer == "t") {
        tree.DeleteFromTree(shared_ptr<T>(new Triangle(number)));
    }
}