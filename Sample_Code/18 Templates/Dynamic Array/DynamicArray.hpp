#ifndef _DynamicArray
#define _DynamicArray

#include <string>
using namespace std;

template <typename T>
class DynamicArray
{
    public:
    DynamicArray()
    {
        cout << "Constructor" << endl;
        m_list = NULL;
        m_listSize = 0;
        m_elements = 0;
        CreateList();
    }

    ~DynamicArray()
    {
        cout << "Destructor" << endl;
        DestroyList();
    }

    void Insert( const T& value )
    {
        cout << "Insert \"" << value << "\"" << endl;
        if ( m_list == NULL )
        {
            CreateList();
        }
        else if ( m_listSize == m_elements )
        {
            ResizeList();
        }

        m_list[ m_elements ] = value;
        m_elements++;
    }

    void Display()
    {
        cout << "Display List" << endl;
        for ( int i = 0; i < m_elements; i++ )
        {
            cout << i << ": " << m_list[i] << endl;
        }
    }

    int GetSize()
    {
        return m_elements;
    }

    private:
    void CreateList()
    {
        cout << "Create List" << endl;
        if ( m_list == NULL )
        {
            m_list = new T[ 5 ];
            m_listSize = 5;
        }
    }

    void DestroyList()
    {
        cout << "Destroy List" << endl;
        if ( m_list != NULL )
        {
            delete [] m_list;
            m_list = NULL;
        }
    }

    void ResizeList()
    {
        cout << "Resize List" << endl;

        T* tempList = new T[ m_listSize * 2 ];

        // copy over
        for ( int i = 0; i < m_listSize; i++ )
        {
            tempList[i] = m_list[i];
        }

        // destroy old
        delete [] m_list;

        // update pointer
        m_list = tempList;
        m_listSize *= 2;
    }

    T*       m_list;
    int      m_listSize;
    int      m_elements;
};

#endif

