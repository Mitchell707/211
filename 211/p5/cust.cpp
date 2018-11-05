//cust.cpp
//Beck, Mitchell
//mbeck16

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
    assert(clock == time);
    os << clock << ": " << name << " done shopping" << endl;

}

void Cust::printCheckout(ostream &os, int clock, int checker)
{
    assert(clock == time);
    os << clock << ": " << name << " started checkout with checker " << checker << endl;

}

void Cust::printPaid(ostream &os, int clock, int checker)
{
    assert(clock == time);
    os << clock << ": " << name << " paid $" << (items * 3) << " for " << items << " items to checker " << checker << endl;

}

void Cust::printStole(ostream &os, int clock, int amt, int checker)
{
    assert(clock == time);
    os << clock << ": " << name << " stole $" << amt << " and " << items << " items from checker " << checker << endl;

}
