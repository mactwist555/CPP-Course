// This program isn't portable - it will run on a linux machine, basically.

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;

void LoadCommands( queue<string>& commands );
void ExecuteCommands( queue<string>& commands );

void Filesystem()
{
    system( "ls" );
}

void Time()
{
    system( "time" );
}

void Uptime()
{
    system( "uptime" );
}

void Directory()
{
    system( "pwd" );
}

void CustomProgram( const string& name )
{
    string cmd = "SubPrograms/" + name;
    system( cmd.c_str() );
}

int main()
{
    queue<string> commands;

    LoadCommands( commands );
    ExecuteCommands( commands );

    return 0;
}

void LoadCommands( queue<string>& commands )
{
    ifstream input( "commands.txt" );
    string buffer;
    while ( input >> buffer )
    {
        commands.push( buffer );
    }
    input.close();
}

void ExecuteCommands( queue<string>& commands )
{
    while ( !commands.empty() )
    {
        cout << endl << "Commands left: " << commands.size() << endl << endl;
        cout << commands.front() << endl;

        if ( commands.front() == "FILESYSTEM" )
        {
            Filesystem();
        }

        else if ( commands.front() == "TIME" )
        {
            Time();
        }

        else if ( commands.front() == "DIRECTORY" )
        {
            Directory();
        }

        else if ( commands.front() == "UPTIME" )
        {
            Uptime();
        }

        else if ( commands.front() == "PROG" )
        {
            commands.pop();
            CustomProgram( commands.front() );
        }

        commands.pop();
    }
}

