#ifndef _DYNAMICSTRING
#define _DYNAMICSTRING

#include <string>
using namespace std;

class DynamicString
{
    public:
    DynamicString( int size );
    ~DynamicString();

    void Set( int index, const string& val );
    string Get( int index );

    int Size();

    private:
    void Resize( int newSize );

    string* m_stringList;
    int m_maxVal;
};

#endif

