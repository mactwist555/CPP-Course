#include "Webpage.hpp"

int main()
{
    Webpage myPage( "My Webpage" );
    myPage.Open( "Web.html" );

    Link link;
    link.SetID( "toIndex" );
    link.SetLink( "index.html" );
    link.SetText( "Go Home" );
    myPage.AddElement( link );

    Button btn;
    btn.SetID( "btnReset" );
    btn.SetValue( "Reset" );
    myPage.AddElement( btn );

    Paragraph text;
    text.SetID( "welcome" );
    text.SetText( "Welcome to this page!" );
    myPage.AddElement( text );

    myPage.Close();
}
