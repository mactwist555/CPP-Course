#ifndef _WEBPAGE
#define _WEBPAGE

#include <string>
#include <fstream>

// Abstract Class
class Webpage
{
	public:
	Webpage( const string& filename );
	virtual ~Webpage();

	// Pure Virtual Functions
	virtual void WriteLine( const string& text ) = 0;
	virtual void BeginDocument() = 0;
	virtual void EndDocument() = 0;

	protected:
	ofstream m_outfile;
};

Webpage::Webpage( const string& filename )
{
	m_outfile.open( filename.c_str() );
	cout << "Opened \"" << filename << "\"" << endl;
}

Webpage::~Webpage()
{
	m_outfile.close();
	cout << "Closed file" << endl;
}

/* BASIC WEBPAGE ************************************************/

class BasicWebpage : public Webpage
{
	public:
	BasicWebpage( const string& filename );
	virtual ~BasicWebpage();

	virtual void WriteLine( const string& text );
	virtual void BeginDocument();
	virtual void EndDocument();
};

BasicWebpage::BasicWebpage( const string& filename )
	: Webpage( filename )
{
	BeginDocument();
}

BasicWebpage::~BasicWebpage()
{
	EndDocument();
}

void BasicWebpage::WriteLine( const string& text )
{
	m_outfile << "<p>" << text << "</p>" << endl;
}

void BasicWebpage::BeginDocument()
{
	m_outfile << "<html><head><title>Webpage!</title></head><body>" << endl;
}

void BasicWebpage::EndDocument()
{
	m_outfile << "</body></html>" << endl;
}

/* STYLED WEBPAGE ************************************************/

class StyledWebpage : public Webpage
{
	public:
	StyledWebpage( const string& filename );
	virtual ~StyledWebpage();

	virtual void WriteLine( const string& text );
	virtual void BeginDocument();
	virtual void EndDocument();
};

StyledWebpage::StyledWebpage( const string& filename )
	: Webpage( filename )
{
	BeginDocument();
}

StyledWebpage::~StyledWebpage()
{
	EndDocument();
}

void StyledWebpage::WriteLine( const string& text )
{
	m_outfile << "<p>" << text << "</p>" << endl;
}

void StyledWebpage::BeginDocument()
{
	m_outfile << "<html><head><title>Webpage!</title>" << endl;
	m_outfile << "<style type='text/css'>" << endl;
	m_outfile << "body { background: #ede4a9; color: #452310; font-family: 'Garamond'; }" << endl;
	m_outfile << "p { font-size: 30px; }" << endl;
	m_outfile << "</style></head>" << endl;
	m_outfile << "<body>" << endl;
}

void StyledWebpage::EndDocument()
{
	m_outfile << "</body></html>" << endl;
}

#endif
