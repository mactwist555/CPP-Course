#ifndef _LIST
#define _LIST

#include <string>
#include <iostream>
using namespace std;

class Node
{
	public:
	friend class List;

	private:
	string m_data;
	Node* m_nextNode;
};

class List
{
	public:
	List();
	~List();

	int GetSize(); 					// Get List size

	void Push( string newItem ); 	// Add item to end of list
	void Pop();						// Remove first item in list

	string GetItem( int index );	// Get item at index

	private:
	int m_size;
	Node* m_firstNode;
	Node* m_lastNode;				// If we store the last node,
									// it will be easier to Push new elements.
};

List::List()
{
	cout << endl << "CONSTRUCTOR" << endl;
	m_firstNode = NULL;
	m_lastNode = NULL;
	m_size = 0;
}

List::~List()
{
	cout << endl << "DESTRUCTOR" << endl;
	while ( m_firstNode != NULL )
	{
		Pop();
	}
}

int List::GetSize()
{
	return m_size;
}

void List::Push( string newItem )
{
	cout << endl << "PUSH ITEM \"" << newItem << "\"" << endl;

	// Create a new Node
	Node* newNode = new Node;
	newNode->m_data 	= newItem;
	newNode->m_nextNode = NULL;

	if ( m_lastNode == NULL )
	{
		// The list is empty
		m_firstNode = newNode;
		m_lastNode 	= newNode;
	}
	else
	{
		// A last node exists
		m_lastNode->m_nextNode 	= newNode;
		m_lastNode 				= newNode;
	}

	m_size++;
}

void List::Pop()
{
	if ( m_firstNode->m_nextNode == NULL )
	{
		// Only one item in the list!
		delete m_firstNode;

		// Any time we free up memory we want to
		// set the pointer equal to NULL.
		m_firstNode = NULL;
	}
	else
	{
		// Multiple items in the list. Remove last one.
		Node* ptrNode = m_firstNode;

		// Get the 2nd to last Node.
		while ( ptrNode->m_nextNode != m_lastNode )
		{
			ptrNode = ptrNode->m_nextNode;
		}

		// Delete the last node
		delete m_lastNode;
		m_lastNode = NULL;

		// Point the 2nd to last node to NULL.
		// It is our new Last.
		ptrNode->m_nextNode = NULL;
		m_lastNode = ptrNode;
	}
}

string List::GetItem( int index )
{
	int counter = 0;

	Node* ptrNode = m_firstNode;
	while ( counter != index && ptrNode != NULL )
	{
		counter++;
		ptrNode = ptrNode->m_nextNode;
	}

	if ( ptrNode == NULL )
	{
		return "INVALID INDEX";
	}

	return ptrNode->m_data;
}



#endif
