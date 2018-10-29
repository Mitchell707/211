#include <iostream>
#include "cust.h"

Cust::Cust(string n, bool r, int t, int i)
{
    name = n;
    robber = r;
    time = t;
    items = i;
}

void Cust::print(ostream &os)
{
    string temp = "shopper";

    if(robber) temp = "robber";

    os << name << " " << temp << " " << time << " " << items << endl;
}
