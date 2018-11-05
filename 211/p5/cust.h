#ifndef CUST_H_
#define CUST_H_

#include <iostream>
#include <string>

using namespace std;

class Cust
{
    public:
        Cust(string, bool, int, int);
        void printEntered(ostream&, int);
        void printShopped(ostream&, int);
        void printCheckout(ostream&, int, int /*checker number*/);
        void printPaid(ostream&, int);
        void printStole(ostream&, int, int);

        int getTime() {return time;};
        int getItems() {return items;};
        bool getPurpose() {return robber;};

    private:
        string name;
        bool robber;
        int time;
        int items;
};

#endif
