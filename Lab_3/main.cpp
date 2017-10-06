#include <cstdlib>
#include <iostream>
#include "./Headers/Octagon.h"
#include "./Headers/Triangle.h"
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
    int number;
    std::cin >> number;
    if(answer == "o") {
        tree.InsertInTree(new Octagon(number));
    } else if (answer == "s") {
        tree.InsertInTree(new TSquare(number));
    } else if (answer == "t") {
        tree.InsertInTree(new Triangle(number));
    }
}

void removeFromTree (TBinaryTree & tree) {
    std::string answer;
    std::cout << "What figure (o,s,t): ";
    std::cin >> answer;

    std::cout << "Enter size: ";
    int number;
    std::cin >> number;
    if(answer == "o") {
        tree.DeleteFromTree(new Octagon(number));
    } else if (answer == "s") {
        tree.DeleteFromTree(new TSquare(number));
    } else if (answer == "t") {
        tree.DeleteFromTree(new Triangle(number));
    }
}