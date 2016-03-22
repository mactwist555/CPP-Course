#include "Logger.hpp"

int Sum( int a, int b );

int main()
{
    Logger::Setup();

    int sum = Sum( 5, -9 );

    if ( sum < 0 )
    {
        Logger::Error( "Sum is less than 0!", "main()" );
    }

    Logger::Cleanup();
    return 0;
}

int Sum( int a, int b )
{
    Logger::Out( "Function Begin", "Sum" );
    return a + b;
}
