#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "How many students are there? ";

	int studentCount;
	cin >> studentCount;

	string* students = new string[ studentCount ];

	for ( int i = 0; i < studentCount; i++ )
	{
		cout << "Name of student #" << i << ": ";
		cin >> students[i];
	}


	for ( int i = 0; i < studentCount; i++ )
	{
		cout << "Name of student #" << i << ": " << students[i] << endl;
	}

	delete [] students;

	return 0;
}
