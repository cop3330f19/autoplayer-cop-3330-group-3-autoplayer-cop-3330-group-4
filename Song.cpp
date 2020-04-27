//Song.cpp
// Group 4 Noah Richardson, Milik Bennett-Spence, Desjah Thompson, Terik Hamilton
// 04/26/20
//Allow users to create new named playlist, view all the playlists, merge (intersect) exisiting playlists into a new list, and play a playlist.
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Song.h"
#include "Playlist.h"
#include "StringHelper.h"

using namespace std;

//
Song::Song()
{
    title = "";
    artist = "";
    album = "";
    length = 0;
    year = 0;
}

Song::Song(string title, string artist, string album, int length, int year)
{
    set(title, artist, album, length, year);
}

void Song::set(string title, string artist, string album, int length, int year)
{
    this->title = title;
    this->artist = artist;
    this->album = album;
    this->length = length;
    this->year = year;
}

ostream &operator<<(ostream &os, const Song &song)
{
    os << song.title << " " << song.artist << " " << song.album << " " << song.year << " " << song.length; 
    return os;
}

ofstream &operator<<(ofstream &os, const Song &song)
{
    os << song.title << "," << song.artist << "," << song.album << "," << song.year << "," << song.length; 
    return os;
}

//get input from playlist files
fstream &operator>>(fstream &is, Song &song)
{
    string placeholder;

    getline(is, song.title, ',');
    getline(is, song.artist, ',');
    getline(is, song.album, ',');
    getline(is, placeholder, ',');
    song.year = atoi(placeholder.c_str());
    getline(is, placeholder);
    song.length = atoi(placeholder.c_str());
  
    return is;
}

//output song info from playlist file
istream &operator>>(istream &is, Song &song)
{
    cout << "Song Details \n";
    cout << "Title: \n";
    getline(is, song.title);
    cout << "Artist: \n";
    getline(is, song.artist);
    cout << "Album: \n";
    getline(is, song.album);
    cout << "Year: \n";
    is >> song.year;
    cout << "Length (in seconds): \n";
    is >> song.length;
    return is;
}

bool operator==(const Song &lhs, const Song &rhs)
{
    return (lhs.title == rhs.title && lhs.artist == rhs.artist); 
}
