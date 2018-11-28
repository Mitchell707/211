//square.cpp
//Beck, Mitchell
//mbeck16

#include <iostream>
#include <string>
#include "square.h"
#include "grid.h"
#include "shape.h"

using namespace std;

void Square::draw(Grid &grid)
{
    size = size - 1;

    //grid.arr[x][y] = "*";
    grid.set(x + size, y + size, '*');

    for(int i = x; i < x + size; i++)//draws two lines along the x axis size length
    {
        grid.set(i, y, '*');
        grid.set(i, y + size, '*');
    }

    for(int i = y; i < y + size; i++)//draws two lines along the y axis size length
    {
        grid.set(x, i, '*');
        grid.set(x + size, i, '*');
    }
    
}
