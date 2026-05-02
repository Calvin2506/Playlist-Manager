#ifndef SONG_H // Preprocessor directive to prevent multiple inclusions
#define SONG_H
#include <iostream>
#include <string>
using namespace std;
class Song{
    private:
        string title;
        string artist;
        string genre;
        float duration;
    public:
        Song();
        Song(string title, string artist,string genre ,float duration);
        string getTitle() const;
        string getArtist() const;
        string getGenre() const;
        float getDuration() const;
        void setTitle(const string& title);
        void setArtist(const string& artist);
        void setGenre(const string& genre);
        void setDuration(float duration);
        void displaySong() const;

};
#endif
