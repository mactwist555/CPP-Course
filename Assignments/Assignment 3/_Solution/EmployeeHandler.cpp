/*
CS 201 Summer 2013 Assignment 3: Employee/Schedule Management program
Solution by Rachel J. Morris
*/

#include "EmployeeHandler.h"

#include <iostream>
using namespace std;

EmployeeHandler::EmployeeHandler()
{
	m_employeeCount = 0;
}

void EmployeeHandler::AddEmployee()
{
	cout << "NEW EMPLOYEE" << endl;

	cout << "First name? ";
	string fname;
	cin >> fname;

	cout << "Last name? ";
	string lname;
	cin >> lname;

	cout << "Pay rate? $";
	float pay;
	cin >> pay;

	m_lstEmployee[ m_employeeCount ].Setup( fname, lname, pay );
	cout << "** Employee " << m_employeeCount << " added" << endl;

	m_employeeCount++;
}

int EmployeeHandler::EmployeeSelection()
{
	DisplayEmployeeList();
	cout << "Enter the index of the employee: ";
	int index;
	cin >> index;
	return index;
}

void EmployeeHandler::EditEmployee()
{
	int index = EmployeeSelection();

	if ( index >= m_employeeCount || index < 0 )
	{
		cout << "Invalid index" << endl;
		return;
	}

	m_lstEmployee[ index ].Output();

	cout << "First name? ";
	string fname;
	cin >> fname;

	cout << "Last name? ";
	string lname;
	cin >> lname;

	cout << "Pay rate? $";
	float pay;
	cin >> pay;

	m_lstEmployee[ index ].Setup( fname, lname, pay );
	cout << "** Employee " << index << " updated" << endl;
}

void EmployeeHandler::LayoffEmployee()
{
	int index = EmployeeSelection();

	m_lstEmployee[ index ].Output();
	m_lstEmployee[ index ].LayOff();

	cout << "** Employee " << index << " laid off" << endl;
}

void EmployeeHandler::DisplayEmployeeList()
{
	cout << "EMPLOYEES" << endl;
	for ( int i = 0; i < m_employeeCount; i++ )
	{
		cout << ">> [" << i << "]:\t";
		m_lstEmployee[i].Output();
	}
}

Employee& EmployeeHandler::GetEmployee( int index )
{
	return m_lstEmployee[index];
}

int EmployeeHandler::GetEmployeeCount()
{
	return m_employeeCount;
}
