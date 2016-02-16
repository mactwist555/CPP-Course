#ifndef _DICTIONARY
#define _DICTIONARY

#include <string>
#include <iostream>
using namespace std;

class Entry
{
    public:
    string language;
    string word;

    Entry()
    {
        m_translations = NULL; //= new Entry[ 10 ];
        m_size = 10;
        m_top = 0;
    }

    ~Entry()
    {
        if ( m_translations != NULL )
        {
            delete [] m_translations;
            m_translations = NULL;
        }
    }

    void AddTranslation( const string& word, const string& language )
    {
        if ( m_translations == NULL )
        {
            m_translations = new Entry[ 10 ];
        }

        if ( m_top == m_size )
        {
            cout << "Resize" << endl;
            return;
        }

        m_translations[ m_top ].word = word;
        m_translations[ m_top ].language = language;

        m_top++;
    }

    void Display()
    {
        cout << language << ": " << word << endl;

        for ( int i = 0; i < m_top; i++ )
        {
            cout << "\t" << m_translations[ i ].language << ": "
                << m_translations[i].word << endl;
        }
        cout << endl;
    }

    private:
    Entry* m_translations;
    int m_top;
    int m_size;
};

class Dictionary
{
    public:
    Dictionary();
    ~Dictionary();

    void AddEntry( const string& from );
    void Display();

    private:
    Entry* m_entryList;
    int m_size;
    int m_top;
};

Dictionary::Dictionary()
{
    m_entryList = new Entry[ 10 ];
    m_size = 10;
    m_top = 0;
}

Dictionary::~Dictionary()
{
    delete [] m_entryList;
}

void Dictionary::AddEntry( const string& from )
{
    if ( m_top == m_size )
    {
        cout << "Resize" << endl;
        return;
    }

    m_entryList[ m_top ].language = from;

    cout << endl << "Word in " << from << ": ";
    cin >> m_entryList[ m_top ].word;

    string lang, word;
    while ( true )
    {
        cout << "\nType QUIT to stop" << endl;

        cout << "Translated word: ";
        cin >> word;

        if ( word == "QUIT" ) { break; }

        cout << "Target language: ";
        cin >> lang;

        m_entryList[ m_top ].AddTranslation( word, lang );
    }

    m_top++;
}

void Dictionary::Display()
{
    cout << endl;
    for ( int i = 0; i < m_top; i++ )
    {
        m_entryList[ i ].Display();
    }
    cout << endl;
}

#endif
