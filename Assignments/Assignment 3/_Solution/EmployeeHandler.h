#ifndef _EMPLOYEEHANDLER
#define _EMPLOYEEHANDLER

#include "Employee.h"

class EmployeeHandler
{
	public:
	EmployeeHandler();

	void AddEmployee();
	void EditEmployee();
	void LayoffEmployee();
	void DisplayEmployeeList();

	int EmployeeSelection();

	Employee& GetEmployee( int index );

	int GetEmployeeCount();

	private:
	Employee m_lstEmployee[50];
	int m_employeeCount;
};

#endif
