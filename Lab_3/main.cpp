#include <cstdlib>
#include <iostream>
#include "./Headers/Figure.h"
#include "./Headers/Octagon.h"
#include "./Headers/Triangle.h"
#include "./Headers/TSquare.h"
#include "Headers/TBinaryTree.h"
#include <memory>

const int NUMBER = 10;
void addToTree(TBinaryTree & tree);
void removeFromTree(TBinaryTree & tree);
int main() {
    TBinaryTree myTree;
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
void addToTree(TBinaryTree & tree) {
    std::string answer;
    std::cout << "What figure (o,s,t): ";
    std::cin >> answer;

    std::cout << "Enter size: ";
    size_t number;
    std::cin >> number;
    if(answer == "o") {
        tree.InsertInTree(Item(new Octagon(number)));
    } else if (answer == "s") {
        tree.InsertInTree(Item(new TSquare(number)));
    } else if (answer == "t") {
        tree.InsertInTree(Item(new Triangle(number)));
    }
}
void removeFromTree (TBinaryTree & tree) {
    std::string answer;
    std::cout << "What figure (o,s,t): ";
    std::cin >> answer;

    std::cout << "Enter size: ";
    size_t number;
    std::cin >> number;
    if(answer == "o") {
        tree.DeleteFromTree(Item(new Octagon(number)));
    } else if (answer == "s") {
        tree.DeleteFromTree(Item(new TSquare(number)));
    } else if (answer == "t") {
        tree.DeleteFromTree(Item(new Triangle(number)));
    }
}