#include <iostream>
#include <string>
using namespace std;

int main()
{
    while ( true )
    {
        string word;
        cout << endl << "Type a word: ";
        cin >> word;

        for ( unsigned int i = 0; i < word.size(); i++ )
        {
            cout << "\t'" << word[i] << "'" << endl;
        }
    }

    return 0;
}

