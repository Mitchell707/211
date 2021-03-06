//pqueue.cpp
//Beck, Mitchell
//mbeck16

#include <iostream>
#include <assert.h>
#include <string.h>
#include "pqueue.h"
#include "cust.h"

using namespace std;

Pqueue::Pqueue()
{
    m_head = NULL;
    m_length = 0;
}

Pqueue::~Pqueue()
{
    while(m_head)
    {
        Node *tmp = m_head;
        m_head = m_head->m_next;
        delete tmp->m_value;
        delete tmp;
    }
}

void Pqueue::enqueue(Cust *cust, int p)
{
    if(!m_head)
    {
        m_head = new Node(cust, p, m_head);
    }
    else
    {
        Node *cur = m_head;
        while(cur->m_next != NULL && p >= cur->m_next->m_p)
        {
            cur = cur->m_next;
        }
        assert(cur != NULL);
        cur->m_next = new Node(cust, p, cur->m_next);       
    }

    m_length++;
}

Cust *Pqueue::dequeue()
{
    if(m_head)
    {
        Node *tmp = m_head;
    
        m_head = m_head->m_next;

        m_length--;

        return tmp->m_value;
    }
    else
    {
        return NULL;
    }
}

int Pqueue::getPriority()
{
    if(m_head)
    {
        return m_head->m_p;    
    }
    else
    {
        return NULL;
    }
}
