#include <iostream>
#include <string>
#include "Song.h"

using namespace std;

int main()
{
    int index = 0;
    Song song;
    bool check;
    string title, artist, album, tempPlaylist;
    int year, song_in_seconds;

    int selection, selection1, selection3;
    char selection2;
    char control, control2;

    vector<string> play;

    openPlaylistFile("Playlist.list", play);

    cout << "AutoPlayer" << endl << endl;
    cout << "There are " << play.size() << " playlists availible to choose from." << endl;
    label1:
    cout << "1 - Open an exisiting playlist" << endl;
    cout << "2 - Create new list" << endl;
    cout << "3 - Exit" << endl;
    cout << "Enter your choice here: "; 
    cin >> selection;
    cout << endl;

    switch (selection)
    {
    case 1:
        cout << "Please select one of the following playlists:" << endl;
        for (int i = 0; i < play.size() ; i++)
        {
           cout << i + 1 << " " << play[i] << endl;
        }
        cout << "Selection: ";
        cin >> selection1;
        cout << endl;
        
        index = searchForPlaylist(selection1,play);
   
        Playlist p(play[index]);
        cout << "Current Song: " << p.getTitle() << endl;
        cout << "A - Add a song" << endl;
        cout << "D - Delete a song" << endl;
        cout << "P - Play a song" << endl;
        cout << "M - Set the mode" << endl;
        cout << "S - Show all songs" << endl;
        cout << "Q - Quit" << endl;
        cout << "Selection: ";
        cin >> control;
        cout << endl;
        switch(toupper(control))
        {
            case 'A': 
                cout << "Song Details" << endl;
                cout << "Title: ";
                cin >> title;
                cout << "Artist: ";
                cin >> artist;   
                cout << "Album: ";
                cin >> album;                         
                cout << "Year: ";
                cin >> year;
                cout << "Length (in seconds): ";
                cin >> song_in_seconds;
                song.set(title,artist,album,song_in_seconds,year);
                p.addSong(song);
                break;
            case 'D':
                cout << "Enter to delete: " << endl;
                cout << "Title: ";
                cin >> song;
                cout << "Artist: ";
                cin >> song;    
                check = p.deleteSong(song);
                if(check == true)
                    cout << "Song successfully deleted " << endl;
                else
                     cout << "Song not found in playlist" << endl;
                break;
            case 'M':
                label:
                cout << "Enter mode: " << endl;
                cout << setw(9) << right << "N - Normal " << endl;
                cout << setw(9) << "R - Repeat " <<endl;
                cout << setw(9) << "L - Loop " << endl;
                cout << "Selection: ";
                cin >> control2;
                    switch (toupper(selection2))
                    {
                    case 'N':
                        p.setMode(control2);
                        break;
                    case 'R':
                        p.setMode(control2);
                        break;
                    case 'L':
                        p.setMode(control2);
                        break;
                    default: goto label;
                        break;
                    }
            case 'P':
                    p.play();
                    break;
            case 'S':
                   p.printPlaylist();
                    break;
            case 'Q': goto label1;
                    break;
            default: 
                cout << "Invalid selection " << endl; 
                break; 
        }
    } 
    return 0;
}

const int countLinesInFile(string filename) 
{
    int count = 0;
    string line;
    ifstream file;
    file.open(filename.c_str());
    while (getline(file, line))
        count++;
    return count;
}


int searchForPlaylist(int selection, vector<string> & v)
{
    string playlist;
    if(selection == 1)
        playlist = "Country";
    else if(selection == 2)
        playlist = "90s_RnB";
    else if(selection == 3)
        playlist = "Country_RnB_Mix";
    else if(selection == 4)
        playlist = "Intersected_List";
    else if(selection == 5)
        playlist = "Rock_Anthems";

    for(int i = 0; i < v.size() ; i++)
    {
        if (playlist == v[i])
        {
            return i;
        }
    }
    return -1; 
}

void openPlaylistFile(string filename, vector <string> & v)
{
    string line;
    ifstream file;
    file.open(filename.c_str());
    while(file >> line)
        v.push_back(line);
}
//Recieved a lot of help here
