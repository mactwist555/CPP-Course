#include <iostream>
#include <string>
using namespace std;

#include "DocuManager.hpp"

int main()
{
    DocuManager<TextDoc> textManager;
    DocuManager<CsvDoc>  csvManager;

    textManager.Add( "Carmack" );
    textManager.Add( "Romero" );
    textManager.Add( "Hall" );
    textManager.Add( "Schafer" );
    textManager.Add( "Gilbert" );
    textManager.Add( "Grossman" );
    textManager.Add( "Lowe" );
    textManager.Add( "Williams" );
    textManager.Add( "Cole" );
    textManager.Save();

    csvManager.Add( "Carmack" );
    csvManager.Add( "Romero" );
    csvManager.Add( "Hall" );
    csvManager.Add( "Schafer" );
    csvManager.Add( "Gilbert" );
    csvManager.Add( "Grossman" );
    csvManager.Add( "Lowe" );
    csvManager.Add( "Williams" );
    csvManager.Add( "Cole" );
    csvManager.Save();

    return 0;
}
