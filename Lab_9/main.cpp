#include <iostream>

#include <cstdlib>
#include <iostream>
#include "Figures/Headers/Figure.h"
#include "Figures/Headers/Octagon.h"
#include "Figures/Headers/Triangle.h"
#include "Figures/Headers/TSquare.h"

#include "Trees/Templates/TBinTree.h"
#include "Trees/Templates/TNTree.h"

#include <thread>
#include <future>
#include <functional>
#include <chrono>
#include <random>

using namespace std::chrono;

void addToTree(TBinTree<Figure> & tree,int number) {
    std::this_thread::sleep_for(seconds(1));
    int randomNumber = rand() % 3 + 1;
    if (randomNumber == 1) {
        tree.Insert(shared_ptr<Figure>(new TSquare(number)));
    } else if (randomNumber == 2) {
        tree.Insert(shared_ptr<Figure>(new Octagon(number)));
    } else if (randomNumber == 3) {
        tree.Insert(shared_ptr<Figure>(new Triangle(number)));
    }
}

int main() {
    TBinTree<Figure> myTree;
    typedef std::function<void(void)> command;
    std::mutex myMytex;

    command cmd_insert = [&]() {
        std::lock_guard<std::mutex> myGuard(myMytex);
        std::cout << "Command: Create Figure" << std::endl;

        for (int i = 0; i < 10; i++) {
            int figureType = 1 + rand() % 3 ;
            int number = 1 + rand() % 10;

            if (figureType == 1) {
                myTree.Insert(shared_ptr<Figure>(new Triangle(number)));
            } else if (figureType == 2) {
                myTree.Insert(shared_ptr<Figure>(new TSquare(number)));
            } else if (figureType == 3) {
                myTree.Insert(shared_ptr<Figure>(new Octagon(number)));
            }
        }
    };

    command cmd_print = [&]() {
        std::lock_guard<std::mutex> myGuard(myMytex);
        std::cout << "Command: Print tree" << std::endl;
        myTree.Print();
    };

    command cmd_delete = [&] {
        std::lock_guard<std::mutex> myGuard(myMytex);
        std::cout << "Command: Delete" << std::endl;
        int square = 1 + rand() % 500;

        if (myTree.Size() == 0) {
            std::cout << "Tree is empty!" << std::endl;
        } else {
            std::cout << "Square: " << square << std::endl;
            for (auto i : myTree) {
                if (i->Square() < square) {
                    myTree.Delete(shared_ptr<Figure>(i));
                }
            }
        }

    };

    TNTree<command> tree_cmd;
    std::cout << "Create tree of Commands[5]" << std::endl;
    std::cout << "1 -- insert, 2 -- delete, 3 -- print" << std::endl;
    int Commands[5] = {0};
    for (int i = 0; i < 5; i++ ) {
        std::cin >> Commands[i];
        if (Commands[i] == 1) {
            tree_cmd.Insert(shared_ptr<command>(&cmd_insert,[](command*) {} ));
        } else if (Commands[i] == 2) {
            tree_cmd.Insert(shared_ptr<command>(&cmd_delete,[](command*) {} ));
        } else if (Commands[i] == 3) {
            tree_cmd.Insert(shared_ptr<command>(&cmd_print, [](command*) {} ));
        }
    }

    for (auto i : tree_cmd) {
        std::shared_ptr<command> myCommand = i;
        std::future<void> ft  = std::async(*myCommand);
        ft.get();
    }

    return 0;
}