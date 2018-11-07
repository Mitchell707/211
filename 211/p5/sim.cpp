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

string inFile;
string outFile;

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
    
    string line;
    
    string name;
    string purpose;
    int enterTime;
    int items;

    inFile = argv[3];
    outFile = argv[4];

    ifstream ifile;
    
    ifile.open(inFile);
    
    while(ifile >> name)
    {
        ifile >> purpose;
        ifile >> enterTime;
        ifile >> items;
        
        outside.enqueue(new Cust(name, (purpose == "robber" ? 1 : 0), enterTime, items), enterTime);    

    }
    
    ifile.close();

    numCheckers = stoi(argv[1]);
    breakTime = stoi(argv[2]);

    ofstream ofile(outFile);

    ofile.open(outFile);

    run_simulation(outside, numCheckers, breakTime, ofile);
     
    ofile.close();
    
    return 0;
}

void run_simulation(Pqueue &start, int numCheckers, int breakTime, ostream & os)
{
    Pqueue shopping;
    Pqueue line;

    Checker *checkers = new Checker[numCheckers];
    
    int num_cust = start.getLength();
    
    for(int clock = 1; num_cust > 0 ; clock++)
    {    
        while(!start.isEmpty() && clock == start.getPriority())
        {
            Cust *tmp = start.dequeue();
                
            tmp->printEntered(os, clock);
                
            int nextTime = clock + (tmp->getItems() * 2);
             
            shopping.enqueue(tmp, nextTime);
            
        }

        for(int i = 0; i < num_cust; i++)
        {
            if(clock == shopping.getPriority())
            {
                Cust *tmp = shopping.dequeue();
                tmp->printShopped(os, clock);
                line.enqueue(tmp, 0);
            }
        }
        
        //Finishes Checkout
        for(int i = 1; i < numCheckers; i++)
        {
        
            if(checkers[i].c == NULL)
            {
                Cust *tmp = checkers[i].c;
            

                if(checkers[i].reg.getPriority() == clock)
                {
                    if(tmp->getPurpose()) //SEG FAULT AT THIS LINE
                    {
                        cout << "Purpose" << endl;
                        checkers[i].money += tmp->getItems() * 3;
                        tmp->printPaid(os, clock, i);
                    }
                    else
                    {
                        tmp->printStole(os, clock, checkers[i].money, i);
                        checkers[i].money = 0;
                    }
                
                    checkers[i].c = NULL;
                    num_cust--;
                    delete tmp;
               
                }   

            }

        }
                
        //Puts customer on to available checker
        for(int i = 0; i < numCheckers; i++)
        {
            if(checkers[i].c == NULL && line.isEmpty() == false)
            {
                Cust *tmp = line.dequeue();
                           
                int nextTime = 0;
                
                if(tmp->getPurpose())
                {
                    
                    nextTime = tmp->getTime() + 7;
                }
                else
                {
                    nextTime = tmp->getTime() + tmp->getItems();
                }
                
                tmp->printCheckout(os, clock, i);
                checkers[i].reg.enqueue(checkers[i].c, nextTime);
            }

        }

    }

}
