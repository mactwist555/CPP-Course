/*
CS 201 Summer 2013 Assignment 3: Employee/Schedule Management program
Solution by Rachel J. Morris
*/

#include <iostream>
using namespace std;

#include "EmployeeHandler.h"
#include "ScheduleHandler.h"

enum MenuOptions { QUIT,
	ADD_EMPLOYEE, EDIT_EMPLOYEE, LAYOFF_EMPLOYEE, VIEW_EMPLOYEE,
	UPDATE_SCHEDULE, CANCEL_SCHEDULE, VIEW_SCHEDULE,
	EXPORT_SCHEDULE_CSV, EXPORT_SCHEDULE_HTML };

void DisplayMainMenu()
{
	cout << endl << endl;
	cout << "BUSINESS MANAGEMENT system!" << endl;
	cout << "---------------------------" << endl;
	cout << "EMPLOYEE OPTIONS" << endl;
	cout << ADD_EMPLOYEE << ". Add Employee" << endl;
	cout << EDIT_EMPLOYEE << ". Edit Employee" << endl;
	cout << LAYOFF_EMPLOYEE << ". Layoff Employee" << endl;
	cout << VIEW_EMPLOYEE << ". View Employee List" << endl;
	cout << "---------------------------" << endl;
	cout << "SCHEDULING OPTIONS" << endl;
	cout << UPDATE_SCHEDULE << ". Update Schedule" << endl;
	cout << CANCEL_SCHEDULE << ". Cancel Schedule" << endl;
	cout << VIEW_SCHEDULE << ". View Schedule" << endl;
	cout << EXPORT_SCHEDULE_CSV << ". Export Schedule to CSV" << endl;
	cout << EXPORT_SCHEDULE_HTML << ". Export Schedule to HTML" << endl;
	cout << "---------------------------" << endl;
	cout << QUIT << ". Quit" << endl;
	cout << "---------------------------" << endl;
	cout << "Please enter an option: ";
}

int main()
{
	EmployeeHandler employeeHandler;
	ScheduleHandler scheduleHandler;

	bool done = false;
	while ( !done )
	{
		DisplayMainMenu();
		int choice;
		cin >> choice;

		switch( choice )
		{
			case ADD_EMPLOYEE:
				employeeHandler.AddEmployee();
			break;
		}

		if ( choice == ADD_EMPLOYEE )
		{
			employeeHandler.AddEmployee();
		}
		else if ( choice == EDIT_EMPLOYEE )
		{
			employeeHandler.EditEmployee();
		}
		else if ( choice == LAYOFF_EMPLOYEE )
		{
			employeeHandler.LayoffEmployee();
		}
		else if ( choice == VIEW_EMPLOYEE )
		{
			employeeHandler.DisplayEmployeeList();
		}
		else if ( choice == UPDATE_SCHEDULE )
		{
			scheduleHandler.AddSchedule( employeeHandler );
		}
		else if ( choice == CANCEL_SCHEDULE )
		{
			scheduleHandler.CancelSchedule();
		}
		else if ( choice == VIEW_SCHEDULE )
		{
			scheduleHandler.DisplaySchedule();
		}
		else if ( choice == EXPORT_SCHEDULE_CSV )
		{
			scheduleHandler.ExportScheduleCSV();
		}
		else if ( choice == EXPORT_SCHEDULE_HTML )
		{
			scheduleHandler.ExportScheduleHTML();
		}
		else if ( choice == QUIT )
		{
			done = true;
		}
	}

	return 0;
}
