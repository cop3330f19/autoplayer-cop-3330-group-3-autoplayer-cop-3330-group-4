//Playlist.cpp
//Group 4 Noah Richardson, Milik Bennett-Spence, Desjah Thompson, Terik Hamilton
//04/26/20
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Playlist.h"
#include "Song.h"
#include "StringHelper.h"

using namespace std;

//Default Mode for playlist
char Playlist::option = 'N'; 

//Add song by pushing it back in the playlist vector
void Playlist::addSong(Song &s1)
{
    listOfSongs.push_back(s1); 
}

//Delete song from playlist vector
void Playlist::deleteSong(Song &deletesong)
{
    bool valid;
    valid = false;
    for (int iterator = 0; iterator < listOfSongs.size(); iterator++)
    {
        if (listOfSongs[iterator] == deletesong)
        {
            valid = true;
            listOfSongs.erase(listOfSongs.begin() + iterator);
        }
    }
}

//Return songs for playlist
vector<Song> Playlist::getSong()
{
    return listOfSongs;
}

//This intersect the playlist to find similarities and return a new playlist
Playlist Playlist::intersectPlaylist(Playlist &p2)
{
    Playlist result;
    bool valid;
    vector<Song> temp = p2.getSong();

    valid = false;

    for (int iterator = 0; iterator < listOfSongs.size(); iterator++) 
    {                                                                 
        for (int forLoopIterator = 0; forLoopIterator < temp.size(); forLoopIterator++)
        {
            if (listOfSongs[iterator] == temp[forLoopIterator] && search(result.getSong(), listOfSongs[iterator]))
                valid = true;
            result.addSong(listOfSongs[iterator]);
        }
    }
    return result;
}
//Linear search through song vector
bool Playlist::search(vector<Song> b, Song &g) 
{
    bool valid;

    valid = false;
    for (int iterator = 0; iterator < b.size(); iterator++)
        if (b[iterator] == g)
            valid = true;
    return valid;
}

//merge one playlist with another
Playlist operator+(Playlist &p1, Playlist &p2)
{
    Playlist merge;
    merge = p1;
    bool valid;
    vector<Song> temp = p2.getSong();

    valid = false;

    for (int iterator = 0; iterator < temp.size(); iterator++)
    {

        valid = true;

        merge.addSong(temp[iterator]);
    }
    return Playlist(merge);
}

//Add songs to specified playlist
Playlist operator+(Playlist &p1, Song &s1)
{
    Playlist a1;
    a1 = p1;
    a1.addSong(s1);
    return Playlist(a1);
}

//Delete song from specified playlist
Playlist operator-(Playlist &p1, Song &s1)
{
    Playlist d1;
    d1 = p1;
    d1.deleteSong(s1);
    return d1;
}

ostream &operator<<(ostream &os, const Playlist &p1)
{
    for (int iterator = 0; iterator < p1.listOfSongs.size(); iterator++)
    {
        os << p1.listOfSongs[iterator];
    }
    return os;
}

//Play the current song
void Playlist::play() 
{
    if (option == 'N' || option == 'n')
    {
        currentSongInPlaylist++;
        if (currentSongInPlaylist < listOfSongs.size())
            cout << listOfSongs[currentSongInPlaylist] << endl;
        else

            cout << "This is the end of the plalist." << endl;
    }
    else if (option == 'R' || option == 'r')
    {
        cout << listOfSongs[currentSongInPlaylist] << endl;
    }
    else if (option == 'L' || option == 'l')
    {
        currentSongInPlaylist++;
        if (currentSongInPlaylist > listOfSongs.size())
            currentSongInPlaylist = 0;
        cout << listOfSongs[currentSongInPlaylist] << endl;
    }
}

//Read charater and change mode to
void Playlist::mode(char option)
{
    Playlist::option = option;
}

//set the playlist name
void Playlist::setPName(string pname)
{
    playlistName = pname;
}

//get playlist name
string Playlist::getPlaylistname()
{
    return playlistName;
}

//record what is in -> "" <-
Playlist::Playlist()
{
    playlistName = "";
}

//
Playlist::Playlist(string name)
{
    setPName(name);
    string play_listname = name + ".playlist";
    play_listname = StringHelper::stou(play_listname);

    fstream in;
    in.open(play_listname.c_str(), ios::in);
    Song s;
    int k = 0;
    while (in >> s)
    {
        listOfSongs.push_back(s);
    }
    in.close();
}
