#include <iostream>
#include "video.h"

Video::Video(string t, string u, string c, float l, int r)
{
    title = t;
    URL = u;
    comment = c;
    length = l;
    rating = r;

}

void Video::print()
{
    cout << title << ", " << URL << ", " << comment << ", " << length << ", ";

    for( int i = 0; i < rating; i++)
    {
        cout << "*";
    }

    cout << endl;

}

