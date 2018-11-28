//triangle.h
//Beck, Mitchell
//mbeck16

#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include <iostream>
#include "triangle.h"
#include "grid.h"
#include "shape.h"

using namespace std;

class Triangle : public Shape
{
  private:
  
  public:
    Triangle(int x, int y) : Shape(x, y){};
    
    void draw(Grid &grid);

};

#endif
