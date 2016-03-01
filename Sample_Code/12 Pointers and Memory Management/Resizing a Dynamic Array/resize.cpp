#include <iostream>
#include <string>
using namespace std;

int main()
{
    // First array
    string* names = new string[ 5 ];
    names[0] = "Snake";
    names[1] = "Ocelot";
    names[2] = "Octopus";
    names[3] = "Fox";
    names[4] = "Wolf";

    // Oops, need more space...
    // Create a temporary array with a bigger size:
    string* newArray = new string[ 10 ];

    // Copy over the contents of the old array:
    for ( int i = 0; i < 5; i++ )
    {
        newArray[i] = names[i];
    }

    // Delete the old array, free that memory:
    delete [] names;

    // But, we still want to use the original array name.
    // So, we will change pointers!
    // Point "names" to the new, bigger array,
    // and reset our temporary array to NULL.

    names = newArray;
    newArray = NULL;

    // Now we can keep using the original names array
    names[5] = "Raven";
    names[6] = "Mantis";
    names[7] = "Fortune";
    names[8] = "Vamp";
    names[9] = "Fatman";

    // Output the results! :)
    for ( int i = 0; i < 10; i++ )
    {
        cout << (i+1) << ": " << names[i] << endl;
    }

    // Don't forget that we need to delete
    // the bigger array once the program ends.
    // names is currently pointing to the big array.
    delete [] names;

    return 0;
}



