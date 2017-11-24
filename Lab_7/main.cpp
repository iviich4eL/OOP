#include <cstdlib>
#include <iostream>
#include "Figures/Headers/Figure.h"
#include "Figures/Headers/Octagon.h"
#include "Figures/Headers/Triangle.h"
#include "Figures/Headers/TSquare.h"

#include "Trees/Templates/TBinTree.h"
#include "Trees/Templates/TNTree.h"
#include "Trees/Templates/TNTreeInTBinTree.h"

const int NUMBER = 10;

template <typename T>
void addToTree(T & tree);
template <typename T>
void removeFromTree(T & tree);
template <typename T>
void removeByType(T & tree);

int main() {
//    std::cout << "What tree ? (N -- N-Tree, B -- Binary Tree) " << std::endl;
    std::string answer;
//    std::cin >> answer;
    answer = 'B';
    if (answer == "B") {
//        TNTree<Figure> myTree;
//        TBinTree<Figure> myTree;
        TNTreeInTBinTree<Figure> myTree;
        while (answer != "q") {
            if (answer == "a") {
                addToTree(myTree);
            } else if(answer == "d") {
                removeFromTree(myTree);
            } else if (answer == "t") {
                removeByType(myTree);
            } else if (answer == "p") {
//                std::cout << myTree << std::endl;
                myTree.Print();
            }
            std::cin >> answer;
        }

//        std::cout << "[ ";
//        for (auto i : myTree) {
//            i->Print();
//            std::cout << " ";
//        }
//        std::cout << "]" << std::endl;

    }
    return 0;
}
template <typename T>
void addToTree(T & tree) {
    std::string answer;
    std::cout << "What figure (o,s,t): ";
    std::cin >> answer;

    std::cout << "Enter size: ";
    size_t number;
    std::cin >> number;
    if(answer == "o") {
        tree.Insert(shared_ptr<Figure>(new Octagon(number)));
    } else if (answer == "s") {
        tree.Insert(shared_ptr<Figure>(new TSquare(number)));
    } else if (answer == "t") {
        tree.Insert(shared_ptr<Figure>(new Triangle(number)));
    }
    std::cout<< std::endl;
    tree.Print();
}

template <typename T>
void removeFromTree (T & tree) {
    std::string answer;
    std::cout << "What figure (o,s,t): ";
    std::cin >> answer;

    std::cout << "Enter size: ";
    size_t number;
    std::cin >> number;
    if(answer == "o") {
        tree.Delete(shared_ptr<Figure>(new Octagon(number)));
//        IRemoveCriteriaByValue<Octagon> criteria(new Octagon(number));
//        tree.Delete(&criteria);
    } else if (answer == "s") {
        tree.Delete(shared_ptr<Figure>(new TSquare(number)));
//        IRemoveCriteriaByValue<TSquare> criteria(new TSquare(number));
//        tree.Delete(&criteria);
    } else if (answer == "t") {
        tree.Delete(shared_ptr<Figure>(new Triangle(number)));
//        IRemoveCriteriaByValue<Triangle> criteria(new Triangle(number));
//        tree.Delete(&criteria);
    }
//    std::cout<< std::endl;
    tree.Print();
}

template <typename T>
void removeByType(T & tree) {
    std::string answer;
    std::cout << "What figure (o,s,t): ";
    std::cin >> answer;

    if(answer == "o") {
        tree.DeleteByType(1);
    } else if (answer == "s") {
        tree.DeleteByType(3);
    } else if (answer == "t") {
        tree.DeleteByType(2);
    }
    std::cout<< std::endl;
    tree.Print();
}



