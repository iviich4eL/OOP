cmake_minimum_required(VERSION 3.8)
project(Lab_6)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Figures/Headers/Figure.h Figures/Headers/Octagon.h TBinaryTree/Headers/TBinaryTree.h TBinaryTree/Headers/TNode.h Figures/Sources/Octagon.cpp TBinaryTree/Sources/TNode.cpp TBinaryTree/Sources/TBinaryTree.cpp Figures/Headers/TSquare.h Figures/Sources/TSquare.cpp Figures/Sources/Triangle.cpp Figures/Headers/Triangle.h TStack/TStack.h TIterator/TIterator.h TNTree/Headers/TNTree.h TNTree/Headers/TNodeN.h TNTree/Sources/TNTree.cpp TNTree/Sources/TNodeN.cpp TAllocator/TAllocationBlock.h TAllocator/TAllocationBlock.cpp Figures/Sources/Figure.cpp)

add_executable(Lab_6 ${SOURCE_FILES})