//square.h
//Beck, Mitchell
//mbeck16

#ifndef _SQUARE_H_
#define _SQUARE_H_

#include <iostream>
#include "square.h"
#include "grid.h"
#include "shape.h"

using namespace std;

class Square : public Shape
{
  private:
    int size;

  public:
    Square(int x, int y, int p_size) : Shape(x, y)
    {
        size = p_size;
    }
    void draw(Grid &grid);

};

#endif
