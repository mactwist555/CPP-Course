#ifndef _WIDGET
#define _WIDGET

#include <string>
using namespace std;

class Widget
{
    public:
    string GetOutput() { return ""; }
    void SetID( const string& id ) { m_id = id; }

    protected:
    string m_id;
};

class Paragraph : public Widget
{
    public:
    string GetOutput()
    {
        return "<p id='" + m_id + "'>" + m_text + "</p>";
    }

    void SetText( const string& text )
    {
        m_text = text;
    }

    private:
    string m_text;
};

class Button : public Widget
{
    public:
    string GetOutput()
    {
        return "<input type='button' value='" + m_value + "' id='" + m_id + "'/>";
    }

    void SetValue( const string& value )
    {
        m_value = value;
    }

    private:
    string m_value;
};

class Link : public Widget
{
    public:
    string GetOutput()
    {
        return "<a href='" + m_link + "' id='" + m_id + "'>" + m_text + "</a>";
    }

    void SetText( const string& text )
    {
        m_text = text;
    }

    void SetLink( const string& link )
    {
        m_link = link;
    }

    private:
    string m_text;
    string m_link;
};

#endif
