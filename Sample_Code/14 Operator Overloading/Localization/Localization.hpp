#ifndef _LOC
#define _LOC

#include <string>
#include <map>
using namespace std;

class Localization
{
    public:
    void SetLanguage( const string& language );
    void LoadFile( const string& filename );
    string GetName() { return m_language; }

    string& Text( const string& key );
    string& operator[]( const string& key );

    private:
    string m_language;
    map<string, string> m_translations;
};

#endif
