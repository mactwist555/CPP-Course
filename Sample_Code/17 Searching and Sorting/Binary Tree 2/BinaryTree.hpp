#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

class Node
{
    public:
    Node();
    ~Node();

    int value;
    Node* ptrLeft;
    Node* ptrRight;
};

class BinaryTree
{
    public:
    BinaryTree();
    ~BinaryTree();

    bool Insert( int value );
    bool Search( int value );
    void Display();

    private:
    // Depth-first
    bool PreOrderSearch( Node* ptrNode, int value );
    bool PostOrderSearch( Node* ptrNode, int value );
    bool InOrderSearch( Node* ptrNode, int value );

    void DisplayPreOrder( Node* ptrNode );
    void DisplayPostOrder( Node* ptrNode );
    void DisplayInOrder( Node* ptrNode );

    bool NodeHasValue( Node* ptrNode, int value );

    Node* m_ptrRoot;
};

#endif
