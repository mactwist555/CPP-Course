#include "Classroom.h"

#include <iostream>
using namespace std;

#include <stdlib.h>		// For random numbers
#include <time.h>		// For time

Classroom::Classroom()
{
	m_students[0].firstName = "not";
	m_students[0].lastName = "found";
	m_classSize = 1;
	srand( time( NULL ) );
}

void Classroom::AddStudent( string firstName, string lastName )
{
	if ( m_classSize < 20 )
	{
		m_students[ m_classSize ].firstName = firstName;
		m_students[ m_classSize ].lastName = lastName;
		m_classSize++;

		cout << "Added " << lastName << ", " << firstName << " to classroom" << endl;
	}
}

void Classroom::SetRandomGrades()
{
	for ( int i = 0; i < m_classSize; i++ )
	{
		int randGrade = rand() % 5;

		switch( randGrade )
		{
			case 0:
			m_students[i].grade = 'A';
			break;

			case 1:
			m_students[i].grade = 'B';
			break;

			case 2:
			m_students[i].grade = 'C';
			break;

			case 3:
			m_students[i].grade = 'D';
			break;

			case 4:
			m_students[i].grade = 'F';
			break;
		}
	}
}

Student& Classroom::operator[]( const string lastName )
{
	// Find student with matching name
	for ( int i = 0; i < m_classSize; i++ )
	{
		if ( m_students[i].lastName == lastName )
		{
			return m_students[i];
		}
	}

	return m_students[0];
}
