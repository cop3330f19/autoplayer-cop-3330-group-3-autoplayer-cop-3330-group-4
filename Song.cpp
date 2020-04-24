#include <iostream>
#include <string>
#include "Song.h"

Using namespce std;

Song::Song(){}

Song::Song(string title, string artist, string album, int length, int year)
{
  this->title = title;
  this->artist = artist;
  this->album = album;
  this->length = length;
  this->year = year;
}

Song::set(std::string title, std::string artist, std::string album, int length, int year)
{
	this->title = title;
	this->artist = artist;
	this->album = album;
	this->length = length;
	this->year = year;
}


std::istream& operator>>(std::istream& is, Song& song)
{
	cout << "Song Details" << endl;
	cout << "Title: ";
	getline(is,song.title);
	cout << "Artist: ";
	getline(is,song.artist);
	cout << "Album: ";
	getline(is,song.album);
	cout << "Year: ";
	is >> song.year;
	cout << "Length (in seconds): ";
	is >> song.length;
	
	return is;
}

fstream& operator>>(std::fstream& is, Song& song)
{
	string line,myString,myString2;
	while (getline(is,line))
	{
		stringstream ss(line);
		
		getline(ss,song.title,',');
		getline(ss,song.artist,',');
		getline(ss,song.album,',');
		getline(ss,myString,',');
		song.year = stoi(myString);
		getline(ss,myString2,',');
		song.length = stoi(myString2); 
	}
	return 0;
}  

