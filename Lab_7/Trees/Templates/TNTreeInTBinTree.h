#ifndef TNTREEINTBINTREE_H
#define TNTREEINTBINTREE_H

#include "TNTree.h"
#include "TBinTree.h"
#include <memory>

using std::shared_ptr;

template <typename T>

class TNTreeInTBinTree : TTree<T> {
private:
    TBinTree<TNTree<T>> superTree;
    bool test() {
        return true;
    }
public:
    explicit TNTreeInTBinTree () = default;
    bool Insert(shared_ptr<T> && value) override ;
    bool Delete(shared_ptr<T> && value) override;
    bool DeleteByType(int type);
    void Print();
    virtual ~TNTreeInTBinTree();
};

template <typename T>
bool TNTreeInTBinTree<T>::Insert(shared_ptr<T> &&value) {
    bool inserted = false;

    int count = 0;
    for (auto i : superTree) {
        count++;
        if ((i->Size() < 5) && (!inserted)){
            i->Insert(shared_ptr<Figure>(value));
//            std::cout << "TNTree № " << count << std::endl;
//            i->Print();
            inserted = true;
        }
    }

    if (!inserted) {
        shared_ptr<TNTree<T>> newTNTree(new TNTree<T>());
        newTNTree->Insert(shared_ptr<T>(value));
        superTree.Insert(shared_ptr<TNTree<T>>(newTNTree));
//        std::cout << "NEW Tree № " << count << std::endl;
//        newTNTree->Print();
    }
}
//        newTNTree->Insert(shared_ptr<Figure>(new TSquare(number)));
//        auto x = shared_ptr<Figure>(new TSquare(number));
//        shared_ptr<Figure> x = value;

template <typename T>
bool TNTreeInTBinTree<T>::Delete(shared_ptr<T> && value) {
    for (auto i : superTree) {
        i->Delete(shared_ptr<T>(value));
    }
}

template <typename T>
bool TNTreeInTBinTree<T>::DeleteByType(int type){
    for (auto i : superTree) {
        for (auto j : *i) {
            if (( (j.get())->Type() == type)  ) {
                i->Delete(shared_ptr<T>(j));
            }
        }
    }
}

template <typename T>
void TNTreeInTBinTree<T>::Print() {
    int count = 0;
    for(auto i : superTree) {
        if (i->Size() == 0) {
            continue;
        }
        std::cout << "Tree # "<< count;// << std::endl;
        i->Print();
        std::cout << std::endl;
        count++;
    }
}

template <typename T>
TNTreeInTBinTree<T>::~TNTreeInTBinTree() {

}

#endif /* LAB_6_1_TNTREEINTBINTREE_H */
