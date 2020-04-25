
#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "Song.h"

#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>

class Playlist
{
private:
    std::vector<Song> listOfSongs;
    int currentSongInPlaylist;
    std::string playlistName;
    static char option;

public:
    Playlist();
    Playlist(std::string);

    void addSong(Song &);
    void deleteSong(Song &);
    Playlist intersectPlaylist(Playlist &);
    bool search(std::vector<Song>, Song &);
    friend Playlist operator+(Playlist &, Playlist &);
    friend Playlist operator+(Playlist &, Song &);
    friend Playlist operator-(Playlist &, Song &);
    friend std::ostream &operator<<(std::ostream &, const Playlist &);
    void play();
    static void mode(char);
    std::vector<Song> getSong();
    void setPName(std::string);
    std::string getPlaylistname();
};
#endif
