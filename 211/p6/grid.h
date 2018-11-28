//grid.h
//Beck, Mitchell
//mbeck16

#ifndef _GRID_H_
#define _GRID_H_

#include <iostream>
#include <string>
#include "grid.h"

using namespace std;

class Grid
{
  private:
    char arr[60][24];

  public:
    Grid()
    {  
        for(int x = 0; x < 24; x++)
        {
            for(int y = 0; y < 60; y++)
            {
                arr[y][x] = ' ';
            
            }
        }
    }

    void set(int, int, char);
    void print();

};

#endif
