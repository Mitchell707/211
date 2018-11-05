//sim.cpp
//Beck, Mitchell
//mbeck16

#include <iostream>
#include <string>
#include <fstream>
#include <assert.h>
#include "cust.h" 
#include "pqueue.h"

using namespace std;

/*
Read in all customers into pqueue

Make the simulation transfer customers between different queues changing the priority each time, then have the simulation check each first priority and react to that appropriately

*/

Pqueue outside;

void run_simulation(Pqueue &, int, int, ostream &os);

int numCheckers = 0;
int breakTime = 0;

//----------------------

struct Checker
{
    int money = 250;
    int breakTime = 0;
    Cust *c = NULL;
    Pqueue reg;
};

//----------------------

//command line arguments
//1) number of checkers
//2) length of break
//3) input file name
//4) output file name

int main(int argc, char *argv[])
{
    //READ IN CUSTOMERS FROM A FILE
        
    ifstream ifile(argv[3]);

    ifile.open(argv[3]);

    while(ifile.peek() != EOF)
    {
        string name;
        string purpose;
        int enterTime;
        int items;

        ifile >> name;
        ifile >> purpose;
        ifile >> enterTime;
        ifile >> items;

        outside.enqueue(new Cust(name, (purpose == "robber" ? 1 : 0), enterTime, items), enterTime);    

    }
    
    ifile.close();

    numCheckers = stoi(argv[1]);
    breakTime = stoi(argv[2]);

    ofstream ofile(argv[4]);

    ofile.open(argv[4]);

    run_simulation(outside, numCheckers, breakTime, ofile);
     
    ofile.close();
    
    //Print Output File
    string line = "";

    ofile.open(argv[4]);
       
    for(int i = 0; i < 10; i++)
    {
        ofile << line << endl;
    }

    ofile.close();    

    return 0;
}

void run_simulation(Pqueue &start, int numCheckers, int breakTime, ostream &os)
{
    Pqueue shopping;
    Pqueue line;

    Checker *checkers = new Checker[numCheckers];
    
    for(int clock = 1; clock < start.getLength(); clock++)
    {
        for(int i = 0; i < start.getLength(); i++)
        {
            if(clock == start.getPriority())
            {
                Cust *tmp = start.dequeue();
                tmp->printEntered(os, clock);
                int nextTime = tmp->getTime() + (tmp->getItems() * 2);
                shopping.enqueue(tmp, nextTime);
            }
        }

        for(int i = 0; i < shopping.getLength(); i++)
        {
            if(clock == shopping.getPriority())
            {
                Cust *tmp = shopping.dequeue();
                tmp->printShopped(os, clock);
                line.enqueue(tmp, 0);
            }
        }
        
        //Finishes Checkout
        for(int i = 0; i < numCheckers; i++)
        {
            Cust *tmp = checkers[i].c;

            if(checkers[i].reg.getPriority() == clock)
            {
                if(tmp->getPurpose() == 0)
                {
                    checkers[i].money += tmp->getItems() * 3;
                    tmp->printPaid(os, clock, i);
                }
                else
                {
                    tmp->printStole(os, clock, checkers[i].money, i);
                    checkers[i].money = 0;
                }
                
                checkers[i].c = NULL;
                delete tmp;
                
            }

        }
        
        //Puts custs on available checkers
        for(int i = 0; i < numCheckers; i++)
        {
            if(checkers[i].c == NULL)
            {
                int nextTime = 0;
                checkers[i].c = line.dequeue();
                
                if(checkers[i].c->getPurpose())
                {
                    nextTime = checkers[i].c->getTime() + 7;
                }
                else
                {
                    nextTime = checkers[i].c->getTime() + checkers[i].c->getItems();
                }
                
                checkers[i].c->printCheckout(os, clock, i);
                checkers[i].reg.enqueue(checkers[i].c, nextTime);
            }

            //if checkers current cust priority = clock
            
        }

    }

}
