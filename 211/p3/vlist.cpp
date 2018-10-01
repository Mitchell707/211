//vlist.cpp
//Beck, Mitchell
//mbeck16

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
        m_head = m_head->m_next; //Sets the next link to the head
        delete tmp->m_value;
        delete tmp;
    }
}

bool List::remove(string name) //deletes named video
{

    Node *cur = m_head;

    if(m_head == NULL)
    {
        return false;
    }
    
    if(cur->m_value->getTitle() == name) //Checks the heads value
    {
        Node *tmp = m_head;
        m_head = m_head->m_next; //Sets the next link to the head
        delete tmp->m_value;
        delete tmp;
        return true;
    }

    while(cur->m_next != NULL)
    {
        if(cur->m_next->m_value->getTitle() == name) //Checks the next links value for deletion
        {
            Node *tmp = cur->m_next;
            cur->m_next = cur->m_next->m_next; //sets the current pointers m_next to the link two places in front of it
            delete tmp;
            return true;
        }
        else
        {
            cur = cur->m_next;
        }
    }
}

bool List::freeName(string name) //Returns whether the entered name exists in the list.
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

void List::insert(Video* video) //Puts a video into the list in alphabetic order
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

bool List::search(string name)
{
    Node *cur = m_head;

    while(cur)
    {
        if(cur->m_value->getTitle() == name)
        {
            cur->m_value->print();
            return true;
        }
        cur = cur->m_next;
    }
    return false;
}
