#ifndef _SCHEDULEHANDLER
#define _SCHEDULEHANDLER

#include "Schedule.h"
#include "EmployeeHandler.h"

class ScheduleHandler
{
	public:
	ScheduleHandler();

	void AddSchedule( EmployeeHandler& employeeHandler );
	void EditSchedule( EmployeeHandler& employeeHandler );
	void CancelSchedule();

	void DisplaySchedule();

	void ExportScheduleCSV();
	void ExportScheduleHTML();

	int ScheduleSelection();

	private:
	Schedule m_lstSchedule[24];
};

#endif
