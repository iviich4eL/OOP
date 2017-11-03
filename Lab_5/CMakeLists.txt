cmake_minimum_required(VERSION 3.8)
project(Lab_2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Headers/Figure.h Headers/Octagon.h Headers/TBinaryTree.h Headers/TNode.h Sources/Octagon.cpp Sources/TNode.cpp Sources/TBinaryTree.cpp Headers/TSquare.h Sources/TSquare.cpp  Sources/Triangle.cpp Headers/Triangle.h Headers/TStack.h Sources/TStack.cpp Headers/TIterator.h)

add_executable(Lab_2 ${SOURCE_FILES})