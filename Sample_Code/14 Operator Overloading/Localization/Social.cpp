#include "Social.hpp"

ostream& operator<<( ostream& out, Post& item )
{
    out << "----------------------------------------------" << endl;
    out << item.content << endl
        << item.author << ", " << item.date << "\n" << item.mood << endl;
    out << "----------------------------------------------" << endl << endl;
    return out;
}

Post& Friend::operator[]( const int index )
{
    return posts[index];
}
