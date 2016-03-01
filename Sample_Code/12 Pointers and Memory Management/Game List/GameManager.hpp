#ifndef _GAMEMANAGER
#define _GAMEMANAGER

#include "Game.hpp"
#include "Extras.hpp"

class GameManager
{
    public:
    GameManager();
    ~GameManager();

    void DisplayGames();

    int GetGenreCount()     { return m_genreCount; }
    int GetGameCount()      { return m_gameCount; }
    int GetPlatformCount()  { return m_platformCount; }

    private:
    void LoadGames();
    void LoadPlatforms();
    void LoadGenres();

    Genre* m_genreList;
    Platform* m_platformList;
    Game* m_gameList;

    int m_genreCount;
    int m_platformCount;
    int m_gameCount;
};

#endif
