#include "IterativeBinaryTree.hpp"

// Tree that uses iterative approaches to insert/search/delete
// instead of recursive, but recursive would be better. :P


IterativeBinaryTree::IterativeBinaryTree()
{
    m_root = NULL;
    m_size = 0;
}

IterativeBinaryTree::~IterativeBinaryTree()
{
    DestroyTree();
}

// This is an ugly function.
// Use recursion - don't implement it this way! :P
void IterativeBinaryTree::DestroyTree()
{
    cout << endl << "Destroy tree" << endl;
    // Destroy all nodes
    while ( true )
    {
        Node* current = m_root;
        if ( current == NULL )
        {
            break;
        }
        cout << "ROOT (" << current->data << ") ";

        Node* parent = m_root;
        int direction = 0;

        while ( current->left != NULL || current->right != NULL )
        {
            parent = current;
            if ( current->left != NULL )
            {
                current = current->left;
                direction = -1;
                cout << ">L (" << current->data << ") ";
            }
            else
            {
                current = current->right;
                direction = 1;
                cout << ">R (" << current->data << ") ";
            }
        }

        if ( current == m_root )
        {
            m_root = NULL;
        }

        cout << " REMOVE: " << current->data << endl;
        delete current;
        current = NULL;

        if ( direction == -1 )
        {
            parent->left = NULL;
        }
        else if ( direction == 1 )
        {
            parent->right = NULL;
        }
    }
}

void IterativeBinaryTree::Insert( char data )
{
    if ( m_root == NULL )
    {
        // First Node
        Node* m_root = new Node;
        m_root->data = data;
    }
    else
    {
        // Find Location, start at the root and keep going down.
        // go LEFT if the new data is LESS THAN the current node,
        // go RIGHT if the new data is GREATER THAN the current node.
        Node* current = m_root;
        while ( true )
        {
            // LESS THAN - LEFT
            if ( data < current->data )
            {
                // No node here yet - found position for new node
                if ( current->left == NULL )
                {
                    current->left = new Node;
                    current->left->data = data;
                    break;
                }
                // Already a node here - go to this node
                else
                {
                    current = current->left;
                }
            }
            // GREATER THAN - RIGHT
            else if ( data > current->data )
            {
                // No node here yet - found position for new node
                if ( current->right == NULL )
                {
                    current->right = new Node;
                    current->right->data = data;
                    break;
                }
                // Already a node here - go to this node
                else
                {
                    current = current->right;
                }
            }
        }
    }

    m_size++;
}

Node* IterativeBinaryTree::GetNode( char data )
{
    Node* current = m_root;
    while ( true )
    {
        if ( data < current->data && current->left != NULL )
        {
            current = current->left;
        }
        else if ( data > current->data && current->right != NULL )
        {
            current = current->right;
        }
        else if ( data == current->data )
        {
            return current;
        }
        else
        {
            return NULL;
        }
    }
}

Node* IterativeBinaryTree::CreateNode( char data )
{
    Node* newNode = new Node;
    newNode->data = data;
    return newNode;
}
