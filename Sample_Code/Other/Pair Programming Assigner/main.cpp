#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

void ReadStudentList( vector<string>& names );
string SpaceOut( const string& value, int spaces = 20 );

struct Group
{
    int teamNumber;
    vector<string> members;

    void Output()
    {
        cout << "Team " << teamNumber << ":" << endl;
        for ( int i = 0; i < members.size(); i++ )
        {
            cout << SpaceOut( members[i] );
        }
        cout << endl << endl;
    }
};

void AssignGroups( vector<string>& names, vector<Group>& groups, int membersPerTeam );

int main()
{
    cout << "STUDENT PAIRING RANDOM SELECTOR" << endl << endl;

    cout << "Enter a seed: ";
    int seed;
    cin >> seed;

    srand( seed );

    vector<string> students;
    ReadStudentList( students );

    vector<Group> groups;
    AssignGroups( students, groups, 2 );

    cout << endl << "STUDENT TEAMS:" << endl;
    for ( int i = 0; i < groups.size(); i++ )
    {
        groups[i].Output();
    }

    return 0;
}

void AssignGroups( vector<string>& names, vector<Group>& groups, int membersPerTeam )
{
    int teamCount = names.size() / membersPerTeam + 1;

    cout << "Generating " << teamCount << " teams..." << endl;

    for ( int t = 0; t < teamCount; t++ )
    {
        Group newGroup;
        newGroup.teamNumber = t+1;

        for ( int m = 0; m < membersPerTeam; m++ )
        {
            if ( names.size() == 0 )
            {
                break;
            }
            int randIndex = rand() % names.size();
            newGroup.members.push_back( names[ randIndex ] );
            names.erase( names.begin() + randIndex );
        }

        groups.push_back( newGroup );
    }

    // Fix a single-person group
    int removeIndex = -1;
    for ( int g = 1; g < groups.size(); g++ )
    {
        if ( groups[g].members.size() == 1 )
        {
            groups[g-1].members.push_back( groups[g].members[0] );
            removeIndex = g;
        }
    }

    if ( removeIndex != -1 )
    {
        groups.erase( groups.begin() + removeIndex );
    }
}

void ReadStudentList( vector<string>& names )
{
    string buffer;
    string name;
    bool isPresent;
    ifstream input( "jccc.txt" );

    input >> buffer >> buffer;
    while ( input >> name >> isPresent )
    {
        if ( isPresent )
        {
            names.push_back( name );
        }
    }

    input.close();

    cout << names.size() << " students present" << endl;
}

string SpaceOut( const string& value, int spaces )
{
    string spaced = "";
    for ( int i = 0; i < spaces - value.size(); i++ )
    {
        spaced += " ";
    }
    spaced += value;
    return spaced;
}
