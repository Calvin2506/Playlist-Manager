#ifndef PLAYLIST_H
#define PLAYLIST_H
#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include "Song.h"
using namespace std;
class Playlist{
    private:
        vector<Song> songs;
    public:
        void addSong(const Song& song);
        void removeSong(const string& title);
        void displayPlaylist() const;
        int searchSong(const string& title) const;
        void sortSongs();
        void sortSongsByDuration();
        void playSong(int index) const;
        void saveToFile(const string& filename) const;
        void loadFromFile(const string& filename);
        vector<Song>& getSongs();
        const vector<Song>& getSongs() const;
};
#endif
