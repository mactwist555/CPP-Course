#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "../LinkedList/LinkedList.hpp"

template <typename T>
class Queue
{
    public:
    void Push( T data )
    {
        cout << "Push " << data << endl;
        container.PushBack( data );
    }

    void Pop()
    {
        cout << "Pop " << Front() << endl;
        container.PopFront();
    }

    T Front()
    {
        return container.GetFirst();
    }

    int Size()
    {
        return container.Size();
    }

    private:
    LinkedList<T> container;
};

#endif
