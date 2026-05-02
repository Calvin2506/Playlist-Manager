#include "../include/MusicPlayer.h"
#include <algorithm>
#include <chrono>
#include <random>

MusicPlayer::MusicPlayer(Playlist& playlist):playlist(playlist),currentIndex(-1),isPaused(false){}

void MusicPlayer::rebuildUpcomingQueue() {
    queue<Song> emptyQueue;
    upcomingSongs = emptyQueue;

    const vector<Song>& songs = playlist.getSongs();
    for (int i = currentIndex + 1; i < static_cast<int>(songs.size()); i++) {
        upcomingSongs.push(songs[i]);
    }
}

int MusicPlayer::findSongIndex(const Song& song) const {
    const vector<Song>& songs = playlist.getSongs();

    for (int i = 0; i < static_cast<int>(songs.size()); i++) {
        if (songs[i].getTitle() == song.getTitle() &&
            songs[i].getArtist() == song.getArtist() &&
            songs[i].getGenre() == song.getGenre() &&
            songs[i].getDuration() == song.getDuration()) {
            return i;
        }
    }

    return -1;
}

void MusicPlayer::playSong(int index){
    const vector<Song>& songs = playlist.getSongs();

    if (index < 0 || index >= static_cast<int>(songs.size())) {
        cout << "Invalid song number.\n";
        return;
    }

    if (currentIndex != -1 && currentIndex != index) {
        previousSongs.push(songs[currentIndex]);
    }

    currentIndex = index;
    isPaused = false;
    rebuildUpcomingQueue();

    cout << "Playing song: ";
    songs[currentIndex].displaySong();
}

void MusicPlayer::pauseSong(){
    if(currentIndex==-1){
        cout<<"No song is currently playing."<<endl;
        return;
    }
    isPaused=!isPaused;
    if(isPaused){
        cout<<"Song paused: " << playlist.getSongs()[currentIndex].getTitle() << endl;
    } else {
        cout<<"Song resumed: " << playlist.getSongs()[currentIndex].getTitle() << endl;
    }
}

void MusicPlayer::nextSong(){
    const vector<Song>& songs = playlist.getSongs();

    if (songs.empty()) {
        cout << "Playlist is empty.\n";
        return;
    }

    if (currentIndex == -1) {
        playSong(0);
        return;
    }

    if (upcomingSongs.empty()) {
        cout << "No next song available." << endl;
        return;
    }

    previousSongs.push(songs[currentIndex]);
    Song next = upcomingSongs.front();
    upcomingSongs.pop();

    currentIndex = findSongIndex(next);
    if (currentIndex == -1) {
        cout << "Could not locate the next song in the playlist.\n";
        return;
    }

    isPaused = false;
    rebuildUpcomingQueue();

    cout << "Playing next song: ";
    songs[currentIndex].displaySong();
}

void MusicPlayer::shufflePlaylist(){
    vector<Song>& songs = playlist.getSongs();
    if (songs.empty()) {
        cout << "Cannot shuffle an empty playlist." << endl;
        return;
    }

    Song currentSong;
    bool hasCurrentSong = (currentIndex != -1);

    if (hasCurrentSong) {
        currentSong = songs[currentIndex];
    }

    unsigned seed=chrono::system_clock::now().time_since_epoch().count();
    default_random_engine engine(seed);
    shuffle(songs.begin(),songs.end(),engine);

    if (hasCurrentSong) {
        currentIndex = findSongIndex(currentSong);
        rebuildUpcomingQueue();
    }
    cout<<"Playlist shuffled successfully."<<endl;
}

void MusicPlayer::previousSong(){
    if (previousSongs.empty()) {
        cout << "No previous song available." << endl;
        return;
    }

    Song previous = previousSongs.top();
    previousSongs.pop();

    currentIndex = findSongIndex(previous);
    if (currentIndex == -1) {
        cout << "Could not locate the previous song in the playlist.\n";
        return;
    }

    isPaused = false;
    rebuildUpcomingQueue();

    cout << "Playing previous song: ";
    playlist.getSongs()[currentIndex].displaySong();
}
