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
        bool empty() {return (m_head == NULL);};
        int length() {return m_length;};
        string first_priority();
        void enqueue(Cust*, int);
        void dequeue();

    private:
        class Node
        {
            public:
                Node(Cust *cust, int p, Node *next)
                {m_value = cust; m_p = p; m_next = next;}
                Cust *m_value;
                Node *m_next;
                int m_p;

        };
        Node *m_head;
        int m_length;

};

#endif
