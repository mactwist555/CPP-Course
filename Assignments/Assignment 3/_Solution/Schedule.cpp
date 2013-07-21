/*
CS 201 Summer 2013 Assignment 3: Employee/Schedule Management program
Solution by Rachel J. Morris
*/

#include "Schedule.h"

#include <iostream>
using namespace std;

void Schedule::Setup( int hour )
{
	m_ptrEmployee = NULL;
	m_beginHour = hour;
}

void Schedule::AssignEmployee( Employee* employee )
{
	m_ptrEmployee = employee;
}

void Schedule::Reset()
{
	m_ptrEmployee = NULL;
}

bool Schedule::GetIsSet()
{
	return ( m_ptrEmployee != NULL );
}

void Schedule::Output()
{
	if ( m_ptrEmployee == NULL )
	{
		cout << "\t " << m_beginHour << ":00 - UNALLOCATED" << endl;
	}
	else
	{
		cout << "\t " << m_beginHour << ":00 - " << m_ptrEmployee->GetName() << endl;
	}
}

string Schedule::GetEmployeeName()
{
	if ( m_ptrEmployee == NULL )
	{
		return "UNALLOCATED";
	}
	else
	{
		return m_ptrEmployee->GetName();
	}
}
