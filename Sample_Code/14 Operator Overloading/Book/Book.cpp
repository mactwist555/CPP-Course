#include "Book.hpp"

void Book::Load( const string& title )
{
    m_title = title;

    for ( int i = 1; i <= 4; i++ )
    {
        Chapter chap;

        char numAsAscii = char( 48+i );
        string file = "chapter";
        file += numAsAscii;
        chap.m_title = file;

        file += ".txt";
        ifstream input( file.c_str() );

        string buffer;
        while ( input >> buffer )
        {
            chap.m_content.push_back( buffer );
        }

        m_chapters.push_back( chap );

        input.close();
    }
}

Chapter& Book::operator[]( const int index )
{
    return m_chapters[index];
}

ostream& operator<<( ostream& out, Chapter& item )
{
    for ( int i = 0; i < item.m_content.size(); i++ )
    {
        out << item.m_content[i] << " ";
    }
    return out;
}
