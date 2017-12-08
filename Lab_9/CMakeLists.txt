cmake_minimum_required(VERSION 3.9)
project(Lab_9)

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
        Trees/Templates/TTree.h
        Trees/Templates/TNTree.h
        Trees/Templates/TNodeN.h)

add_executable(Lab_9 main.cpp ${SOURCE_FILES})