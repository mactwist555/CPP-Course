#ifndef NODE_HPP
#define NODE_HPP

class Node
{
    public:
    Node()
    {
        left = NULL;
        right = NULL;
    }

    char data;
    Node* left;
    Node* right;
};


#endif
