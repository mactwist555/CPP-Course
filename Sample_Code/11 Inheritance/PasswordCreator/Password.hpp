#ifndef PASSWORD_HPP
#define PASSWORD_HPP

#include <vector>
#include <string>
using namespace std;

class WeakPassword
{
    public:
    WeakPassword();
    string GetRandomPassword();

    protected:
    vector<string> m_wordList;
};

class MediumPassword : public WeakPassword
{
    public:
    MediumPassword();
    string GetRandomPassword(); // override the WeakPassword version

    protected:
    string SwapChar( char letter );
};

class HarderPassword : public MediumPassword
{
    public:
    HarderPassword();
    string GetRandomPassword();
};

#endif
