#include <iostream>
#include <string>
using namespace std;

#include "BinaryTree.hpp"

int main()
{
    BinaryTree tree;

    tree.Insert( 4 );
    tree.Insert( 6 );
    tree.Insert( 7 );
    tree.Insert( 9 );

    tree.Search( 7 );
    tree.Search( 8 );

    tree.Display();

    return 0;
}
