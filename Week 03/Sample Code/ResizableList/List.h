#ifndef _LIST
#define _LIST

class List
{
	public:
	List();
	~List();

	bool Append( int number );
	int Count();
	int AllocatedSize();
	void Pop();
	void Remove( int position );

	void OutputAllElements();
	int GetItemAtPosition( int position );

	private:
	void ResizeList( int newSize );

	int* m_list;
	int m_elementSize;
	int m_allocatedSize;
};

#endif
