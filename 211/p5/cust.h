#ifndef CUST_H_
#define CUST_H_

#include <iostream>
#include <string>

using namespace std;

class Cust
{
    public:
        Cust(string, bool, int, int);
        void print(ostream&);

    private:
        string name;
        bool robber;
        int time;
        int items;
};

#endif
