//circle.h
//Beck, Mitchell
//mbeck16

#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include <iostream>
#include "circle.h"
#include "grid.h"
#include "shape.h"

using namespace std;

class Circle : public Shape
{
  private:
    
  public:
    Circle(int x, int y) : Shape(x, y)
    {}

    void draw(Grid &grid);

};

#endif
