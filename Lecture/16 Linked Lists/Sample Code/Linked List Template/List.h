#ifndef _LIST
#define _LIST

template <typename T>
class Node
{
	public:
	friend class List;

	private:
	Node* m_ptrNext;
	T m_data;
};

template <typename T>
class List
{
	public:
	List();
	~List();

	void Push( T newItem );
	void Pop();

	T GetItem( int index );

	private:
	Node<T>* m_ptrFirst;
	Node<T>* m_ptrLast;
	int m_size;
};

template <typename T>
List<T>::List()
{
	m_ptrFirst = NULL;
	m_ptrLast = NULL;
	m_size = 0;
}

template <typename T>
List<T>::~List()
{
	while ( m_ptrFirst != NULL )
	{
		Pop();
	}
}

template <typename T>
void List<T>::Push( T newItem )
{
	Node<T>* newNode = new Node<T>;
	newNode->m_data = newItem;
	newNode->m_ptrNext = NULL;

	if ( m_ptrFirst == NULL )
	{
		m_ptrFirst = m_ptrLast = newNode;
	}
	else
	{
		m_ptrLast->m_ptrNext = newNode;
		m_ptrLast = newNode;
	}

	m_size++;
}

template <typename T>
void List<T>::Pop()
{
	if ( m_ptrFirst->m_ptrNext == NULL )
	{
		delete m_ptrFirst;
		m_ptrFirst = NULL;
	}
	else
	{
		Node<T>* curNode = m_ptrFirst;

		while ( curNode->m_ptrNext != m_ptrLast )
		{
			curNode = curNode->m_ptrNext;
		}

		delete m_ptrLast;
		curNode->m_ptrNext = NULL;
		m_ptrLast = curNode;
	}
}

template <typename T>
T List<T>::GetItem( int index )
{
	int count = 0;
	Node<T>* curNode = m_ptrFirst;

	while ( curNode != NULL || count < index )
	{
		curNode = curNode->m_ptrNext;
	}

	if ( curNode == NULL )
	{
		return NULL;
	}

	return curNode->m_data;
}

#endif
