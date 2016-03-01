#include "Webpage.hpp"

Webpage::Webpage( const string& name )
{
    m_name = name;
}

void Webpage::Open( const string& filename )
{
    m_output.open( filename.c_str() );
    OutputPageBegin();
}

void Webpage::Close()
{
    OutputPageEnd();
    m_output.close();
}

void Webpage::AddElement( Link& widget )
{
    m_output << widget.GetOutput() << endl;
}

void Webpage::AddElement( Button& widget )
{
    m_output << widget.GetOutput() << endl;
}

void Webpage::AddElement( Paragraph& widget )
{
    m_output << widget.GetOutput() << endl;
}

void Webpage::OutputPageBegin()
{
    m_output << "<html>" << endl;
    m_output << "<head><title>" << m_name << "</title></head>" << endl;
    m_output << "<body>" << endl;
}

void Webpage::OutputPageEnd()
{
    m_output << "</body></html>" << endl;
}
