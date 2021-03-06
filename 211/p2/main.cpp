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

const int MAX = 100;

Video* vid[100];

void lengthSort();
void ratingSort();
void titleSort();

void swap(Video*, Video*);

int main()
{
    
    cin >> sorting;

    if(!(sorting == "rating" || sorting == "length" || sorting == "title")) //Illegal sorting method check
    {
        cerr << sorting << " is not a legal sorting method, giving up." << endl;
        return 1;
    }
        
    cin.ignore();

    while(cin.peek() != EOF) //Continues till end of input
    {
        getline(cin, title);
    
        getline(cin, URL);

        getline(cin, comment);
        //getlines allow for spaces in entrys
        cin >> length;
        cin >> rating;

        cin.ignore();

        vid[count] = new Video(title, URL, comment, length, rating);
        count++;

        if(count > MAX) //Limits input to 100 videos
        {
            cerr << "Too many videos, giving up." << endl;
            return 1;
        }
    }

    if(sorting == "length") //sorts using given method
    {   
        lengthSort();
        
    }
    else if(sorting == "rating")
    {
        ratingSort();

    }
    else if(sorting == "title")
    {
        titleSort();
    }

    for(int i = 0; i < count; i++)
    {
        vid[i]->print();
    }

    return 0;
}

void swap(Video* x, Video* y)
{
    Video temp = *x;

    *x = *y;

    *y = temp;

    return;
}

void lengthSort() //Uses bubble sort algorithm for sorting
{
    for(int last = count - 1; last > 0; last--)
    {
        for(int cur = 0; cur < last; cur++)
        {
            if(vid[cur]->longer(vid[cur+1]))
            {           
                swap(vid[cur], vid[cur+1]);
             
            }   
        }
    }
}

void ratingSort()
{
    for(int last = count - 1; last > 0; last--)
    {
        for( int cur = 0; cur < last; cur++)
        {
            if(vid[cur]->rate(vid[cur+1]))
            {
                swap(vid[cur], vid[cur+1]);
            }
        }
    }
}

void titleSort()
{
    for(int last = count - 1; last > 0; last--)
    {
        for(int cur = 0; cur < last; cur++)
        {
            if(vid[cur]->alpha(vid[cur+1]))
            {
                swap(vid[cur], vid[cur+1]);
            }
        }
    }
}
