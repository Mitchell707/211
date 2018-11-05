#include <iostream>
#include <assert.h>
#include "cust.h"

Cust::Cust(string n, bool r, int t, int i)
{
    name = n;
    robber = r;
    time = t;
    items = i;
}

void Cust::printEntered(ostream &os, int clock)
{
    assert(clock == time);
    os << clock << ": " << name << " entered store" << endl;
           
}

void Cust::printShopped(ostream &os, int clock)
{
    os << clock << ": " << name << " done shopping" << endl;

}

void Cust::printCheckout(ostream &os, int clock, int checker)
{
    

}

void Cust::printPaid(ostream &os, int clock)
{

}

void Cust::printStole(ostream &os, int clock, int amt)
{

}
