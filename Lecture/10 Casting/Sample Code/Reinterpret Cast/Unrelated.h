#ifndef _UNRELATED
#define _UNRELATED

#include <string>
using namespace std;

class Unrelated
{
	public:
	Unrelated( const string& text )
	{
		SetFilename( text );
	}

	void SetFilename( const string& text )
	{
		m_filename = "*** " + text + " ***";
	}

	protected:
	string m_filename;
};

#endif
