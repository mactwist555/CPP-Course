#ifndef _DOCUMENT
#define _DOCUMENT

#include <string>
#include <fstream>
#include <vector>
using namespace std;

// Document Interface
class IDocument
{
    public:
    virtual void Load( const string& filename ) = 0;
    virtual void Save( const string& filename ) = 0;
    virtual void GetInput() = 0;
    virtual ofstream& Display( ofstream& out ) = 0;
};

// Implementations of Documents

class TextDocument : public IDocument
{
    public:
    virtual void Load( const string& filename );
    virtual void Save( const string& filename );
    virtual ofstream& Display( ofstream& out );
    virtual void GetInput();

    void SetContent( const string& content );

    private:
    string m_content;
};

struct Element
{
    string html;
};

class WebDocument : public IDocument
{
    public:
    virtual void Load( const string& filename );
    virtual void Save( const string& filename );
    virtual ofstream& Display( ofstream& out );
    virtual void GetInput();

    void AddElement( const string& element );

    private:
    void OutputHeader( ofstream& out );
    void OutputFooter( ofstream& out );

    vector<Element> m_elements;
};

class CsvDocument : public IDocument
{
    public:
    virtual void Load( const string& filename );
    virtual void Save( const string& filename );
    virtual ofstream& Display( ofstream& out );
    virtual void GetInput();

    void AddRow( const string& row );

    private:
    vector<string> m_rows;
};

#endif
