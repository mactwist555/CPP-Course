#ifndef _WIDGETS
#define _WIDGETS

#include <iostream>
#include <string>
using namespace std;

class Button
{
    public:
    void Draw();
    void SetDimensions( int width, int height );

    protected:
    int m_width, m_height;
};

class Label
{
    public:
    void Draw();
    void SetText( const string& text );

    protected:
    string m_text;
};

class TextButton : public Button, public Label
{
    public:
    void Draw();

    // inherits m_text, m_width, m_height
    // and the SetText and SetDimensions functions
    // Overwrites Draw function
};

#endif
