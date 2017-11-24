cmake_minimum_required(VERSION 3.8)
project(Lab_7)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Figures/Headers/Figure.h Figures/Headers/Octagon.h Trees/Templates/TBinTree.h Figures/Sources/Octagon.cpp Figures/Headers/TSquare.h Figures/Sources/TSquare.cpp Figures/Sources/Triangle.cpp Figures/Headers/Triangle.h TStack/TStack.h TIterator/TIterator.h Trees/Templates/TNTree.h TAllocator/TAllocationBlock.h TAllocator/TAllocationBlock.cpp Figures/Sources/Figure.cpp Trees/Templates/TTree.h Trees/Templates/TNodeB.h Trees/Templates/TNodeN.h Trees/Templates/TNTreeInTBinTree.h)

add_executable(Lab_7 ${SOURCE_FILES})