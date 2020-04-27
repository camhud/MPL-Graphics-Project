//
// Created by Brandon Lee
//

#ifndef BL_CH_CW_JS_FINAL_PROJECT_MPL_ALBUM_H
#define BL_CH_CW_JS_FINAL_PROJECT_MPL_ALBUM_H
#include <string>
#include <vector>
#include "Song.h"
#include <map>
#include <filesystem>
#include <fstream>
using namespace std;
namespace fs = filesystem;

class Album{
private:
    vector<Song> trackList;
    string name;
    string artist;
    int numSongs;

public:
    Album();
    Album(string title, string artist, map<string,string> songMap, map<string,double> lengthMap);

    //Setters Here
    void setTrackList(vector<Song> trackList);
    void setName(string name);
    void setArtist(string artist);
    void setNumSongs(int numSongs);

    // Getters Here
    vector<Song> getTrackList() const;
    string getName() const;
    string getArtist() const;
    int getNumSongs() const;

    /* Calculates the mean unique words per second of the songs in the tracklist
     * Requires: nothing
     * Modifies: meanUniqueWordsPerSec
     * Effects: loops through and gets the uniqueWordsPerSec of each song in tracklist, calculates avg and sets field equal to the average
     */
    double getMeanUniqueWordsPerSec();

    /* Calculates the sd unique words per second of the songs in the tracklist
     * Requires: nothing
     * Modifies: sdUniqueWordsPerSec
     * Effects: loops through and gets the uniqueWordsPerSec of each song in tracklist, calculates sd and sets field equal to the average
     */
    double getSDUniqueWordsPerSec();
};

// global functions
map<string,string> readFromFolder(string folder);

void strReplace(string& word, char old, char newCh);

#endif //BL_CH_CW_JS_FINAL_PROJECT_MPL_ALBUM_H
