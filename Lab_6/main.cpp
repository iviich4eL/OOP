#include <cstdlib>
#include <iostream>
#include "Figures/Headers/Figure.h"
#include "Figures/Headers/Octagon.h"
#include "Figures/Headers/Triangle.h"
#include "Figures/Headers/TSquare.h"
#include "TBinaryTree/Headers/TBinaryTree.h"
#include "TNTree/Headers/TNTree.h"
const int NUMBER = 10;

template <typename T>
void addToTBinaryTree(TBinaryTree<T> & tree);
template <typename T>
void removeFromTBinaryTree(TBinaryTree<T> & tree);

template <typename T>
void addToTNTree(TNTree<T> & tree);
template <typename T>
void removeFromTNTree(TNTree<T> & tree);

int main() {


    std::cout << "What tree ? (N -- N-Tree, B -- Binary Tree) " << std::endl;
    std::string answer;
    std::cin >> answer;
    if (answer == "N") {
        TNTree<Figure> myTree;
        while (answer != "q") {
            if (answer == "a") {
                addToTNTree(myTree);
            } else if(answer == "d"){
                removeFromTNTree(myTree);
            } else if (answer == "p") {
                std::cout << myTree << std::endl;
            }
            std::cin >> answer;
        }

        std::cout << "[ ";
        for (auto i : myTree) {
            i->Print();
            std::cout << " ";
        }
        std::cout << "]" << std::endl;
    } else if (answer == "B") {
        TBinaryTree<Figure> myTree;
        while (answer != "q") {
            if (answer == "a") {
                addToTBinaryTree(myTree);
            } else if(answer == "d"){
                removeFromTBinaryTree(myTree);
            } else if (answer == "p") {
                std::cout << myTree << std::endl;
            }
            std::cin >> answer;
        }

        std::cout << "[ ";
        for (auto i : myTree) {
            i->Print();
            std::cout << " ";
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}
template <typename T>
void addToTBinaryTree(TBinaryTree<T> & tree) {
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
void removeFromTBinaryTree (TBinaryTree<T> & tree) {
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

template<typename T>
void addToTNTree(TNTree<T> &tree) {

    std::cout << "Enter side of Parent TSquare " << std::endl;
    size_t number1;
    std::cin >> number1;
    shared_ptr<T> parentFigure = shared_ptr<T>(new TSquare(number1));
    std::cout << "Enter side of Insert TSquare: " << std::endl;
    size_t number2;
    std::cin >> number2;
    shared_ptr<T> insertFigure = shared_ptr<T>(new TSquare(number2));

    if (number1 == 0) {
        tree.Insert(nullptr, shared_ptr<T>(insertFigure));

    } else if (number1 > 0){
        tree.Insert(shared_ptr<T>(parentFigure), shared_ptr<T>(insertFigure));
    }
    insertFigure = nullptr;
    parentFigure = nullptr;
    std::cout << tree << std::endl;
}

template<typename T>
void removeFromTNTree(TNTree<T> &tree) {

    std::cout << "Enter Parent Square: ";
    size_t number1;
    std::cin >> number1;

    tree.Delete( shared_ptr<T>(new TSquare(number1)) );
    std::cout << tree << std::endl;
}