#ifndef _SOCIAL
#define _SOCIAL

#include <iostream>
#include <string>
using namespace std;

class Post
{
    public:
    string content;
    string mood;
    string date;
    string author;

    friend ostream& operator<<( ostream& out, Post& item );
};

class Friend
{
    public:
    string name;
    Post posts[3];
    Post& operator[]( const int index );
};

#endif
