#include <iostream>
#include <string>
using namespace std;

#include "Widgets.hpp"

int main()
{
    Label label;
    label.SetText( "This is a label" );

    Button button;
    button.SetDimensions( 10, 5 );

    TextButton textButton;
    textButton.SetText( "Click Me" );
    textButton.SetDimensions( 10, 5 );

    cout << endl << endl << "LABEL" << endl;
    label.Draw();

    cout << endl << endl << "BUTTON" << endl;
    button.Draw();

    cout << endl << endl << "TEXT BUTTON" << endl;
    textButton.Draw();

    return 0;
}


