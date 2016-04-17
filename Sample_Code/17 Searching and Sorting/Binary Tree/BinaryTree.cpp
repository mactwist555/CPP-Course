#include "BinaryTree.hpp"

#include <vector>

BinaryTree::BinaryTree()
{
    m_ptrRoot = NULL;
    m_size = 0;
}

BinaryTree::~BinaryTree()
{
    if ( m_ptrRoot != NULL )
    {
        delete m_ptrRoot;
        m_ptrRoot = NULL;
    }
}


bool BinaryTree::Push( char value )
{
    Node* newNode = new Node( value );

    // This is the new root
    if ( m_ptrRoot == NULL )
    {
        m_ptrRoot = newNode;
    }

    // Find a place for the new node
    else
    {
        Node* ptrParent = NULL;
        Node* ptrCurrent = m_ptrRoot;

        while ( true )
        {
            ptrParent = ptrCurrent;

            // No duplicates
            if ( value == ptrCurrent->m_value )
            {
                delete newNode;
                return false;
            }

            // Or move left
            else if ( value < ptrCurrent->m_value )
            {
                ptrCurrent = ptrCurrent->m_ptrLeft;

                if ( ptrCurrent == NULL )
                {
                    ptrParent->m_ptrLeft = newNode;
                    m_size++;
                    return true;
                }
            }

            // Or move right
            else if ( value > ptrCurrent->m_value )
            {
                ptrCurrent = ptrCurrent->m_ptrRight;

                if ( ptrCurrent == NULL )
                {
                    ptrParent->m_ptrRight = newNode;
                    m_size++;
                    return true;
                }
            }
        }
    }
    // Function should not get here
    return true;
}

bool BinaryTree::Search( char value )
{
    if ( m_ptrRoot == NULL )
    {
        return false;
    }

    Node* ptrCurrent = m_ptrRoot;
    while ( ptrCurrent->m_value != value )
    {
        if( value < ptrCurrent->m_value )
        {
            ptrCurrent = ptrCurrent->m_ptrLeft;
        }
        else
        {
            ptrCurrent = ptrCurrent->m_ptrRight;
        }

        if ( ptrCurrent == NULL )
        {
            return false;
        }
    }

    return true;
}

void BinaryTree::DisplayPreOrder()
{
    PreOrder( m_ptrRoot );
}

void BinaryTree::DisplayPostOrder()
{
    PostOrder( m_ptrRoot );
}

void BinaryTree::DisplayInOrder()
{
    InOrder( m_ptrRoot );
}

void BinaryTree::DisplayBreadthFirst()
{
    BreadthFirst( m_ptrRoot );
}

void BinaryTree::PreOrder( Node* ptrNode )
{
    if ( ptrNode != NULL )
    {
        cout << ptrNode->m_value << " ";
        PreOrder( ptrNode->m_ptrLeft );
        PreOrder( ptrNode->m_ptrRight );
    }
}

void BinaryTree::PostOrder( Node* ptrNode )
{
    if ( ptrNode != NULL )
    {
        PostOrder( ptrNode->m_ptrLeft );
        PostOrder( ptrNode->m_ptrRight );
        cout << ptrNode->m_value << " ";
    }
}

void BinaryTree::InOrder( Node* ptrNode )
{
    if ( ptrNode != NULL )
    {
        InOrder( ptrNode->m_ptrLeft );
        cout << ptrNode->m_value << " ";
        InOrder( ptrNode->m_ptrRight );
    }
}

void BinaryTree::BreadthFirst( Node* ptrNode )
{
    // Add nodes to queue in order of tree depth
    vector<Node*> q;

    if ( ptrNode == NULL )
    {
        return;
    }

    q.push_back( ptrNode );
    while ( q.size() > 0 )
    {
        Node* ptrCurrent = q[0];
        q.erase( q.begin() );
        cout << ptrCurrent->m_value << " ";

        if ( ptrCurrent->m_ptrLeft != NULL )
        {
            q.push_back( ptrCurrent->m_ptrLeft );
        }
        if ( ptrCurrent->m_ptrRight != NULL )
        {
            q.push_back( ptrCurrent->m_ptrRight );
        }
    }
}

