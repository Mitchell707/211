//bst.cpp
//Beck, Mitchell
//mbeck16

#include <iostream>
#include <string>
#include <vector>
#include "bst.h"

using namespace std;

Bst::Bst()
{
    m_root = new Node;

}

Bst::~Bst()
{

}

bool Bst::insert(string str, Node *cur)
{
    if(m_root->m_value.empty()) //Will initialize a Node with two Null children if the tree is empty
    {
        m_root->m_value = str;
        m_root->right = NULL;
        m_root->left = NULL;
        length++;
    }
    else if(str < cur->m_value) //handles the left insertion
    {
        if(cur->left != NULL)
        {
            insert(str, cur->left);
        }
        else
        {
            cur->left = new Node;
            cur->left->m_value = str;
            cur->left->left = NULL;
            cur->left->right = NULL;
            length++;
        }
    }
    else if(str > cur->m_value) //handles the right insertion
    {
        if(cur->right != NULL)
        {   
            insert(str, cur->right);
        }
        else
        {
            cur->right = new Node;
            cur->right->m_value = str;
            cur->right->left = NULL;
            cur->right->right = NULL;
            length++;
        }
    }
    else if(str == cur->m_value) //returns false when a string is already in the tree
    {
        return false;
    }

    return true;

}

bool Bst::find(string str, Node *cur) //traverses whole tree while comparing values
{
    if(!cur)
    {
        return false;
    }

    if(str == cur->m_value)
    {
        return true;
    }
    else if(str > cur->m_value)
    {
        return find(str, cur->right);
    }
    else if(str < cur->m_value)
    {
        return find(str, cur->left);
    }
}

void Bst::print(vector <string> &str, Node *cur, int pos)
{
    if(!cur)
    {
        return;
    }

    print(str, cur->left, pos);
    str.push_back(cur->m_value);
    print(str, cur->right, pos);
}

void Bst::printLevel(vector <string> &str, Node *cur, int pos) //used by breadth search function
{
    if(!cur)
    {
        return;
    }
    
    if(pos == 1) //traverses down tree until it gets to the correct level(pos == 1) then prints left to right.
    {
        str.push_back(cur->m_value);
    }
    else if(pos > 1)
    {
        printLevel(str, cur->left, pos - 1);
        printLevel(str, cur->right, pos - 1);
    }
}

void Bst::breadth(vector <string> &str, Node *cur, int pos)
{     
    int l = size();

    for(int i = 1; i <= l; i++)
    {
        printLevel(str, cur, i);
    }
}

double Bst::distance()
{
    distance(m_root, dist);
    return total / length;
}

void Bst::distance(Node *cur, int dist) //gets cumulative distance from root to leafs
{
    if(!cur)
    {
        return;
    }

    total += dist;
    
    distance(cur->right, dist + 1);
    distance(cur->left, dist + 1);
}

int Bst::height(Node* cur)
{
    if(!cur)
    {
        return 0;
    }

    return 1 + max(height(cur->left), height(cur->right));
}

bool Bst::balanced(Node *cur) //checks the bottom leaf size each and returns true or false if the size is within one
{
    int leftH = 0;
    int rightH = 0;
        
    if(!cur)
    {
        return true;
    }

    leftH = height(cur->left);
    rightH = height(cur->right);

    bool l = balanced(cur->left);
    bool r = balanced(cur->right);

    if(abs(leftH - rightH) <= 1 && l && r)
    {
        return 1;
    }

    return 0;

}

void Bst::rebalance()
{

}
