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

class TextButton
{
    public:
    void Draw();
    void SetText( const string& text );
    void SetDimensions( int width, int height );

    private:
    Button m_button;
    Label m_label;
};

#endif
