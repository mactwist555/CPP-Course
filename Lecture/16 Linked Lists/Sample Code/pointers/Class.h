#ifndef _CLASS
#define _CLASS

class SmartPointer
{
	public:

	~SmartPointer()
	{
		m_ptr = NULL;
	}

	void SetPointer( int* address )
	{
		m_ptr = address;

		cout << m_ptr << endl;
	}

	void SetPointer( int& ref )
	{
		m_ptr = &ref;

		cout << m_ptr << endl;
	}

	void Output()
	{
		cout << *m_ptr << endl;
	}

	private:
	int* m_ptr;
};

#endif
