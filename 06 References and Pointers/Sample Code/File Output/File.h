#ifndef _FILE
#define _FILE

#include <iostream>
#include <fstream>
using namespace std;

class File
{
	public:
	File( const string& filename )
	{
		m_file.open( filename.c_str() );
	}
	~File()
	{
		m_file.close();
	}

	void WriteLine( const string& line )
	{
		m_file << "<p>" << line << "</p>" << endl;
	}

	private:
	ofstream m_file;
};

#endif
