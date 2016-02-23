#include "GameManager.hpp"

#include <fstream>
using namespace std;

GameManager::GameManager()
{
    m_genreList = NULL;
    m_platformList = NULL;
    m_gameList = NULL;

    m_genreCount = 0;
    m_gameCount = 0;
    m_platformCount = 0;

    LoadPlatforms();
    LoadGenres();
    LoadGames();
}

GameManager::~GameManager()
{
    if ( m_genreList != NULL )
    {
        delete [] m_genreList;
    }
}

void GameManager::DisplayGames()
{
    cout << endl << "GENRES" << endl;
    for ( int i = 0; i < m_genreCount; i++ )
    {
        cout << (i+1) << "\t" << m_genreList[i].name << endl;
    }

    cout << endl << "PLATFORMS" << endl;
    for ( int i = 0; i < m_platformCount; i++ )
    {
        cout << (i+1) << "\t" << m_platformList[i].name << endl;
    }

    cout << endl << "GAMES" << endl;

    for ( int g = 0; g < m_gameCount; g++ )
    {
        cout << (g+1) << "\t";
        m_gameList[g].Display();
        cout << endl;
    }
}

void GameManager::LoadGames()
{
    ifstream input( "games.txt" );

    string buffer, title;
    int genre, platform;

    input >> buffer >> m_gameCount;

    // Allocate array
    m_gameList = new Game[ m_gameCount ];

    for ( int i = 0; i < m_gameCount; i++ )
    {
        // Torchlight          GENRE 0     PLATFORM 0
        input >> title >> buffer >> genre >> buffer >> platform;
        m_gameList[i].Setup( title, &m_genreList[genre], &m_platformList[platform] );
    }

    cout << m_gameCount << " games" << endl;

    input.close();
}

void GameManager::LoadPlatforms()
{
    ifstream input( "platforms.txt" );

    string buffer;

    input >> buffer >> m_platformCount;

    // Allocate array
    m_platformList = new Platform[ m_platformCount ];

    for ( int i = 0; i < m_platformCount; i++ )
    {
        input >> buffer;
        input >> m_platformList[i].name;
    }

    cout << m_platformCount << " platforms" << endl;

    input.close();
}

void GameManager::LoadGenres()
{
    ifstream input( "genres.txt" );

    string buffer;

    input >> buffer >> m_genreCount;

    // Allocate array
    m_genreList = new Genre[ m_genreCount ];

    for ( int i = 0; i < m_genreCount; i++ )
    {
        input >> buffer;
        input >> m_genreList[i].name;
    }

    cout << m_genreCount << " platforms" << endl;

    input.close();
}

