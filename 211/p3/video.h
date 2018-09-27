#ifndef VIDEO_H
#define VIDEO_H

#include <string>

using namespace std;

class Video
{
    public:
        Video(string, string, string, float, int);
        void print();
        string getTitle() {return title;};

    private:
        string title;
        string url;
        string comment;
        float length;
        int rating;
};

#endif
