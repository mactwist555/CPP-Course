#include <iostream>
#include <string>
using namespace std;

int main()
{
    bool done = false;
    while ( !done )
    {
        cout << "Enter a word: ";
        string word;
        cin >> word;

        cout << "The length of that word is "
            << word.size() << " characters." << endl;

        cout << endl << "Do again? (y/n)";
        string choice;
        cin >> choice;

        // Stop looping if the user is done.
        if ( choice == "n" || choice == "N" )
        {
            done = true;
        }
    }
}

