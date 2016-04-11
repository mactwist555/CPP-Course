#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <iostream>
using namespace std;

#include "Node.hpp"

class IterativeBinaryTree
{
    public:
    IterativeBinaryTree();
    ~IterativeBinaryTree();

    void Insert( char data );
    Node* GetNode( char data );

    private:
    Node* CreateNode( char data );
    void DestroyTree();

    Node* m_root;
    int m_size;
};

#endif
