#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include "Node.hpp"

class BinaryTree
{
    public:
    BinaryTree();
    ~BinaryTree();

    bool Push( char value );
    bool Search( char value );

    void DisplayPreOrder();
    void DisplayPostOrder();
    void DisplayInOrder();

    void DisplayBreadthFirst();

    private:
    Node* m_ptrRoot;
    int m_size;

    // Depth-first Traversals
    void PreOrder( Node* ptrNode );
    void PostOrder( Node* ptrNode );
    void InOrder( Node* ptrNode );

    // Breadth-first Traversal
    void BreadthFirst( Node* ptrNode );
};

#endif
