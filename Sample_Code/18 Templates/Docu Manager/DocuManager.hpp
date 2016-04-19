#ifndef DOCUMANAGER_HPP
#define DOCUMANAGER_HPP

#include "Docs.hpp"

template <typename T>
class DocuManager
{
    public:
    void Add( const string& text )
    {
        m_doc.content.push_back( text );
    }

    void Save()
    {
        m_doc.Save();
    }

    private:
    T m_doc;
};

#endif
