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
    if(m_root->m_value.empty())
    {
        m_root->m_value = str;
        m_root->right = NULL;
        m_root->left = NULL;
        length++;
    }
    else if(str < cur->m_value)
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
    else if(str > cur->m_value)
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
    else if(str == cur->m_value)
    {
        return false;
    }

    return true;

}

bool Bst::find(string str, Node *cur)
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

void Bst::breadth(vector <string> &str, Node *cur, int pos)
{     
    if(!cur)
    {
        return;
    }

    str.push_back(cur->m_value);
    breadth(str, cur->left, pos);
    breadth(str, cur->right, pos);
}

double Bst::distance()
{
    distance(m_root, dist);
    return total / length;
}

void Bst::distance(Node *cur, int dist)
{
    if(!cur)
    {
        return;
    }

    total += dist;
    
    distance(cur->right, dist + 1);
    distance(cur->left, dist + 1);
}

bool Bst::balanced(Node *cur, int length)
{
    int leftH = 0;
    int rightH = 0;
        
    if(!cur)
    {
        length = 0;
        return true;
    }

    bool l = balanced(cur->left, leftH);
    bool r = balanced(cur->right, rightH);

    length = max(leftH, rightH) + 1;

    if(abs(leftH - rightH) > 1)
    {
        return false;
    }

    return (l && r);

}

void Bst::rebalance()
{

}
