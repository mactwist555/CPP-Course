/*
CS 201 Summer 2013 Assignment 3: Employee/Schedule Management program
Solution by Rachel J. Morris
*/

#include "ScheduleHandler.h"

#include <iostream>
#include <fstream>
using namespace std;

ScheduleHandler::ScheduleHandler()
{
	for ( int i = 0; i < 24; i++ )
	{
		m_lstSchedule[i].Setup( i );
	}
}

void ScheduleHandler::AddSchedule( EmployeeHandler& employeeHandler )
{
	int hour = ScheduleSelection();

	int employeeIndex = employeeHandler.EmployeeSelection();
	Employee& refEmployee = employeeHandler.GetEmployee( employeeIndex );

	if ( refEmployee.GetIsActive() == false )
	{
		cout << "** ERROR: Employee is not currently working for company!" << endl;
	}

	m_lstSchedule[ hour ].AssignEmployee( &refEmployee );

	cout << "Assigned " << hour << " to employee " << refEmployee.GetName() << endl;
}

void ScheduleHandler::CancelSchedule()
{
	int hour = ScheduleSelection();
	m_lstSchedule[ hour ].Reset();
	cout << "Hour " << hour << " reset" << endl;
}

void ScheduleHandler::DisplaySchedule()
{
	for ( int i = 0; i < 24; i++ )
	{
		cout << "[" << i << "]: ";
		m_lstSchedule[i].Output();
	}
}

void ScheduleHandler::ExportScheduleCSV()
{
	cout << "Enter output filename: ";
	string filename;
	cin >> filename;
	filename = filename + ".csv";

	cout << "Writing to " << filename << "..." << endl;

	ofstream outfile( filename.c_str() );

	// Output HEADER
	outfile << "HOUR,EMPLOYEE" << endl;

	// Output data
	for ( int i = 0; i < 24; i++ )
	{
		outfile << i << ":00," << m_lstSchedule[i].GetEmployeeName() << endl;
	}

	outfile.close();

	cout << "File written to " << filename << endl;
}

void ScheduleHandler::ExportScheduleHTML()
{
	cout << "Enter output filename: ";
	string filename;
	cin >> filename;
	filename = filename + ".html";

	ofstream outfile( filename.c_str() );

	outfile << "<head><title>Schedule</title>" << endl;
	outfile << "<style type='text/css'>" << endl;
	outfile << "table tr td { border: solid 1px #000000; width: 200px;";
	outfile << "background: #cccccc; }" << endl;
	outfile << "</style></head>" << endl;
	outfile << "<body><table>" << endl;
	outfile << "<tr><td>HOUR</td><td>EMPLOYEE</td></tr>" << endl;
	for ( int i = 0; i < 24; i++ )
	{
		outfile << "<tr>" << endl;
		outfile << "<td>" << i << ":00</td>" << endl;
		outfile << "<td>";
		outfile << m_lstSchedule[i].GetEmployeeName();
		outfile << "</td>" << endl;
		outfile << "</tr>" << endl;
	}
	outfile << "</table></body>" << endl;

	outfile.close();

	cout << "File written to " << filename << endl;
}

int ScheduleHandler::ScheduleSelection()
{
	DisplaySchedule();
	cout << "Enter the schedule hour-block: ";
	int index;
	cin >> index;
	return index;
}


