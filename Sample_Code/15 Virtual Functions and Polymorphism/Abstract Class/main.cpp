#include <iostream>
#include <string>
using namespace std;

#include "Document.hpp"

int main()
{
    CsvDocument csv;
    csv.AddRow( "GAME,YEAR" );
    csv.AddRow( "The Secret of Monkey Island,1990" );
    csv.AddRow( "Kings Quest VI,1992" );
    csv.AddRow( "The Longest Journey,1999" );
    csv.Save( "Games.csv" );

    TextDocument text;
    text.SetContent( "Hello!\nHow are you?\nI am fine!" );
    text.Save( "Greeting.txt" );

    WebDocument html;
    html.AddElement( "<h1>This is a header!</h1>" );
    html.AddElement( "<p>Welcome to this page</p>" );
    html.AddElement( "<input type='button' value='Click me'/>" );
    html.Save( "Sample.html" );

    return 0;
}


