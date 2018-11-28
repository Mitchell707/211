//point.h
//Beck, Mitchell
//mbeck16

#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
#include "point.h"
#include "grid.h"
#include "shape.h"

using namespace std;

class Point : public Shape
{
  private:
    char c;

  public:
    Point(int x, int y, char p_c) : Shape(x, y)
    {
        c = p_c;

    }

    void draw(Grid &grid);

};

#endif
