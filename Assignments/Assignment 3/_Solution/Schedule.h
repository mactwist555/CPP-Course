#ifndef _SCHEDULE
#define _SCHEDULE

#include <string>
using namespace std;

#include "Employee.h"

class Schedule
{
	public:
	void Setup( int hour );
	void AssignEmployee( Employee* employee );
	string GetEmployeeName();
	void Output();
	void Reset();
	bool GetIsSet();

	private:
	Employee* m_ptrEmployee;
	int m_beginHour;
};

#endif

