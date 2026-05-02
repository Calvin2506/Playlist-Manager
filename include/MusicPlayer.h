#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <iostream>
#include <stack>
#include <queue>
#include <cstdlib>
#include <ctime>
#include "Playlist.h"
using namespace std;

class MusicPlayer {
private:
    Playlist& playlist;
    stack<Song> previousSongs;
    queue<Song> upcomingSongs;
    int currentIndex;
    bool isPaused;

    void rebuildUpcomingQueue();
    int findSongIndex(const Song& song) const;

public:
    MusicPlayer(Playlist& playlist);

    void playSong(int index);
    void pauseSong();
    void nextSong();
    void previousSong();
    void shufflePlaylist();
};

#endif
