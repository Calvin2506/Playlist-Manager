#include "../include/Playlist.h"

void Playlist::addSong(const Song& song){
    songs.push_back(song);
}

void Playlist::removeSong(const string& title){
    for (auto it = songs.begin(); it != songs.end(); ++it) {
        if (it->getTitle() == title) {
            songs.erase(it);
            cout << "Song removed successfully.\n";
            return;
        }
    }

    cout << "Song not found in playlist.\n";
}

void Playlist::displayPlaylist() const{
    if(songs.empty()){
        cout<<"Playlist is empty. Add songs to continue.\n";
        return;
    }
    for(size_t i=0;i<songs.size();i++){
        cout<<i+1<<". ";
        songs[i].displaySong();
    }
}

int Playlist::searchSong(const string& title) const{
    for(size_t i=0;i<songs.size();i++){
        if(songs[i].getTitle()==title){
            return static_cast<int>(i);
        }
    }

    return -1;
}

void Playlist::sortSongs(){
    // STL sort uses an efficient hybrid sorting strategy internally.
    sort(songs.begin(),songs.end(),[](const Song& a, const Song& b){
        return a.getTitle() < b.getTitle();
    });
}

void Playlist::saveToFile(const string& filename) const{
    ofstream outFile(filename);
    if(!outFile){
        cout<<"Error opening file for writing.\n";
        return;
    }
    for(const Song& song:songs){
        outFile<<song.getTitle()<<","<<song.getArtist()<<","<<song.getGenre()<<","<<song.getDuration()<<"\n";
    }
    outFile.close();
}

void Playlist::loadFromFile(const string& filename) {
    ifstream inFile(filename);
    if(!inFile){
        cout<<"No previous playlist file found.\n";
        return;
    }
    songs.clear();
    string line;
    while(getline(inFile,line)){
        if (line.empty()) {
            continue;
        }

        size_t firstComma = line.find(',');
        size_t secondComma = line.find(',', firstComma + 1);
        size_t thirdComma = line.find(',', secondComma + 1);

        if(firstComma == string::npos || secondComma == string::npos || thirdComma == string::npos){
            cout << "Skipping invalid line in playlist file: " << line << endl;
            continue;
        }

        string title = line.substr(0, firstComma);
        string artist = line.substr(firstComma + 1, secondComma - firstComma - 1);
        string genre = line.substr(secondComma + 1, thirdComma - secondComma - 1);
        
        try {
            float duration = stof(line.substr(thirdComma + 1));
            songs.push_back(Song(title, artist, genre, duration));
        } catch (const exception&) {
            cout << "Skipping line with invalid duration: " << line << endl;
        }
    }
    inFile.close();
}

vector<Song>& Playlist::getSongs(){
    return songs;
}

const vector<Song>& Playlist::getSongs() const{
    return songs;
}

void Playlist::sortSongsByDuration(){
    sort(songs.begin(),songs.end(),[](const Song& a, const Song& b){
        return a.getDuration() < b.getDuration();
    });
}

void Playlist::playSong(int index) const{
    if(index < 0 || index >= static_cast<int>(songs.size())){
        cout<<"Invalid song number.\n";
        return;
    }
    cout<<"Now playing: ";
    songs[index].displaySong();
}
