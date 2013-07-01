#include <iostream>
using namespace std;

class Number
{
	public:
	friend class NumberContainer;

	private:
	int m_number;
};

class NumberContainer
{
	public:
	void Setup()
	{
		for ( int i = 0; i < 10; i++ )
		{
			m_lstNumbers[i].m_number = i / 2;
			cout << m_lstNumbers[i].m_number << endl;
		}
	}

	private:
	Number m_lstNumbers[10];
};

int main()
{
	NumberContainer container;
	container.Setup();

	return 0;
}
