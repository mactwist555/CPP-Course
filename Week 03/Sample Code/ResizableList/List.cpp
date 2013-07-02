#include "List.h"

#include <iostream>
using namespace std;

List::List()
{
	m_elementSize = 0;
	m_allocatedSize = 5;
	m_list = new int[ m_allocatedSize ];
}

List::~List()
{
	delete [] m_list;
}

bool List::Append( int number )
{
	if ( m_elementSize == m_allocatedSize )
	{
		ResizeList( m_allocatedSize + 5 );
	}

	m_list[ m_elementSize ] = number;
	m_elementSize++;

	return true;
}

void List::OutputAllElements()
{
	for ( int i = 0; i < m_elementSize; i++ )
	{
		cout << i << ": "
			<< m_list[i] << endl;
	}
}

void List::ResizeList( int newSize )
{
	// Create a temporary list
	// to store data while we free and
	// reallocate space
	int* tempList = new int[ m_allocatedSize ];
	int oldSize = m_allocatedSize;

	// Copy values into temp
	for ( int i = 0; i < oldSize; i++ )
	{
		tempList[i] = m_list[i];
	}

	// Reallocate space for m_list
	delete [] m_list;
	m_list = new int[ newSize ];
	m_allocatedSize = newSize;

	// Copy data back to m_list
	for ( int i = 0; i < oldSize; i++ )
	{
		m_list[i] = tempList[i];
	}

	// free memory for tempList
	delete [] tempList;
}

int List::AllocatedSize()
{
	return m_allocatedSize;
}

void List::Remove( int position )
{
	for ( int i = position + 1; i < m_elementSize; i++ )
	{
		m_list[ i - 1 ] = m_list[i];
	}

	m_elementSize--;
}

void List::Pop()
{
	m_elementSize--;
}

int List::GetItemAtPosition( int position )
{
	if ( position >= m_elementSize ||
			position < 0 )
	{
		return 0;
	}

	return m_list[ position ];
}





