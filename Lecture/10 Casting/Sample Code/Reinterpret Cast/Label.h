#ifndef _LABEL
#define _LABEL

#include <string>
using namespace std;

class Label
{
	public:
	Label( const string& text )
	{
		SetText( text );
	}

	void SetText( const string& text )
	{
		m_text = text;
	}

	virtual void Output()
	{
		cout << m_text << endl;
	}

	protected:
	string m_text;
};

class FancyLabel : public Label
{
	public:
	FancyLabel( const string& text )
		: Label( text )
	{ uniqueMember = 20; }

	virtual void Output()
	{
		for ( int i = 0; i < m_text.length() + 4; i++ )
		{
			cout << "*";
		}
		cout << endl;

		cout << "* " << m_text << " *" << endl;

		for ( int i = 0; i < m_text.length() + 4; i++ )
		{
			cout << "*";
		}
		cout << endl;
	}

	void UniqueFunction()
	{
		cout << "This is a unique function!" << endl;
		cout << uniqueMember << endl;
	}

	protected:
	int uniqueMember;
};

#endif


