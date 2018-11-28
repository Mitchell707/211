//shape.h
//Beck, Mitchell
//mbeck16

#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <iostream>
#include "grid.h"

using namespace std;

class Shape
{
  protected:
    int x;
    int y;
    
  public:
    virtual void draw(Grid &grid) = 0;

    Shape(int, int);

};

#endif
