#include "Widgets.hpp"

void Button::Draw()
{
    for ( int y = 0; y < m_height; y++ )
    {
        for ( int x = 0; x < m_width; x++ )
        {
            if ( x == 0 || x == m_width-1 || y == 0 || y == m_height-1 )
            {
                cout << "#";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void Button::SetDimensions( int width, int height )
{
    m_width = width;
    m_height = height;
}

void Label::Draw()
{
    cout << m_text << endl;
}

void Label::SetText( const string& text )
{
    m_text = text;
}

void TextButton::SetText( const string& text )
{
    m_label.SetText( text );
}

void TextButton::SetDimensions( int width, int height )
{
    m_button.SetDimensions( width, height );
}

void TextButton::Draw()
{
    for ( int y = 0; y < m_height; y++ )
    {
        for ( int x = 0; x < m_width; x++ )
        {
            if ( x == 0 || x == m_width-1 || y == 0 || y == m_height-1 )
            {
                cout << "#";
            }
            else if ( y == m_height/2 && x == 1 )
            {
                cout << m_text;
            }
            else if ( y != m_height/2 )
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

