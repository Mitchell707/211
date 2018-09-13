#ifndef VIDEO_H
#define VIDEO_H

#include <string>

using namespace std;

class Video
{
    public:
        Video(string, string, string, float, int);
            
        void print();
   
        bool longer(Video* other) {return length > other->length;};
        bool rate(Video* other) {return rating < other->rating;};
        bool alpha(Video* other) {return title > other->title;};

    private:
        string title;
        string URL;
        string comment;
        float length;
        int rating;
        
};

#endif
