#include "Button.h"

#include <iostream>
using namespace std;

void Button::Setup( const string& text, int width, int height )
{
	m_text = text;
	m_width = width;
	m_height = height;
}


// Friend function - not a part of Button class
void Draw( const Button& button )
{
	for ( int y = 0; y < button.m_height; y++ )
	{
		if ( y == 0 || y == button.m_height - 1 )
		{
			for ( int x = 0; x < button.m_width; x++ )
			{
				cout << "#";
			}
		}
		else if ( y == button.m_height/2 )
		{
			cout << "# ";
			cout << button.m_text;

			for ( int x = button.m_text.size() + 2; x < button.m_width - 1; x++ )
			{
				cout << " ";
			}
			cout << "#";
		}
		else
		{
			cout << "#";
			for ( int x = 1; x < button.m_width - 1; x++ )
			{
				cout << " ";
			}
			cout << "#";
		}

		cout << endl;
	}
}
