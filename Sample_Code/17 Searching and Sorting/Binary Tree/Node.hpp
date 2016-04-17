#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

class BinaryTree;

class Node
{
    public:
    Node()
    {
        m_value = 0;
    }

    Node( char value )
    {
        m_value = value;
    }

    ~Node()
    {
        cout << "Destroy node " << m_value << endl;
        if ( m_ptrLeft != NULL )
        {
            delete m_ptrLeft;
            m_ptrLeft = NULL;
        }

        if ( m_ptrRight != NULL )
        {
            delete m_ptrRight;
            m_ptrRight = NULL;
        }
    }

    char GetValue()
    {
        return m_value;
    }

    private:
    char m_value;
    Node* m_ptrLeft;
    Node* m_ptrRight;

    friend BinaryTree;
};

#endif
