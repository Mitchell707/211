#include <iostream>
#include <string>
#include "video.h"
#include "vlist.h"

using namespace std;

List::List()
{
    m_head = NULL;
    m_length = 0;
}

List::~List()
{
    while (m_head)
    {
        Node *tmp = m_head;
        m_head = m_head->m_next;
        delete tmp->m_value;
        delete tmp;
    }
}

bool List::remove(string name)
{
    if(m_head == NULL)
    {
        return false;
    }
    else
    {
        Node *cur = m_head;

        while(cur->m_next)
        {
            if(cur->m_next->m_value->getTitle() == name)
            {
                Node *tmp = cur->m_next;
                cur->m_next = cur->m_next->m_next;
                delete cur->m_value;
                delete cur;
                m_length--;
                return true;
            }
            cur = cur->m_next;
        }
        return false;
    }
}

bool List::freeName(string name)
{
    Node *cur = m_head;

    while(cur)
    {
        if(cur->m_value->getTitle() == name)
        {
            return false;
        }
        else
        {
            cur = cur->m_next;
        }
    }

    return true;
}

void List::insert(Video* video)
{
    if(!(freeName(video->getTitle())))
    {
        return;
    }
    else if(m_head == NULL || video->getTitle() < m_head->m_value->getTitle())
    {
        m_head = new Node(video, m_head);
        m_length++;
    }
    else
    {
        Node *cur = m_head;
        while(cur->m_next && video->getTitle() > cur->m_next->m_value->getTitle())
        {
            cur = cur->m_next;
        }
        cur->m_next = new Node(video, cur->m_next);
        m_length++;

    }

}

void List::print()
{
    Node *cur = m_head;

    while(cur)
    {
        cur->m_value->print();
        cur = cur->m_next;
    }
}

void List::search(string name)
{
    Node *cur = m_head;

    while(cur)
    {
        if(cur->m_value->getTitle() == name)
        {
            cur->m_value->print();
            return;
        }
        cur = cur->m_next;
    }
    cerr << "Title <" << name << "> not in list." << endl;
}
