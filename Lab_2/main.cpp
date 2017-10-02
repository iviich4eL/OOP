#include <cstdlib>
#include <iostream>
#include "./Headers/Octagon.h"
#include "Headers/TBinaryTree.h"

const int NUMBER = 10;
void addToTree(TBinaryTree & tree);
void removeFromTree(TBinaryTree & tree);
int main() {
    TBinaryTree myTree;
    std::string answer;

    std::cin >> answer;
    while (answer != "q"){
        if(answer == "a") {
            addToTree(myTree);
        } else if(answer == "d"){
            removeFromTree(myTree);
        } else if(answer == "p"){
            std::cout << myTree << std::endl;
        }
        std::cin >> answer;
    }
    std::cout << std::endl;
    return 0;
}
void addToTree(TBinaryTree & tree) {
    int number = 0;
    std::cin >> number;
    tree.InsertInTree(Octagon(number));
    std::cout << tree << std::endl;
}
void removeFromTree(TBinaryTree & tree) {
    int number = 0;
    std::cin >> number;
    tree.DeleteFromTree(Octagon(number));
    std::cout << tree << std::endl;
}