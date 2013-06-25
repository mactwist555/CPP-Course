#include "Student.h"

#include <iostream>

namespace School
{
	void Student::Setup( const std::string& name, char grade )
	{
		m_name = name;
		m_grade = grade;
	}

	void Student::DisplayInfo()
	{
		std::cout << "Name: " << m_name;
		std::cout << "\t Grade: " << m_grade << std::endl;
	}
}
