#ifndef _FILESYSTEMHANDLER
#define _FILESYSTEMHANDLER

#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "FileSystemObject.hpp"

class FileSystemHandler
{
    public:
    FileSystemHandler( const string& basePath, const string& baseDirFile );
    void DisplayAllFiles();
    void Open( int index );

    private:
    void ReadDirectory( const string& filePath, string prefix = "" );

    vector<IFileSystemObject*> m_files;
    string m_basePath;
};

void FileSystemHandler::Open( int index )
{
    m_files[index]->Open();
}

void FileSystemHandler::DisplayAllFiles()
{
    for ( int i = 0; i < m_files.size(); i++ )
    {
        cout << i << "\t" << m_files[i]->GetFullPath() << endl;
    }
}

FileSystemHandler::FileSystemHandler( const string& basePath, const string& baseDirFile)
{
    m_basePath = basePath;
    ReadDirectory( baseDirFile );
}

void FileSystemHandler::ReadDirectory( const string& filePath, string prefix )
{
    ifstream input( filePath.c_str() );

    string buffer;

    while ( input >> buffer )
    {
        if ( buffer.find( ".txt" ) != string::npos )
        {
            TextObject* txt = new TextObject;

            string path = m_basePath;
            if ( prefix != "" ) { path += "/" + prefix; }

            txt->Setup( path, buffer );
            m_files.push_back( txt );
        }
        else if ( buffer.find( ".mp3" ) != string::npos )
        {
            MusicObject* mus = new MusicObject;

            string path = m_basePath;
            if ( prefix != "" ) { path += "/" + prefix; }

            mus->Setup( path, buffer );
            m_files.push_back( mus );
        }
        else if ( buffer.find( ".png" ) != string::npos || buffer.find( ".jpg" ) != string::npos )
        {
            ImageObject* img = new ImageObject;

            string path = m_basePath;
            if ( prefix != "" ) { path += "/" + prefix; }

            img->Setup( path, buffer );
            m_files.push_back( img );
        }
        else
        {
            if ( filePath == "base.txt" )
            {
                ReadDirectory( buffer + ".txt", buffer );
            }
            else
            {
                string path = filePath;
                path = path.replace( filePath.size() - 4, filePath.size() - 1, "" );
                path = path + "-" + buffer + ".txt";

                cout << prefix << "\t" << buffer << endl;

                string pre = prefix;
                if ( pre != "" )
                {
                    pre += "/" + buffer;
                }

                ReadDirectory( path, pre );
            }
        }
    }

    input.close();
}

#endif
