#include <iostream>
#include <string>
using namespace std;

void PigLatin( string& first, string& middle, string& last )
{
	first = first + first[0] + "ay";
	first[0] = ' ';

	middle = middle + middle[0] + "ay";
	middle[0] = ' ';

	last = last + last[0] + "ay";
	last[0] = ' ';
}

int main()
{
	string first, middle, last;
	cout << "Enter your first, middle, and last name: ";
	cin >> first >> middle >> last;

	PigLatin( first, middle, last );

	cout << "New name: " << first << " " << middle << " " << last << endl;

	cout << endl << endl;
	return 0;
}
