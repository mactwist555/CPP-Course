#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Localization.hpp"
#include "Social.hpp"

enum Languages { ENGLISH, ESPERANTO, PIGLATIN };
enum Choices { NEW_POST, VIEW_WALL, VIEW_FRIENDS, ADD_FRIEND, LOG_OUT };

int GetChoice( int min, int max );
int SelectLanguage( Localization languages[], int amount );
int MainMenu( Localization& lang );
void LoadTestContent( Friend friends[3] );

void ViewWall( Friend friends[3], vector<Post>& posts );
void ViewFriends( Friend friends[3] );

int main()
{
    Localization languages[3];
    languages[0].LoadFile( "english.txt" );
    languages[1].LoadFile( "esperanto.txt" );
    languages[2].LoadFile( "piglatin.txt" );
    int languageId = SelectLanguage( languages, 3 );
    Localization& lang = languages[languageId];

    Friend friends[10];
    LoadTestContent( friends );

    vector<Post> posts;

    cout << endl;

    bool done = false;
    while ( !done )
    {
        int choice = MainMenu( lang );
        if ( choice == NEW_POST )
        {
            Post newPost;

            cout << lang["NEW POST CONTENT"] << ": ";
            cin.ignore();
            getline( cin, newPost.content );

            cout << lang["NEW POST FEELING"] << ": ";
            getline( cin, newPost.mood );

            newPost.date = "2016-03-10";
            newPost.author = "YOU";

            posts.push_back( newPost );
        }
        else if ( choice == VIEW_WALL )
        {
            ViewWall( friends, posts );
        }
        else if ( choice == VIEW_FRIENDS )
        {
            ViewFriends( friends );
        }
        else if ( choice == ADD_FRIEND )
        {
            cout << lang["WHAT IS FRIENDS NAME"] << ": ";
            cin.ignore();
            string buffer;
            getline( cin, buffer );
        }
        else if ( choice == LOG_OUT )
        {
            done = true;
        }
    }

    return 0;
}

void ViewWall( Friend friends[3], vector<Post>& posts )
{
    for ( int i = 0; i < 3; i++ )
    {
        for ( int p = 0; p < 3; p++ )
        {
            cout << friends[i][p] << endl;
        }
    }

    for ( int i = 0; i < posts.size(); i++ )
    {
        cout << posts[i] << endl;
    }
}

void ViewFriends( Friend friends[3] )
{
    for ( int i = 0; i < 3; i++ )
    {
        cout << friends[i].name << endl;
    }
}

int SelectLanguage( Localization languages[], int amount )
{
    cout << "LANGUAGE SELECTION" << endl;
    for ( int i = 0; i < amount; i++ )
    {
        cout << i+1 << ". " << languages[i].GetName() << endl;
    }
    return GetChoice( 1, amount ) - 1;
}

int MainMenu( Localization& lang )
{
    cout << endl;
    cout << lang["MAIN MENU"] << endl;
    cout << "1. " << lang["NEW POST"] << endl;
    cout << "2. " << lang["VIEW WALL"] << endl;
    cout << "3. " << lang["VIEW FRIENDS"] << endl;
    cout << "4. " << lang["ADD FRIEND"] << endl;
    cout << "5. " << lang["LOG OUT"] << endl;
    return GetChoice( 1, 5 ) - 1;
}

int GetChoice( int min, int max )
{
    int choice;
    cout << "(" << min << " to " << max << "): ";
    cin >> choice;
    while ( choice < min || choice > max )
    {
        cout << "Invalid choice!" << endl;
        cout << "(" << min << " to " << max << "): ";
        cin >> choice;
    }
    return choice;
}

void LoadTestContent( Friend friends[3] )
{
    ifstream infile( "test.txt" );
    string buffer;

    int i = 0;
    while ( getline( infile, buffer ) )
    {
        getline( infile, friends[i].name );
        getline( infile, buffer );

        for ( int p = 0; p < 3; p++ )
        {
            getline( infile, friends[i].posts[p].content );
            getline( infile, friends[i].posts[p].mood );
            getline( infile, friends[i].posts[p].date );
            friends[i].posts[p].author = friends[i].name;
            getline( infile, buffer );
        }

        i++;
    }

    infile.close();
}
