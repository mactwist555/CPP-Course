#ifndef _ACCOUNT
#define _ACCOUNT

#include <string>
#include <vector>
using namespace std;

#include "Post.hpp"

class IAccount
{
    public:
//    Post& operator[]( const int index );
//    virtual void CreateNewPost() = 0;
//    virtual void DisplayLatestPost() = 0;
    virtual string AccountType() = 0;

    string GetUsername()                    { return m_username; }
    void SetUsername( const string& val )   { m_username = val; }

    void AddPost( Post* ptrPost );

    protected:
    string m_username;
    vector<Post*> m_postPtrs;
};

class UserAccount : public IAccount
{
    public:
//    virtual void CreateNewPost();
//    virtual void DisplayLatestPost();
    virtual string AccountType() { return "USER"; }
};

class AdminAccount : public IAccount
{
    public:
//    virtual void CreateNewPost();
//    virtual void DisplayLatestPost();
    virtual string AccountType() { return "ADMIN"; }
};

class AdAccount : public IAccount
{
    public:
//    virtual void CreateNewPost();
//    virtual void DisplayLatestPost();
    virtual string AccountType() { return "ADVERT"; }

    float GetBalance()              { return m_balance; }
    void SetBalance( float val )    { m_balance = val; }

    private:
    float m_balance;    // Posts from Ad accounts will show up only if they have a balance to pay for the ad
};

#endif
