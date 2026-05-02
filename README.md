# Smart Playlist Manager

A  C++ console-based music player project built using OOP,file handling, and a modular architecture.

## Project Summary

Smart Playlist Manager is a menu-driven console application that lets users manage and play songs from a persistent playlist. The project is designed to be beginner-friendly in code structure while still being strong enough for interview explanation.

Core capabilities:
- Add songs
- Delete songs
- View playlist
- Search songs by title
- Sort songs alphabetically
- Play, pause, go to next, and go to previous song
- Shuffle playlist
- Save playlist to file
- Auto-load playlist on startup

## Tech Concepts Used

- Language: C++
- OOP: classes, encapsulation, abstraction
- DSA: `vector`, `stack`, `queue`
- File handling: `ifstream`, `ofstream`
- STL algorithms: `sort`, `shuffle`
- Console UI: menu-driven interaction

## Folder Structure

```text
Smart-Playlist-Manager/
├── include/
│   ├── Song.h
│   ├── Playlist.h
│   └── MusicPlayer.h
├── src/
│   ├── Song.cpp
│   ├── Playlist.cpp
│   ├── MusicPlayer.cpp
│   └── main.cpp
├── data/
│   └── playlist.txt
├── docs/
├── build/
└── README.md
```

## Class Design

### 1. `Song`

Represents a single song object.

Attributes:
- `title`
- `artist`
- `genre`
- `duration`

Responsibilities:
- Store song details
- Provide getters and setters
- Display formatted song information

### 2. `Playlist`

Manages the collection of songs.

Responsibilities:
- Add and remove songs
- Display all songs
- Search songs by title
- Sort songs
- Save playlist to file
- Load playlist from file

### 3. `MusicPlayer`

Handles playback-related operations.

Responsibilities:
- Play a selected song
- Pause and resume playback
- Move to next song
- Move to previous song
- Shuffle the playlist

## OOP Concepts Used

### Encapsulation

Each class keeps its data private and exposes only required public methods.  
Example: `Song` hides its fields and provides getters/setters.

### Abstraction

Complex operations are hidden behind clear method names like:
- `addSong()`
- `loadFromFile()`
- `shufflePlaylist()`

The user of the class does not need to know the internal implementation.

### Inheritance

Inheritance is intentionally not forced into this project because there is no real parent-child relationship needed here. This is a good design decision to mention in interviews.

## DSA Concepts Used

### `vector<Song>`

Used in `Playlist` to store songs.

Why it was chosen:
- Dynamic size
- Easy traversal
- Works well with STL sorting
- Simpler and more practical than linked list for this use case

### `stack<Song>`

Used in `MusicPlayer` for previous songs.

Why it was chosen:
- Follows LIFO behavior
- Best fit for returning to the most recently played song

### `queue<Song>`

Used in `MusicPlayer` for upcoming songs.

Why it was chosen:
- Follows FIFO behavior
- Good match for sequential next-song flow

## File Handling

Playlist data is stored in:

```text
data/playlist.txt
```

Stored format:

```text
title,artist,genre,duration
```

Example:

```text
Believer,Imagine Dragons,Rock,3.2
Shape of You,Ed Sheeran,Pop,4.1
Blinding Lights,The Weeknd,Synth-pop,3.5
```

The program:
- loads data automatically at startup
- saves data on exit
- skips malformed lines safely instead of crashing

## How To Build

Use this command from the project root:

```bash
g++ -std=c++17 src/main.cpp src/Song.cpp src/Playlist.cpp src/MusicPlayer.cpp -Iinclude -o build/smart_playlist_manager
```

## How To Run

```bash
./build/smart_playlist_manager
```

## Menu Features

1. Add Song  
2. Delete Song  
3. View Playlist  
4. Search Song  
5. Sort Songs  
6. Play Song  
7. Pause/Resume Song  
8. Next Song  
9. Previous Song  
10. Shuffle Playlist  
11. Save Playlist  
12. Exit

## Scalability Ideas

Possible future improvements:
- Add login and multiple user playlists
- Add favorites and recently played songs
- Add playlist categories
- Add duration-based filtering
- Replace text file storage with database storage
- Build a GUI using Qt
