#ifndef _LIST
#define _LIST

#include "PhoneNumber.h"

template <typename T>
class List
{
	public:
	List();
	~List();

	void AddItem( T item );

	void OutputAll();

	int GetSize();

	private:
	void Resize();
	bool IsAlreadyInList( const T& item );

	T* 	m_list;
	int m_size;
	int m_allocated;
};

template <typename T>
List<T>::List()
{
	m_size = 0;
	m_allocated = 10;
	m_list = new T[ m_allocated ];
}

template <typename T>
List<T>::~List()
{
	delete [] m_list;
}

template <typename T>
void List<T>::AddItem( T item )
{
	if ( m_size == m_allocated )
	{
		Resize();
	}

	if ( !IsAlreadyInList( item ) )
	{
		m_list[ m_size ] = item;
		m_size++;
	}
}

template <typename T>
int List<T>::GetSize()
{
	return m_size;
}

template <typename T>
void List<T>::OutputAll()
{
	for ( int i = 0; i < m_size; i++ )
	{
		cout << m_list[ i ] << endl;
	}
}

template <typename T>
void List<T>::Resize()
{
	T* tempList = new T[ m_allocated ];
	for ( int i = 0; i < m_size; i++ )
	{
		tempList[i] = m_list[i];
	}

	delete [] m_list;
	m_allocated += 10;
	m_list = new T[ m_allocated ];

	for ( int i = 0; i < m_size; i++ )
	{
		m_list[i] = tempList[i];
	}

	delete [] tempList;
}

template <typename T>
bool List<T>::IsAlreadyInList( const T& item )
{
	for ( int i = 0; i < m_size; i++ )
	{
		if ( item == m_list[ i ] )
		{
			return true;
		}
	}

	return false;
}

#endif

