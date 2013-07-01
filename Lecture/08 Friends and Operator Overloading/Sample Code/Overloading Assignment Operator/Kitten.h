#ifndef _KITTEN
#define _KITTEN

#include <string>
#include <iostream>
using namespace std;

class Kitten
{
	public:
	void Setup( const string& name, int age );
	void Print();

	Kitten& operator=( const Kitten& newValue );

	private:
	string m_name;
	int m_age;
};

#endif
