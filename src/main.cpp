#include <iostream>
#include <limits>
#include <string>
#include "../include/Song.h"
#include "../include/Playlist.h"
#include "../include/MusicPlayer.h"

using namespace std;

void showMenu() {
    cout << "\n===== Smart Playlist Manager =====\n";
    cout << "1. Add Song\n";
    cout << "2. Delete Song\n";
    cout << "3. View Playlist\n";
    cout << "4. Search Song\n";
    cout << "5. Sort Songs\n";
    cout << "6. Play Song\n";
    cout << "7. Pause/Resume Song\n";
    cout << "8. Next Song\n";
    cout << "9. Previous Song\n";
    cout << "10. Shuffle Playlist\n";
    cout << "11. Save Playlist\n";
    cout << "12. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Playlist playlist;
    playlist.loadFromFile("data/playlist.txt");
    MusicPlayer player(playlist);

    cout << "Playlist loaded. Welcome to Smart Playlist Manager.\n";

    int choice;
    do {
        showMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a number between 1 and 12.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                string title, artist, genre;
                float duration;

                cout << "Enter title: ";
                getline(cin, title);
                cout << "Enter artist: ";
                getline(cin, artist);
                cout << "Enter genre: ";
                getline(cin, genre);

                cout << "Enter duration: ";
                cin >> duration;

                if (cin.fail() || duration <= 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid duration. Please enter a positive number.\n";
                    break;
                }

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                Song song(title, artist, genre, duration);
                playlist.addSong(song);
                cout << "Song added successfully.\n";
                break;
            }

            case 2: {
                string title;
                cout << "Enter title to delete: ";
                getline(cin, title);
                playlist.removeSong(title);
                break;
            }

            case 3:
                cout << "\nCurrent Playlist:\n";
                playlist.displayPlaylist();
                break;

            case 4: {
                string title;
                cout << "Enter title to search: ";
                getline(cin, title);

                int index = playlist.searchSong(title);
                if (index != -1) {
                    cout << "Song found at position: " << index + 1 << endl;
                } else {
                    cout << "Song not found.\n";
                }
                break;
            }

            case 5:
                playlist.sortSongs();
                cout << "Playlist sorted alphabetically by title.\n";
                break;

            case 6: {
                int index;

                cout << "Enter song number to play: ";
                cin >> index;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid song number.\n";
                    break;
                }

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                player.playSong(index - 1);
                break;
            }

            case 7:
                player.pauseSong();
                break;

            case 8:
                player.nextSong();
                break;

            case 9:
                player.previousSong();
                break;

            case 10:
                player.shufflePlaylist();
                break;

            case 11:
                playlist.saveToFile("data/playlist.txt");
                cout << "Playlist saved successfully.\n";
                break;

            case 12:
                playlist.saveToFile("data/playlist.txt");
                cout << "Playlist saved. Exiting safely...\n";
                break;

            default:
                cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 12);

    return 0;
}
