#ifndef _FILE
#define _FILE

#include <fstream>
#include <iostream>
using namespace std;

class File
{
	public:
	File()
	{
		m_file.open( "default.txt" );
	}

	File( const string& filename )
	{
		m_file.open( filename.c_str() );
	}

	~File()
	{
		m_file.close();
	}

	static void WriteLine( const string& line )
	{
		m_file << "<p>" << line << "</p>" << endl;
		cout << line << endl;
	}

	private:
	static ofstream m_file;
};

ofstream File::m_file;

#endif
