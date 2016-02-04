#include <iostream>
#include <string>
#include <fstream> // file i/o
using namespace std;

void OutputSchedule(const string todo[7][24], int day)
{
	for (int i = 0; i < 24; i++)
	{
		cout << i << ":00 \t " << todo[day][i] << endl;
	}
}

int CountEvents(const string todo[7][24], int day)
{
	int events = 0;
	for (int i = 0; i < 24; i++)
	{
		if (todo[day][i] != "")
		{
			events++;
		}
	}
	return events;
}

void SaveFile(const string todo[7][24], const string days[7])
{
	ofstream outfile("ToDo.txt");

	for (int day = 0; day < 7; day++)
	{
		outfile << days[day] << endl;

		for (int hour = 0; hour < 24; hour++)
		{
			outfile << "\t" << hour << ":00 \t " << todo[day][hour] << endl;
		}
	}

	outfile.close();
}

int main()
{
	bool done = false;
	string todo[7][24];
	string days[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	while (!done)
	{
		cout << endl;
		cout << "Choose a day, or type -1 for QUIT" << endl;
		
		for (int i = 0; i < 7; i++)
		{
			cout << i << ". " << days[i] << " (" << CountEvents(todo, i) << ")" << endl;
		}

		cout << ">> ";
		int day;
		cin >> day;

		if (day == -1)
		{
			break;
		}

		OutputSchedule(todo, day);

		cout << "Which time slot? ";
		int time;
		cin >> time;

		cout << "What is your note for this time?" << endl;
		cin.ignore();
		getline(cin, todo[day][time]);
	}

	SaveFile(todo, days);

	return 0;
}
