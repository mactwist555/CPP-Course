#ifndef _WEBPAGE
#define _WEBPAGE

#include <string>
#include <fstream>
using namespace std;

#include "Widget.hpp"

class Webpage
{
    public:
    Webpage( const string& name );
    void Open( const string& filename );
    void Close();
    void AddElement( Link& widget );
    void AddElement( Button& widget );
    void AddElement( Paragraph& widget );

    private:
    void OutputPageBegin();
    void OutputPageEnd();
    string m_name;
    ofstream m_output;
};

#endif
