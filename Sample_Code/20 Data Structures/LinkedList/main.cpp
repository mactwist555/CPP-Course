#include <iostream>
#include <string>
using namespace std;

#include "LinkedList.hpp"

int main()
{
    LinkedList<int> numbers;

    cout << "\n Add items to both ends" << endl;
    numbers.PushFront( 10 );
    numbers.PushFront( 11 );
    numbers.PushFront( 12 );
    numbers.PushBack( 20 );
    numbers.PushBack( 21 );
    numbers.PushBack( 22 );

    numbers.Display();

    cout << "\n Remove both ends" << endl;
    numbers.PopBack();
    numbers.PopFront();

    numbers.Display();

    return 0;
}
