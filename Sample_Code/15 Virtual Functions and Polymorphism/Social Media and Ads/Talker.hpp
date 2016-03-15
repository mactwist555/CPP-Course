#ifndef _TALKER
#define _TALKER

#include <vector>
using namespace std;

#include "Localization.hpp"
#include "Account.hpp"
#include "Post.hpp"

class Talker
{
    public:
    Talker();
    ~Talker();

    void Run();

    private:
    // Menus
    void GetLanguage();
    void Login();
    void CreateAccount();
    void MainMenu();

    // Functionality
    void LoadAccounts();
    void SaveAccounts();
    void LoadPosts();
    void SavePosts();

    vector<IAccount*>   m_accounts;
    vector<Post*>       m_posts;
    Localization        m_local;
    IAccount*           m_currentUser;

    string m_accountFile;
    string m_postFile;

    bool m_done;
};

#endif
