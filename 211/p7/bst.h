//bst.h
//Beck, Mitchell
//mbeck16

#ifndef BST_H_
#define BST_H_

#include <iostream>
#include <string>
#include <vector>
#include "bst.h"

using namespace std;

class Bst
{
    public:
        Bst();
        ~Bst();

        bool insert(string str) {return insert(str, m_root);}
        int size() {return length;};
        bool find(string str) {return find(str, m_root);}
        void print() {return print(strings, m_root, pos);}
        void breadth() {return breadth(strings, m_root, pos);}
        double distance();
        bool balanced() {return balanced(m_root, length);};
        void rebalance();

        vector <string> strings;

    private:
        struct Node
        {
            public:
                string m_value;
                Node *right = NULL;
                Node *left = NULL;
        };

        Node *m_root;

        bool insert(string str, Node *cur);
        bool find(string str, Node *cur);
        void print(vector <string> &, Node *cur, int);
        void breadth(vector <string> &, Node *cur, int);
        void printLevel(vector <string> &, Node *cur, int);
        void distance(Node *cur, int);
        bool balanced(Node *cur, int);

        int mid;
        int pos;
        int length;
        double dist;
        double total;

};

#endif
