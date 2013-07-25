#ifndef _QUEUE
#define _QUEUE

#include <iostream>
#include <cassert>
using namespace std;

#include "Node.h"

template <typename T>
class Queue
{
	public:
	Queue();
	~Queue();

	void Pop();
	void Push( T item );
	T Front();

	int GetSize();

	private:
	Node<T>* m_ptrTop;
	Node<T>* m_ptrBottom;
	int m_size;
};

template <typename T>
Queue<T>::Queue()
	: m_ptrTop( 0 ), m_ptrBottom( 0 ), m_size( 0 )
{
}

template <typename T>
Queue<T>::~Queue()
{
	while ( m_ptrBottom != NULL )
	{
		Pop();
	}
}

template <typename T>
void Queue<T>::Push( T item )
{
	// Create new node
	Node<T>* newNode = new Node<T>;
	newNode->m_data = item;
	newNode->m_ptrNext = NULL;

	if ( m_ptrBottom == NULL )
	{
		// Empty Queue
		m_ptrBottom = newNode;
		m_ptrTop = newNode;
	}
	else
	{
		// Add item to end of the queue
		m_ptrTop->m_ptrNext = newNode;
		m_ptrTop = newNode;
	}

	m_size++;
}

template <typename T>
void Queue<T>::Pop()
{
	if ( m_ptrBottom->m_ptrNext == NULL )
	{
		// Only one item in list
		delete m_ptrBottom;
		m_ptrBottom = NULL;
	}
	else
	{
		// Remove the first item
		// 2nd item now becomes the first.
		Node<T>* secondNode = m_ptrBottom->m_ptrNext;
		delete m_ptrBottom;
		m_ptrBottom = secondNode;
	}

	m_size--;
}

template <typename T>
T Queue<T>::Front()
{
	assert ( m_ptrBottom != NULL );

	return m_ptrBottom->m_data;
}

template <typename T>
int Queue<T>::GetSize()
{
	return m_size;
}


#endif

