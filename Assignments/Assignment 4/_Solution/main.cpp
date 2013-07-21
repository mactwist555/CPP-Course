/*
CS 201 Summer 2013 Assignment 4: Phonebook appliccation
Solution by Rachel J. Morris
*/

#include <iostream>
using namespace std;

#include "Phonebook.h"

int main()
{
	Phonebook phonebook;
	phonebook.ReadFile( "numbers.txt" );

	return 0;
}
