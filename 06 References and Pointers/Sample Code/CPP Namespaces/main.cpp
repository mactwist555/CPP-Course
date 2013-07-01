#include <iostream>
// using namespace std;

#include "Student.h"
// using namespace School

int main()
{
	std::cout << "Hello, world!" << std::endl;

	School::Student studentBob;

	studentBob.Setup( "Bob", 'A' );
	studentBob.DisplayInfo();

	return 0;
}
