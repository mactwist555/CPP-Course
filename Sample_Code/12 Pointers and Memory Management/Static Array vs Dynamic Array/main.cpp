#include <iostream>
#include <string>
using namespace std;

int main()
{
    int staticArray[ 10 ];

    int* dynamicArray;
    dynamicArray = new int[ 10 ];
    delete [] dynamicArray;

    return 0;
}



