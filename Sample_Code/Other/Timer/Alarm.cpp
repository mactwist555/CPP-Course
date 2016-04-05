#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	cout << "How many minutes? ";
	int minutes;
	cin >> minutes;

	for (int i = 0; i < minutes; i++)
	{
		Sleep(60000);
	}

	cout << "\a" << endl;

	return 0;
}
