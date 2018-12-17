//main.cpp
//Beck, Mitchell
//mbeck16

#include <iostream>
#include <string>
#include "bst.h"

using namespace std;

string command = "";
string temp = "";

Bst tree;

string echo(string);

int main()
{
    
    while(cin >> command)
    {
        if(command == "insert")
        {
            cin.ignore();
            getline(cin, temp);
            if(!tree.insert(temp))
            {
                cerr << "insert <" << temp << "> failed. String already in tree." << endl;
            }
        }
        else if(command == "size")
        {
            cout << tree.size() << endl;
        }
        else if(command == "find")
        {
            cin.ignore();
            getline(cin, temp);
            if(tree.find(temp) == true)
            {
                cout << "<" << temp << "> is in tree." << endl;
            }
            else
            {
                cout << "<" << temp << "> is not in tree." << endl;
            }
        }
        else if(command == "print") //handles the output for the print function
        {
            tree.print();
            cout << "{";
            for(int i = 0; i < tree.size() - 1;)
            {
                cout << tree.strings[i++] << ", ";
            }
            cout << tree.strings[tree.size() - 1] << "}" << endl;
            tree.strings.clear();
        }
        else if(command == "breadth") //handles the output for the breadth function
        {
            tree.breadth();
            cout << "{";
            for(int i = 0; i < tree.size() - 1;)
            {
                cout << tree.strings[i++] << ", ";
            }
            cout << tree.strings[tree.size() - 1] << "}" << endl;
            tree.strings.clear();
        }
        else if(command == "distance")
        {
            cout << "Average distance of nodes to root = " << tree.distance() << endl;
        }
        else if(command == "balanced")
        {
            if(tree.balanced())
            {
                cout << "Tree is balanced." << endl;
            }
            else
            {
                cout << "Tree is not balanced." << endl;
            }
        }
        else if(command == "rebalance")
        {

        }
        else if(command == "echo")
        {
            cin.ignore();
            getline(cin, temp);
            cout << temp << endl;
        }
        else
        {
            cerr << "Illegal command <" << command << ">." << endl;
        
        }

    }

}

string echo(string str) //prints entered string
{
    cout << str << endl;
}
