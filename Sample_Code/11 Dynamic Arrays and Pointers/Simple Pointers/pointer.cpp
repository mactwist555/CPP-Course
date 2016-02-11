#include <iostream>
#include <string>
using namespace std;

class Document
{
public:
    Document()
    {
        m_title = m_content = "";
    }

    void SetTitle( const string& title )
    {
        m_title = title;
    }

    void SetContent( const string& content )
    {
        m_content = content;
    }

    string GetContent()
    {
        return m_content;
    }

    string GetTitle()
    {
        return m_title;
    }

private:
    string m_content;
    string m_title;
};



int main()
{
    Document documents[10];
    Document* ptrCurrentDoc;

    while ( true )
    {
        cout << endl << "DOCUMENT LIST" << endl;
        for ( int i = 0; i < 10; i++ )
        {
            cout << i << ". " << documents[i].GetTitle() << endl;
        }

        cout << "Which document do you want to edit? ";

        int index;
        cin >> index;

        while ( index < 0 || index >= 10 )
        {
            cout << "Invalid choice. Try again: ";
            cin >> index;
        }

        // Utilize pointers
        ptrCurrentDoc = &(documents[index]);

        string text;

        cout << "Item #" << index << endl;

        cout << "Title: ";
        cin.ignore();
        getline( cin, text );
        ptrCurrentDoc->SetTitle( text );

        cout << "Content: ";
        cin.ignore();
        getline( cin, text );
        ptrCurrentDoc->SetContent( text );
    }

    return 0;
}




