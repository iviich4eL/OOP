#ifndef FIGURE_H
#define FIGURE_H

#include "../../TAllocator/TAllocationBlock.h"

class Figure {
public:
    virtual double Square() = 0;
    virtual void Print() = 0;
    virtual ~Figure() {};

    static TAllocationBlock figure_allocator;
};

#endif /* FIGURE_H */