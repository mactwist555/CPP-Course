/*
CS 201 Summer 2013 Assignment 3: Employee/Schedule Management program
Solution by Rachel J. Morris
*/

#ifndef _EMPLOYEE
#define _EMPLOYEE

#include <string>
using namespace std;

class Employee
{
	public:
	void Setup( const string& first, const string& last, float pay );

	string GetName();
	bool GetIsActive();

	void LayOff();
	void Output();

	private:
	string m_firstName;
	string m_lastName;
	float m_payPerHour;
	bool m_activeEmployee;
};

#endif
