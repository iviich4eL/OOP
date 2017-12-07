#include <iostream>

#include <cstdlib>
#include <iostream>
#include "Figures/Headers/Figure.h"
#include "Figures/Headers/Octagon.h"
#include "Figures/Headers/Triangle.h"
#include "Figures/Headers/TSquare.h"

#include "Trees/Templates/TBinTree.h"

#include <thread>
#include <future>
#include <functional>
#include <chrono>
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
    TBinTree<Figure> FirstTree;

    system_clock::time_point start = system_clock::now();
    for (int i = 0; i < 10; i+=2) {
        std::future<void> insertInTree = std::async(std::launch::async, addToTree, std::ref(FirstTree), i);
        std::packaged_task<void(TBinTree<Figure> &, int)> task(addToTree);
        std::thread insertThread(std::move(task), std::ref(FirstTree), i+1);
        insertThread.join();
    }
    auto end = system_clock::now();
    auto diff = duration_cast < std::chrono::seconds > (end - start).count();
    std::cout << "FirstTree " << std::endl;
    std::cout << "Total time taken = " << diff << " seconds" << std::endl;
    FirstTree.Print();


    TBinTree<Figure> SecondTree;
    start = system_clock::now();
    for (int i = 0; i < 10; i++) {
        addToTree(SecondTree, i+1);
    }
    end = system_clock::now();
    diff = duration_cast < std::chrono::seconds > (end - start).count();
    std::cout << "SecondTree " << std::endl;
    std::cout << "Total time taken = " << diff << " seconds" << std::endl;
    SecondTree.Print();

    return 0;
}