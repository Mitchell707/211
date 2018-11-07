//pqueue.h
//Beck, Mitchell
//mbeck16

#ifndef PQUEUE_H_
#define PQUEUE_H_

#include <iostream>
#include <string.h>
#include "cust.h"

using namespace std;

class Pqueue
{
    public:
        Pqueue();
        ~Pqueue(); 
        bool isEmpty() {return (m_head == NULL);};
        int getLength() {return m_length;};
        int getPriority();
        void enqueue(Cust*, int);
        Cust *dequeue();

    private:
        class Node
        {
            public:
                Node(Cust *cust, int p, Node *next)
                {m_value = cust; m_p = p; m_next = next;}
                Cust *m_value;
                Node *m_next;
                int m_p = 0;

        };

        Node *m_head;
        int m_length;

};

#endif
