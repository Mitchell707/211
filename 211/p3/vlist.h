//vlist.h
//Beck, Mitchell
//mbeck16

#ifndef VLIST_H
#define VLIST_H

#include <iostream>
#include <string>
#include "video.h"

using namespace std;

class List
{
    public:
        List();
        ~List();
        void insert(Video *video);
        void print();
        int length() {return m_length;}
        bool search(string name);
        bool remove(string name);
        bool freeName(string title);
        

    private:
        class Node
        {
            public:
                Node(Video *video, Node *next)
                {m_value = video; m_next = next;}
                Video *m_value;
                Node *m_next;
        };
        Node *m_head;
        int m_length;

};

#endif
