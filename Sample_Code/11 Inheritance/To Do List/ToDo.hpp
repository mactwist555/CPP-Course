#ifndef _TODO
#define _TODO

#include <iostream>
#include <string>
using namespace std;

class ToDo
{
    public:
    ToDo();
    void AddItem( const string& item );
    void DisplayList();
    void GetList( string exportList[], int size );
    int GetSize();

    private:
    string m_list[10];
    int m_top;
    int m_max;
};

ToDo::ToDo()
{
    m_top = 0;
    m_max = 10;
}

int ToDo::GetSize()
{
    return m_top;
}

void ToDo::GetList( string exportList[], int size )
{
    for ( int i = 0; i < size; i++ )
    {
        exportList[ i ] = m_list[ i ];
    }
}

void ToDo::AddItem( const string& item )
{
    m_list[ m_top ] = item;
    if ( m_top + 1 < m_max )
    {
        m_top++;
    }
}

void ToDo::DisplayList()
{
    for ( int i = 0; i < m_top; i++ )
    {
        cout << (i+1) << ". " << m_list[i] << endl;
    }
}

#endif
