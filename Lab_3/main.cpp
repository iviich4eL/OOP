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
    while (answer != "q"){
        if(answer == "a") {
            addToTree(myTree);
//        } else if(answer == "d"){
//            removeFromTree(myTree);
        } else if(answer == "p"){
            std::cout << myTree << std::endl;
        }
        std::cin >> answer;
    }
    std::cout << std::endl;

//    Triangle myFirstTriangle;
//    std::cin >> myFirstTriangle;
////    myFirstTriangle.ErrorInSquare();
//    std::cout << myFirstTriangle << std::endl;
//    std::cout << myFirstTriangle.Square() << std::endl;
//
//    Triangle mySecondTriangle;
//    std::cin >> mySecondTriangle;
//    mySecondTriangle.ErrorInSquare();
//    std::cout << mySecondTriangle << std::endl;
//    std::cout << mySecondTriangle.Square() << std::endl;
//
//    std::cout << (myFirstTriangle == mySecondTriangle) << std::endl;
//    std::cout << (myFirstTriangle < mySecondTriangle) << std::endl;
//    std::cout << (myFirstTriangle > mySecondTriangle) << std::endl;

    //    std::string answer;
//
//    TBinaryTree myTree;
//    std::string answer;
//    std::cin >> answer;
//    while (answer != "q"){
//        if(answer == "a") {
//            addToTree(myTree);
//        } else if(answer == "d"){
//            removeFromTree(myTree);
//        } else if(answer == "p"){
//            std::cout << myTree << std::endl;
//        }
//        std::cin >> answer;
//    }
//    std::cout << std::endl;
//    return 0;
}
//void addToTree(TBinaryTree & tree) {
//    int number_a, number_b, number_c;
//    std::cin >> number_a >> number_b >> number_c;
//    tree.DeleteFromTree(Triangle(number_a, number_b, number_c));
//    std::cout << tree << std::endl;
//}
//void removeFromTree(TBinaryTree & tree) {
//    int number_a, number_b, number_c;
//    std::cin >> number_a >> number_b >> number_c;
//    tree.DeleteFromTree(Triangle(number_a, number_b, number_c));
//    std::cout << tree << std::endl;
//}

void addToTree(TBinaryTree & tree) {
    int number = 0;
    std::cin >> number;
    tree.InsertInTree(Octagon(number));
    std::cout << tree << std::endl;
}
//void removeFromTree(TBinaryTree & tree) {
//    int number = 0;
//    std::cin >> number;
//    tree.DeleteFromTree(Octagon(number));
//    std::cout << tree << std::endl;
//}