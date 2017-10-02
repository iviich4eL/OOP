#ifndef FIGURE_H_
#define FIGURE_H_

class Figure
{
  public:
    virtual double Square() = 0;
    virtual void Print() = 0;
    virtual ~Figure(){};
};

#endif