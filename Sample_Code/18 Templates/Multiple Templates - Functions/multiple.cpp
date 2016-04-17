#include <iostream>
#include <string>
using namespace std;

template <typename T1, typename T2>
void Display( T1 itemA, T2 itemB )
{
    cout << itemA << "\t\t" << itemB << endl;
}

int main()
{
    vector<string>      names;
    list<float>         prices;
    map<int, string>    idToStudents;

    int num = 50;
    string str = "hello";
    float price = 9.99;

    Display( num, str );
    Display( str, num );
    Display( num, price );

    return 0;
}


