// SOCIAL WALL
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#include "post.hpp"

int GetChoice( int minVal, int maxVal );

int main()
{
    vector<Post> allPosts;

    bool done = false;

    string username;
    cout << "Username: ";
    cin >> username;

    while ( !done )
    {
        cout << endl << "MAIN MENU" << endl;
        cout << "1. Write Post" << endl;
        cout << "2. View Wall" << endl;
        cout << "3. Log Out" << endl;
        cout << "4. Exit" << endl;

        int choice = GetChoice( 1, 4 );

        if ( choice == 1 )
        {
            Post newPost( allPosts.size() );
            newPost.WritePost( username );
            allPosts.push_back( newPost );
        }
        else if ( choice == 2 )
        {
            for ( int i = 0; i < allPosts.size(); i++ )
            {
                allPosts[i].Display();
            }
        }
        else if ( choice == 3 )
        {
            cout << "Username: ";
            cin >> username;
        }
        else if ( choice == 4 )
        {
            done = true;
        }
    }

    ofstream postlog( "log.txt" );
    for ( int i = 0; i < allPosts.size(); i++ )
    {
        postlog << allPosts[i].GetId()
            << ":\t\"" << allPosts[i].GetPost()
            << "\" by " << allPosts[i].GetAuthor() << endl;
    }
    postlog.close();
}

int GetChoice( int minVal, int maxVal )
{
    int value;
    cout << ">> ";
    cin >> value;
    while ( value < minVal || value > maxVal )
    {
        cout << "Invalid choice." << endl;
        cout << ">> ";
        cin >> value;
    }
    return value;
}
