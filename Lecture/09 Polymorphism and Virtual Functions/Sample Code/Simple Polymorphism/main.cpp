#include <iostream>
#include <string>
using namespace std;

class Email
{
	public:
	Email()
	{
		static int counter = 0;
		m_messageText = "";
		// Store a letter in this message, starting at A.
		m_messageText = char( 65 + counter );
		counter++;
	}

	string m_messageText;
};

class EncryptedEmail : public Email
{
	public:
	EncryptedEmail() : Email() { ; }

	string m_publicKey;
};

int main()
{
	Email m_lstEmail[5];
	EncryptedEmail m_lstEncryptedEmail[5];

	Email* m_lstPtrEmail[10];


	// Assign pointer to all email addresses
	for ( int i = 0; i < 10; i++ )
	{
		if ( i < 5 )
		{
			m_lstPtrEmail[i] = &m_lstEmail[i];
		}
		else
		{
			m_lstPtrEmail[i] = &m_lstEncryptedEmail[i - 5];
		}
	}

	// Output email contents
	for ( int i = 0; i < 10; i++ )
	{
		cout << "Email contents: ";
		cout << m_lstPtrEmail[i]->m_messageText << endl;
	}

	return 0;
}
