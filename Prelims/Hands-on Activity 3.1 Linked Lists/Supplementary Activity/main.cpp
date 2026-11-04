#include "Playlist.h"
 
int main() {
    Node *head = nullptr;
 
    // create playlist with multiple songs
    addSong(head, "Yours to Keep");
    addSong(head, "California");
    addSong(head, "Confusing Girl");
    addSong(head, "Somewhere I Belong");
 
    std::cout << "=== Initial Playlist ===" << std::endl;
    playAll(head);
 
    std::cout << "\n=== Adding a song ===" << std::endl;
    addSong(head, "Romantic Lover");
    playAll(head);
 
    std::cout << "\n=== Removing a song ===" << std::endl;
    removeSong(head, "Somewhere I Belong");
    playAll(head);
 
    std::cout << "\n=== Next / Previous demo ===" << std::endl;
    Node *current = head;
    std::cout << "Now playing: " << current->song << std::endl;
    nextSong(current);
    nextSong(current);
    previousSong(current);
 
    return 0;
}
 