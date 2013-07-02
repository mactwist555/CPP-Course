#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Schedule
{
	int year, month, day, hour, minute;
	string title;
};

int main()
{
	bool done = false;

	Schedule scheduleList[10];
	int size = 0;	// Increments when we add event to schedule

	while ( !done )
	{
		cout << endl;
		cout << "1. Add new item to schedule" << endl;
		cout << "2. Save and quit" << endl;
		int choice;
		cin >> choice;

		if ( choice == 1 && size < 10 )
		{
			cout << "Please enter YEAR MONTH DAY: ";
			cin >> scheduleList[size].year
				>> scheduleList[size].month
				>> scheduleList[size].day;
			cout << "Please enter HOUR MINUTE: ";
			cin >> scheduleList[size].hour
				>> scheduleList[size].minute;
			cout << "Please enter event title (one word): ";
			cin >> scheduleList[size].title;
			size++;
		}

		else if ( choice == 1 && size == 10 )
		{
			cout << "ERROR: Schedule is full" << endl;
		}

		else if ( choice == 2 )
		{
			done = true;
		}
	}

	ofstream outfile;
	outfile.open( "Schedule.csv" );

	cout << "Writing to file..." << endl;

	// Header
	outfile << "YEAR,MONTH,DAY,TIME,EVENT" << endl;

	// Schedule data
	for ( int i = 0; i < size; i++ )
	{
		outfile << scheduleList[i].year << ","
			<< scheduleList[i].month << ","
			<< scheduleList[i].day << ","
			<< scheduleList[i].hour << ":" << scheduleList[i].minute << ","
			<< scheduleList[i].title << endl;
	}

	outfile.close();

	cout << "Wrote schedule to \"Schedule.csv\"" << endl;
	cout << "Please open with Excel or a Spreadsheet viewer" << endl;

	return 0;
}
