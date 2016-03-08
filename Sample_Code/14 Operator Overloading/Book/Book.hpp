#ifndef _BOOK
#define _BOOK

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Book;

class Chapter
{
    public:
    friend ostream& operator<<( ostream& out, Chapter& item );
    string GetTitle() { return m_title; }

    private:
    string m_title;
    vector<string> m_content;
    friend class Book;
};

class Book
{
    public:
    void Load( const string& title );
    Chapter& operator[]( const int index );
    int ChapterCount() { return m_chapters.size(); }

    private:
    string m_title;
    vector<Chapter> m_chapters;
};

#endif
