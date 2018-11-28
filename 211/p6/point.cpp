//point.cpp
//Beck, Mitchell
//mbeck16

#include <iostream>
#include <string>
#include "point.h"
#include "shape.h"
#include "grid.h"

using namespace std;

void Point::draw(Grid &grid)
{
    if(x <= 24 || y <= 60)//Makes sure the point is within the grid
    {
        grid.set(x, y, c);
    }
}
