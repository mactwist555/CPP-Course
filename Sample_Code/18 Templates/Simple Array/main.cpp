#include <iostream>
using namespace std;

template <typename T>
class Array
{
    public:
    void Set( int index, T value )
    {
        if ( index < 0 || index >= 10 )
            return ;
        data[ index ] = value;
    }

    T Get( int index )
    {
        if ( index < 0 || index >= 10 )
            return NULL;
        return data[ index ];
    }

    void DisplayAll()
    {
        for ( int i = 0; i < 10; i++ )
        {
            cout << data[ i ] << ", ";
        }
        cout << endl << endl;
    }

    private:
    T data[10];
};

int main()
{
    Array<int>      numbers;
    numbers.Set( 0, 10 );
    numbers.Set( 1, 13 );
    numbers.DisplayAll();

    Array<string>   words;
    words.Set( 0, "Cat" );
    words.Set( 1, "Puppy" );
    words.Set( 4, "Crocodile" );
    words.DisplayAll();

    return 0;
}
