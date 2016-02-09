// SOCIAL WALL
#ifndef _POST
#define _POST

#include <iostream>
#include <string>
using namespace std;

class Post
{
    public:
    Post( int id );
    void Display();
    void WritePost( const string& username );

    string GetPost();
    string GetAuthor();
    int GetId();

    private:
    string m_post;
    string m_author;
    int m_id;
};

#endif
