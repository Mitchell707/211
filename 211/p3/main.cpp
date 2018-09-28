#include <iostream>
#include <string>
#include "video.h"
#include "vlist.h"

using namespace std;

string command = "";

string title = "";
string url = "";
string comment = "";

float length = 0.00;

int rating = 0;

void insertVid();

List vid;

int main()
{
    while(getline(cin, command))
    {
        if(command == "insert")
        {
            insertVid();
        }
        else if(command == "print")
        {
            vid.print();
        }
        else if(command == "length")
        {
            cout << vid.length() << endl;
        }
        else if(command == "lookup")
        {
            getline(cin, title);
            vid.search(title);
        }
        else if(command == "remove")
        {
            getline(cin, title);
            if(!vid.remove(title))
            {
                cerr << "Title <" << title << "> not in list, could not delete."<< endl;
                return 1;
            }
        }
        else
        {
            cerr << "<" << command << "> is not a legal command, giving up." << endl;
            return 1;
        }

    }
    return 0;
}

void insertVid()
{
    string title = "";
    string url = "";
    string comment = "";
    float length = 0.00;
    int rating = 0;

    getline(cin, title);
    getline(cin, url);
    getline(cin, comment);

    cin >> length;
    cin >> rating;

    cin.ignore();

    if(vid.freeName(title))
    {
        vid.insert(new Video(title, url, comment, length, rating));
    }
}
