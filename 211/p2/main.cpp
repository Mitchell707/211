#include <iostream>
#include <string>
#include "video.h"

using namespace std;

string title = "";
string URL = "";
string comment = "";
string sorting = "";

float length = 0.00;

int rating = 0;

int count = 0;

Video* vid[100];

void lengthSort();
void ratingSort();
void titleSort();

void swap(Video*, Video*);

int main()
{
    
    cin >> sorting;

    if(!(sorting == "rating" || sorting == "length" || sorting == "title"))
    {
        cerr << sorting << " is not a legal sorting method, giving up." << endl;
        return 1;
    }
        
    cin.ignore();

    while(cin.peek() != EOF)
    {
        getline(cin, title);
    
        getline(cin, URL);

        getline(cin, comment);

        cin >> length;
        cin >> rating;

        cin.ignore();

        vid[count] = new Video(title, URL, comment, length, rating);
        count++;
    }

    if(sorting == "length")
    {   
        lengthSort();
        cout << "sorted Length" << endl;
    }

    for(int i = 0; i < count; i++)
    {
        vid[i]->print();
    }

    return 0;
}

void swap(Video* x, Video* y)
{
    Video* temp = x;

    x = y;

    y = temp;
}

void lengthSort()
{
    for(int last = count - 1; last > 0; last--)
    {
        for(int cur = 0; cur < last; cur++)
        {
            if(vid[cur]->longer(vid[cur+1]))
            {           
                //swap(vid[cur], vid[cur+1]);

                Video* temp = vid[cur];

                vid[cur] = vid[cur+1];

                vid[cur+1] = temp;

                cout << "swap" << endl;
            }   
        }
    }
}
