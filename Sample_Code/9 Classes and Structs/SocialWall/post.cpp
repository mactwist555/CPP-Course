// SOCIAL WALL
#include "post.hpp"

Post::Post( int id )
{
    m_id = id;
}

void Post::Display()
{
    cout << endl << "(" << m_id << ") ---------------------" << endl;
    cout << "\t" << m_post << endl
        << "\tBy " << m_author << endl;
}

void Post::WritePost( const string& username )
{
    cin.ignore();
    cout << "Post text: ";
    getline( cin, m_post );
    m_author = username;
}

string Post::GetPost()
{
    return m_post;
}

string Post::GetAuthor()
{
    return m_author;
}

int Post::GetId()
{
    return m_id;
}

