#include "Post.hpp"

ostream& operator<<( ostream& out, Post& item )
{
    out << "----------------------------------------------" << endl;
    out << item.content << endl
        << item.author << ", " << item.date << "\n" << item.mood << endl;
    out << "----------------------------------------------" << endl << endl;
    return out;
}


