#include "IterativeBinaryTree.hpp"
#include "RecursiveBinaryTree.hpp"

#include <iostream>
using namespace std;

int main()
{
    char l[] = { 'M', 'G', 'Q', 'H', 'C', 'A', 'B', 'Y', 'T', 'R' };

    IterativeBinaryTree iterativeTree;
    RecursiveBinaryTree recursiveTree;
    for ( int i = 0; i < 10; i++ )
    {
        iterativeTree.Insert( l[i] );
        recursiveTree.Insert( l[i] );
    }

    return 0;
}
