#include "BinaryTree.hpp"

#include <iostream>
using namespace std;

Node::Node()
{
    ptrLeft = NULL;
    ptrRight = NULL;
}

Node::~Node()
{
    if ( ptrLeft != NULL )
    {
        delete ptrLeft;
        ptrLeft = NULL;
    }

    if ( ptrRight != NULL )
    {
        delete ptrRight;
        ptrRight = NULL;
    }
}

BinaryTree::BinaryTree()
{
    m_ptrRoot = NULL;
}

BinaryTree::~BinaryTree()
{
    if ( m_ptrRoot != NULL )
    {
        delete m_ptrRoot;
        m_ptrRoot = NULL;
    }
}

bool BinaryTree::Insert( int value )
{
    Node* newNode = new Node;
    newNode->value = value;

    // Tree is empty
    if ( m_ptrRoot == NULL )
    {
        m_ptrRoot = newNode;
    }

    // Find location for new node.
    else
    {
        Node* ptrCurrent = m_ptrRoot;

        while ( true )
        {
            // Move Left
            if ( value < ptrCurrent->value )
            {
                if ( ptrCurrent->ptrLeft == NULL )
                {
                    ptrCurrent->ptrLeft = newNode;
                    return true;
                }
                else
                {
                    ptrCurrent = ptrCurrent->ptrLeft;
                }
            }

            // Move Right
            else if ( value > ptrCurrent->value )
            {
                if ( ptrCurrent->ptrRight == NULL )
                {
                    ptrCurrent->ptrRight = newNode;
                    return true;
                }
                else
                {
                    ptrCurrent = ptrCurrent->ptrRight;
                }
            }

            // No Duplicates
            else
            {
                delete newNode;
                return false;
            }
        }
    }
}

bool BinaryTree::Search( int value )
{
    cout << "\n\n Pre order search:  ";
    bool found = PreOrderSearch( m_ptrRoot, value );
    if ( found ) { cout << " FOUND" << endl; }

    cout << "\n\n Post order search: ";
    found = PostOrderSearch( m_ptrRoot, value );
    if ( found ) { cout << " FOUND" << endl; }

    cout << "\n\n In order search:   ";
    found = InOrderSearch( m_ptrRoot, value );
    if ( found ) { cout << " FOUND" << endl; }

    return found;
}

void BinaryTree::Display()
{
    cout << "\n\n Pre order:  ";
    DisplayPreOrder( m_ptrRoot );

    cout << "\n\n Post order: ";
    DisplayPostOrder( m_ptrRoot );

    cout << "\n\n In order:   ";
    DisplayInOrder( m_ptrRoot );
}

bool BinaryTree::NodeHasValue( Node* ptrNode, int value )
{
    cout << ptrNode->value << " ";
    return ( ptrNode->value == value );
}

bool BinaryTree::PreOrderSearch( Node* ptrNode, int value )
{
    // Check current value, then go left and right

    if ( ptrNode == NULL )
        return false;

    if ( NodeHasValue( ptrNode, value ) )
        return true;

    return (
        PreOrderSearch( ptrNode->ptrLeft, value ) ||
        PreOrderSearch( ptrNode->ptrRight, value ) );
}

bool BinaryTree::PostOrderSearch( Node* ptrNode, int value )
{
    // Go left and right, then check current value
    if ( ptrNode == NULL )
        return false;

    if ( PostOrderSearch( ptrNode->ptrLeft, value ) ||
        PostOrderSearch( ptrNode->ptrRight, value ) )
        return true;

    if ( NodeHasValue( ptrNode, value ) )
        return true;

    return false;
}

bool BinaryTree::InOrderSearch( Node* ptrNode, int value )
{
    // Check left, then value, then right
    if ( ptrNode == NULL )
        return false;

    if ( InOrderSearch( ptrNode->ptrLeft, value ) )
        return true;

    if ( NodeHasValue( ptrNode, value ) )
        return true;

    if ( InOrderSearch( ptrNode->ptrRight, value ) )
        return true;

    return false;
}



void BinaryTree::DisplayPreOrder( Node* ptrNode )
{
    if ( ptrNode == NULL ) { return; }
    cout << ptrNode->value << " ";
    DisplayPreOrder( ptrNode->ptrLeft );
    DisplayPreOrder( ptrNode->ptrRight );
}

void BinaryTree::DisplayPostOrder( Node* ptrNode )
{
    if ( ptrNode == NULL ) { return; }
    DisplayPostOrder( ptrNode->ptrLeft );
    DisplayPostOrder( ptrNode->ptrRight );
    cout << ptrNode->value << " ";
}

void BinaryTree::DisplayInOrder( Node* ptrNode )
{
    if ( ptrNode == NULL ) { return; }
    DisplayInOrder( ptrNode->ptrLeft );
    cout << ptrNode->value << " ";
    DisplayInOrder( ptrNode->ptrRight );
}
