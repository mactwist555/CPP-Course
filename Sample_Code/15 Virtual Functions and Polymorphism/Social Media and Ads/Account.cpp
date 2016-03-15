#include "Account.hpp"

void IAccount::AddPost( Post* ptrPost )
{
    if ( ptrPost != NULL )
    {
        m_postPtrs.push_back( ptrPost );
    }
}

//void UserAccount::CreateNewPost()
//{
//}
//
//void UserAccount::DisplayLatestPost()
//{
//}

//Post& IAccount::operator[]( const int index )
//{
//    return m_posts[index];
//}
