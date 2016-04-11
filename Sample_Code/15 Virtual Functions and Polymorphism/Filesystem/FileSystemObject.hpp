#ifndef _FILESYSTEMOBJECT
#define _FILESYSTEMOBJECT

#include <string>
using namespace std;

class IFileSystemObject
{
public:
    virtual void Open() = 0;

    string GetPath() { return m_path; }
    string GetName() { return m_name; }
    string GetExt() { return m_extention; }
    string GetFullPath() { return m_path + "/" + m_name; }
    void Setup( const string& path, const string& name )
    {
        m_path = path;
        m_name = name;
        m_extention = "";
    }

    protected:
    string m_path;          // /home/rejcx/TestDirectory/Music
    string m_name;          // Carefree
    string m_extention;     // mp3
    // update date
    // create date
    // read/write access
    // owner
};

class TextObject : public IFileSystemObject
{
    public:
    virtual void Open()
    {
        string command = "geany "
            + GetFullPath();
        system( command.c_str() );
    }
};

class MusicObject : public IFileSystemObject
{
    public:
    virtual void Open()
    {
        string command = "vlc "
            + GetFullPath();
        system( command.c_str() );
    }
};

class ImageObject : public IFileSystemObject
{
    public:
    virtual void Open()
    {
        string command = "eom "
            + GetFullPath();
        system( command.c_str() );
    }
};

#endif
