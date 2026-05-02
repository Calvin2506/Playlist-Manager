#include "../include/Song.h"
Song::Song(): title(""), artist(""), genre(""), duration(0.0) {}
Song::Song(string title, string artist ,string genre ,float duration){
    this->title=title;
    this->artist=artist;
    this->genre=genre;
    this->duration=duration;
}
string Song::getTitle() const{
    return title;
}
string Song::getArtist() const{
    return artist;
}
string Song::getGenre() const{
    return genre;
}
float Song::getDuration() const{
    return duration;
}
void Song::setTitle(const string& title){
    this->title = title;
}
void Song::setArtist(const string& artist){
    this->artist = artist;
}
void Song::setGenre(const string& genre){
    this->genre = genre;
}
void Song::setDuration(float duration){
    this->duration = duration;
}
void Song::displaySong() const{
    cout << "Title: " << title << ", Artist: " << artist << ", Genre: " << genre << ", Duration: " << duration << "s" << endl;
}
