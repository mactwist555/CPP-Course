#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

int main()
{
    map<string, int> variables;

    ifstream infile( "code.txt" );

    string command;
    while ( infile >> command )
    {
        if ( command == "store" )
        {
            string varName;
            int varValue;

            infile >> varName;
            infile >> varValue;

            variables.insert( pair<string, int>( varName, varValue ) );

            cout << "Store Variable\t" << varName << " = " << varValue << endl;
        }
        else if ( command == "add" )
        {
            string firstVar, secondVar, sumVar;
            infile >> firstVar;
            infile >> secondVar;
            infile >> sumVar;

            int sum = variables[firstVar] + variables[secondVar];
            variables.insert( pair<string, int>( sumVar, sum ) );

            cout << "Add Variables\t" << sumVar << " = " << firstVar << " + " << secondVar << " (" << sumVar << " = " << sum << ")" << endl;
        }
        else if ( command == "addi" )
        {
            string varName, sumVar;
            int immediate;

            infile >> varName;
            infile >> immediate;
            infile >> sumVar;

            int sum = variables[varName] + immediate;
            variables.insert( pair<string, int>( sumVar, sum ) );

            cout << "Add Immediate\t" << sumVar << " = " << varName << " + " << immediate << " (" << sumVar << " = " << sum << ")" << endl;
        }
    }

    infile.close();

    cout << endl << endl;
    cout << "Result:" << endl;
    for (
         map<string, int>::iterator it = variables.begin();
         it != variables.end();
         it++
         )
     {
         cout << it->first << " = " << it->second << endl;
     }

    return 0;
}


