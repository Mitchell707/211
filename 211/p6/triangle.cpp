//triangle.cpp
//Beck, Mitchell
//mbeck16

#include <iostream>
#include <string>
#include "triangle.h"
#include "grid.h"
#include "shape.h"

using namespace std;

void Triangle::draw(Grid &grid)
{
    //draws top point of the triangle
    grid.set(x + 2, y, '+');

    //draws the middle
    grid.set(x + 1, y + 1, '+');
    grid.set(x + 3, y + 1, '+');

    //uses a loop to draw the bottom five '+'"
    for(int i = x; i < x + 5; i++)
    {
        grid.set(i, y + 2, '+');
    }

}
