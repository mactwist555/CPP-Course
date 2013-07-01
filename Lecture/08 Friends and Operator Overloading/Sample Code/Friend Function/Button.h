#ifndef _BUTTON
#define _BUTTON

#include <string>
using namespace std;

class Button
{
	public:
	void Setup( const string& text, int width, int height );

	friend void Draw( const Button& button );

	private:
	string m_text;
	int m_width, m_height;
};

#endif
