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
	{ ; }

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

	protected:
};

#endif
