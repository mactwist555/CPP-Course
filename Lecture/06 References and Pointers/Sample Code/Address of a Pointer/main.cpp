#include <iostream>
#include <string>
using namespace std;

int main()
{
	string filterBy = "B";
	string* ptrCurrentFilter = &filterBy;

	cout << "filterBy address: \t\t" << &filterBy << endl;
	cout << "ptrCurrentFilter value: \t" << ptrCurrentFilter << endl;
	cout << "ptrCurrentFilter address:\t" << &ptrCurrentFilter << endl;
	cout << "ptrCurrentFilter deref: \t" << *ptrCurrentFilter << endl;

	return 0;
}
