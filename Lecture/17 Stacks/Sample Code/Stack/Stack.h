#ifndef _STACK
#define _STACK

#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class Node
{
	public:
	T 		m_data;
	Node* 	m_next;
};

template <typename T>
class Stack
{
	public:
	Stack();
	~Stack();

	void Pop();
	void Push( T item );
	T Top();

	int GetSize();

	private:
	Node<T>* m_ptrTop;
	Node<T>* m_ptrBottom;
	int m_size;
};

template <typename T>
Stack<T>::Stack()
	: m_ptrTop( 0 ), m_ptrBottom( 0 ), m_size( 0 )
{
	cout << "\t\tCONSTRUCTOR" << endl;
}

template <typename T>
Stack<T>::~Stack()
{
	cout << "\t\tDESTRUCTOR" << endl;
	while ( m_ptrBottom != NULL )
	{
		Pop();
	}
}

template <typename T>
void Stack<T>::Push( T item )
{
	cout << "\t\tPUSH" << endl;

	// Create new node
	Node<T>* newNode = new Node<T>;
	newNode->m_data = item;
	newNode->m_next = NULL;

	if ( m_ptrBottom == NULL )
	{
		// Empty Stack
		m_ptrBottom = newNode;
		m_ptrTop = newNode;
	}
	else
	{
		// Add item to top of stack
		m_ptrTop->m_next = newNode;
		m_ptrTop = newNode;
	}

	m_size++;
}

template <typename T>
void Stack<T>::Pop()
{
	cout << "\t\tPOP" << endl;

	if ( m_ptrBottom->m_next == NULL )
	{
		// Only one item in list
		delete m_ptrBottom;
		m_ptrBottom = NULL;
	}
	else
	{
		// Remove the topmost item.
		// First, we need the 2nd to top item.

		Node<T>* currentNode = m_ptrBottom;
		while ( currentNode->m_next != m_ptrTop )
		{
			currentNode = currentNode->m_next;
		}

		currentNode->m_next = NULL;
		delete m_ptrTop;
		m_ptrTop = currentNode;
	}

	m_size--;
}

template <typename T>
T Stack<T>::Top()
{
	cout << "\t\tTOP" << endl;

	assert ( m_ptrTop != NULL );

	return m_ptrTop->m_data;
}

template <typename T>
int Stack<T>::GetSize()
{
	return m_size;
}


#endif
