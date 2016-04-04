#include "Password.hpp"

#include <fstream>
#include <iostream>
using namespace std;

/* WeakPassword ****************************************/

WeakPassword::WeakPassword()
{
    ifstream words( "words.txt" );
    string buffer;
    while ( words >> buffer )
    {
        m_wordList.push_back( buffer );
    }
    words.close();

    cout << m_wordList.size() << " words loaded" << endl;
}

string WeakPassword::GetRandomPassword()
{
    unsigned int index = rand() % m_wordList.size();
    return m_wordList[ index ];
}

/* MediumPassword ****************************************/

MediumPassword::MediumPassword() : WeakPassword() { }

string MediumPassword::GetRandomPassword()
{
    string plaintext = WeakPassword::GetRandomPassword();
    cout << "\t Build password from: " << plaintext << endl;
    string pass = "";
    for ( int i = 0; i < plaintext.size(); i++ )
    {
        int action = rand() % 3;

        if ( action == 0 )
        {
            // Swap with a symbol
            pass += SwapChar( plaintext[i] );
        }
        else if ( action == 1 )
        {
            // Set to upper-case
            pass += toupper( plaintext[i] );
        }
        else
        {
            // Add as-is
            pass += plaintext[i];
        }
    }
    return pass;
}

string MediumPassword::SwapChar( char letter )
{
    if      ( letter == 'a' )   { return "@"; }
    else if ( letter == 'b' )   { return "8"; }
    else if ( letter == 'c' )   { return "("; }
    else if ( letter == 'd' )   { return "|)"; }
    else if ( letter == 'e' )   { return "3"; }
    else if ( letter == 'f' )   { return "PH"; }
    else if ( letter == 'g' )   { return "9"; }
    else if ( letter == 'h' )   { return "|-|"; }
    else if ( letter == 'i' )   { return "1"; }
    else if ( letter == 'j' )   { return "_|"; }
    else if ( letter == 'k' )   { return "|<"; }
    else if ( letter == 'l' )   { return "|_"; }
    else if ( letter == 'm' )   { return "/\\/\\"; }
    else if ( letter == 'n' )   { return "|\\|"; }
    else if ( letter == 'o' )   { return "0"; }
    else if ( letter == 'p' )   { return "P"; }
    else if ( letter == 'q' )   { return "c|"; }
    else if ( letter == 'r' )   { return "|2"; }
    else if ( letter == 's' )   { return "5"; }
    else if ( letter == 't' )   { return "7"; }
    else if ( letter == 'u' )   { return "|_|"; }
    else if ( letter == 'v' )   { return "\\/"; }
    else if ( letter == 'w' )   { return "\\/\\/"; }
    else if ( letter == 'x' )   { return "><"; }
    else if ( letter == 'y' )   { return "Y"; }
    else if ( letter == 'z' )   { return "7_"; }
    return "_";
}

/* HarderPassword ****************************************/

HarderPassword::HarderPassword() : MediumPassword() { }

string HarderPassword::GetRandomPassword()
    {
        string pass = "";
        int length = rand() % 3 + 2;
        for ( int i = 0; i < length; i++ )
        {
            pass += MediumPassword::GetRandomPassword();
        }
        return pass;
    }
