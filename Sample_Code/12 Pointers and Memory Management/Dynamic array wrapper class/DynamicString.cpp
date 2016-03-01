#include "DynamicString.hpp"

#include <iostream>
using namespace std;

DynamicString::DynamicString( int size )
{
    // Automatically allocate memory
    m_stringList = new string[ size ];
    m_maxVal = size;
}

DynamicString::~DynamicString()
{
    // Automatically free memory
    delete [] m_stringList;
}

void DynamicString::Set( int index, const string& val )
{
    if ( index < 0 )
    {
        cout << "Error: Invalid index!" << endl;
        return;
    }

    if ( index >= m_maxVal )
    {
        Resize( m_maxVal + 5 );
    }

    m_stringList[ index ] = val;
}

string DynamicString::Get( int index )
{
    if ( index < 0 || index >= m_maxVal )
    {
        cout << "Error: Invalid index!" << endl;
        return "";
    }
    else
    {
        return m_stringList[ index ];
    }
}

int DynamicString::Size()
{
    return m_maxVal;
}

void DynamicString::Resize( int newSize )
{
    cout << "Resize the array."
        << "\t Old size: " << m_maxVal
        << "\t New size: " << newSize << endl;

    string* tempArray = new string[ newSize ];

    // Copy over
    for ( int i = 0; i < m_maxVal; i++ )
    {
        tempArray[i] = m_stringList[i];
    }

    // Delete old
    delete [] m_stringList;

    // Change pointers
    m_stringList = tempArray;
    tempArray = NULL;

    // Update size
    m_maxVal = newSize;

    // We don't delete m_stringList here, because
    // that is handled in the destructor.
}
