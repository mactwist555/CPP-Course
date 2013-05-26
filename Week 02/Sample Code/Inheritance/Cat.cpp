#include "Cat.h"

#include <iostream>
using namespace std;

Cat::Cat()
{
	m_call = "Meow!";
	m_name = "Cat";
}

void Cat::ReactToDanger()
{
	cout << "HISS!" << endl;
}
