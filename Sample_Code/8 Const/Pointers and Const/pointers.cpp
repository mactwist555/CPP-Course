#include <iostream>
#include <string>
using namespace std;

int main()
{
    string greeting = "Hello, there!";
    string question = "How are you?";

    const string* ptrText = &greeting;
    cout << *ptrText << endl;
    //*ptrText = "Hello, world!"; // invalid - cannot change value

    ptrText = &question;
    cout << *ptrText << endl;

    string answer = "I am fine, thanks!";
    string response = "And how are you?";

    string* const ptrText2 = &answer;
    //ptrText2 = &response; // invalid - cannot change address

    return 0;
}
