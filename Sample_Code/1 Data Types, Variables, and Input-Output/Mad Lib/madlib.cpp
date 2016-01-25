// Mad Lib program

#include <iostream>     // Input/Output
#include <string>       // String Data Type
using namespace std;

int main()
{
    // Declare variables
    int number;
    float money;
    string noun, noun2;

    // Get user input for story
    cout << "Enter a number: ";
    cin >> number;

    cout << "Enter a dollar amount: $";
    cin >> money;

    cout << "Enter a noun: ";
    cin >> noun;

    cout << "Enter another noun (plural): ";
    cin >> noun2;

    // Display story
    cout << endl << "BEST STORY EVER" << endl;
    cout << "Once there was a " << noun << " that had" << endl;
    cout << number << " " << noun2 << " and $" << money << endl;
    cout << endl;
    cout << "The End" << endl;

    return 0;
}
