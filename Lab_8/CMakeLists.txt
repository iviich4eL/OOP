cmake_minimum_required(VERSION 3.8)
project(Lab_8)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "-pthread")

set(
        SOURCE_FILES main.cpp
        Figures/Headers/Figure.h
        Figures/Headers/Octagon.h
        Figures/Headers/Triangle.h
        Figures/Headers/TSquare.h

        Figures/Sources/Octagon.cpp
        Figures/Sources/Triangle.cpp
        Figures/Sources/TSquare.cpp
        TIterator/TIterator.h
        TStack/TStack.h
        Trees/Templates/TBinTree.h
        Trees/Templates/TNodeB.h
        Trees/Templates/TTree.h)
add_executable(Lab_8 ${SOURCE_FILES})