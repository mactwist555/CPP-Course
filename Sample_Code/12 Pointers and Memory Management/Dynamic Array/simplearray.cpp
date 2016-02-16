#include <iostream>
#include <string>
using namespace std;

int main()
{
    int amount;
    cout << "How many items? ";
    cin >> amount;

    float* prices = new float[ amount ];

    for ( int i = 0; i < amount; i++ )
    {
        cout << "Enter price for item " << i << ": ";
        cin >> prices[i];
    }

    delete [] prices; // Free the memory
    prices = NULL; // Reset the pointer to no address

    string* nameList;

    nameList = new string[ 10 ];

    nameList[0] = "Stephanie Shirley";
    nameList[1] = "Ada Lovelace";
    nameList[2] = "Grace Hopper";

    delete [] nameList;

    return 0;
}


