#ifndef _STUDENT
#define _STUDENT

#include <string>

namespace School
{

class Student
{
	public:
	void Setup( const std::string& name, char grade );
	void DisplayInfo();

	private:
	std::string m_name;
	char m_grade;
};

}

#endif
