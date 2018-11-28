//circle.cpp
//Beck, Mitchell
//mbeck16

#include <iostream>
#include <string>
#include "circle.h"
#include "grid.h"
#include "shape.h"

using namespace std;

void Circle::draw(Grid &grid)
{
    for(int i = x + 1; i < x + 3; i++)//draws a line from x + 1 and x + 3 to make half a cirle
    {
        grid.set(i, y, 'o');
        grid.set(i, y + 3, 'o');
        
    }

    for(int i = y + 1; i < y + 3; i++)//draws a line from y + 1 and y + 3 to make a circle
    {
        grid.set(x, i, 'o');
        grid.set(x + 3, i, 'o');

    }

}
