#include <iostream>
using namespace std;

#include "BinaryTree.hpp"

int main()
{
    BinaryTree tree;

    tree.Push( 'E' );
    tree.Push( 'B' );
    tree.Push( 'F' );
    tree.Push( 'A' );
    tree.Push( 'C' );
    tree.Push( 'G' );
    tree.Push( 'H' );
    tree.Push( 'D' );

    cout << endl << endl << "In Order:" << endl;
    tree.DisplayInOrder();

    cout << endl << endl << "Pre Order:" << endl;
    tree.DisplayPreOrder();

    cout << endl << endl << "Post Order:" << endl;
    tree.DisplayPostOrder();

    cout << endl << endl << "Breadth-first:" << endl;
    tree.DisplayBreadthFirst();

    cout << endl << endl << "Bye-bye" << endl;


    return 0;
}
