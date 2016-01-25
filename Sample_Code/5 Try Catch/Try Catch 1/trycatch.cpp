#include <iostream>
using namespace std;

float Division( float a, float b ) throw ( string );

int main()
{
    float budget;
    int studentCount;

    cout << "What's the budget? $";
    cin >> budget;

    cout << "How many students? ";
    cin >> studentCount;

    float pricePerStudent;

    try
    {
        pricePerStudent = Division( budget, studentCount );
        cout << "Price per student: $" << pricePerStudent << endl;
    }
    catch ( string message )
    {
        cerr << message << endl;
    }

    cout << "The End" << endl;

    return 0;
}

float Division( float a, float b ) throw ( string )
{
    if ( b == 0 )
    {
        throw string( "Division by zero!" );
    }
    // If throw is hit, we won't get to this point in the function.
    return ( a / b );
}
