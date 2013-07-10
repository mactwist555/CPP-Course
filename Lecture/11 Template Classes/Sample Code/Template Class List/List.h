#ifndef _LIST
#define _LIST

template <typename T>
class List
{
    public:
    List( const string& name );
    ~List();

    void AddValue( const T& item );
    T& GetItem( int index );
    void OutputAll();

    protected:
    void Resize();

    T*      m_list;
    int     m_size;
    int     m_allocated;
    string  m_name;
};


template <typename T>
List<T>::List( const string& name )
{
    m_name = name;

    cout << "\n\n* CONSTRUCTOR FOR " << m_name << endl;

    m_allocated = 5;
    m_size = 0;
    cout << "Allocate space" << endl;
    m_list = new T[ m_allocated ];
}

template <typename T>
List<T>::~List()
{
    cout << "* DESTRUCTOR FOR " << m_name << endl;
    delete [] m_list;
}

template <typename T>
void List<T>::AddValue( const T& item )
{
    cout << "\n\n* AddValue in " << m_name << endl;

    if ( m_size == m_allocated )
    {
        Resize();
    }

    m_list[ m_size ] = item;
    cout << "\t Added item " << item << " at index " << m_size << endl;

    m_size++;
}

template <typename T>
T& List<T>::GetItem( int index )
{
    cout << "\n\n* GetItem in " << m_name << endl;

    if ( index >= 0 && index < m_size )
    {
        return m_list[ index ];
    }

    cout << "\t Could not find item at index " << index << endl;
    return NULL;
}

template <typename T>
void List<T>::OutputAll()
{
    cout << "\n\n* OutputAll in " << m_name << endl;

    for ( int i = 0; i < m_size; i++ )
    {
        cout << i << ".\t" << m_list[i] << endl;
    }
}

template <typename T>
void List<T>::Resize()
{
    cout << "\n\n* Resize in " << m_name << endl;
    cout << "\t Old Size: " << m_allocated << endl;

    // Temp storage
    T* tempList = new T[ m_allocated ];
    for ( int i = 0; i < m_size; i++ )
    {
        tempList[i] = m_list[i];
    }

    // Reallocate
    delete [] m_list;
    m_allocated += 10;
    m_list = new T[ m_allocated ];

    // Copy back
    for ( int i = 0; i < m_size; i++ )
    {
        m_list[i] = tempList[i];
    }
    delete [] tempList;

    cout << "\t New Size: " << m_allocated << endl;
}

#endif
