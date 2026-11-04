#ifndef PLAYLIST_H
#define PLAYLIST_H
 
#include <iostream>
#include <string>
 
//NODE
class Node {
public:
    std::string song;
    Node *next = nullptr;
    Node *prev = nullptr;
};
 
//CREATE A NEW NODE
Node* createNode(std::string song) {
    Node *newNode = new Node;
    newNode->song = song;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}
 
//ADD A SONG
void addSong(Node *&head, std::string song) {
    Node *newNode = createNode(song);
 
    if (head == nullptr) {         // empty playlist, new node points to itself
        head = newNode;
        head->next = head;
        head->prev = head;
        return;
    }
 
    Node *tail = head->prev;       // last node is head's prev, since it's circular
 
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
}
 
//REMOVE A SONG BY NAME
void removeSong(Node *&head, std::string song) {
    if (head == nullptr) {
        std::cout << "Playlist is empty." << std::endl;
        return;
    }
 
    Node *temp = head;
 
    do {
        if (temp->song == song) {
            if (temp->next == temp) {          // only one song left
                head = nullptr;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                if (temp == head)              // removing the head, move head forward
                    head = temp->next;
            }
            delete temp;
            std::cout << "Removed \"" << song << "\" from the playlist." << std::endl;
            return;
        }
        temp = temp->next;
    } while (temp != head);
 
    std::cout << "\"" << song << "\" not found in playlist." << std::endl;
}
 
//PLAY ALL SONGS ONCE
void playAll(Node *head) {
    if (head == nullptr) {
        std::cout << "Playlist is empty." << std::endl;
        return;
    }
 
    Node *temp = head;
    int track = 1;
 
    do {
        std::cout << track << ". " << temp->song << std::endl;
        temp = temp->next;
        track++;
    } while (temp != head);   // stop once we loop back to the start
}
 
//GO TO NEXT SONG
void nextSong(Node *&current) {
    if (current == nullptr) return;
    current = current->next;
    std::cout << "Now playing: " << current->song << std::endl;
}
 
//GO TO PREVIOUS SONG
void previousSong(Node *&current) {
    if (current == nullptr) return;
    current = current->prev;
    std::cout << "Now playing: " << current->song << std::endl;
}
 
#endif
 