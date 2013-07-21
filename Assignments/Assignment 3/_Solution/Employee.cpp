/*
CS 201 Summer 2013 Assignment 3: Employee/Schedule Management program
Solution by Rachel J. Morris
*/

#include "Employee.h"

#include <iostream>
using namespace std;

void Employee::Setup( const string& first, const string& last, float pay )
{
	m_payPerHour = pay;
	m_firstName = first;
	m_lastName = last;

	m_activeEmployee = true;
}

string Employee::GetName()
{
	return m_firstName + " " + m_lastName;
}

bool Employee::GetIsActive()
{
	return m_activeEmployee;
}

void Employee::LayOff()
{
	m_activeEmployee = false;
}

void Employee::Output()
{
	cout << "\t" << m_firstName + " " + m_lastName + ", PAY: $" << m_payPerHour;
	if ( m_activeEmployee )
	{
		cout << " (CURRENT EMPLOYEE)" << endl;
	}
	else
	{
		cout << " (FORMER EMPLOYEE)" << endl;
	}
}
