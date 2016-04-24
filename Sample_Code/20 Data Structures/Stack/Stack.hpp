#ifndef STACK_HPP
#define STACK_HPP

#include "../LinkedList/LinkedList.hpp"

template <typename T>
class Stack
{
    public:
    void Push( T data )
    {
        cout << "Push " << data << endl;
        container.PushBack( data );
    }

    void Pop()
    {
        cout << "Pop " << Top() << endl;
        container.PopBack();
    }

    T Top()
    {
        return container.GetLast();
    }

    int Size()
    {
        return container.Size();
    }

    private:
    LinkedList<T> container;
};

#endif
