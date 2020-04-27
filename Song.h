//
// Created by Cameron Hudson on 4/4/20.
//
#ifndef BL_CH_CW_JS_FINAL_PROJECT_GRAPHICS_SONG_H
#define BL_CH_CW_JS_FINAL_PROJECT_GRAPHICS_SONG_H

#include <string>
#include <vector>
using namespace std;

class Song {
private:
    string songName;
    double songLength;
    int uniqueWords;
    double uniqueWordsPerSec;
    string lyrics;
    int totalWordCount;

    // split
    // Requires: string and a char
    // Modifies: Nothing
    // Effects: splits up a string into separate words of a vector
    vector<string> split(string str, char space);

public:

    // Constructor
    Song();
    Song(string name, double length, string lyrics);

    // Getters
    string getSongName();
    int getSongLength();
    int getUniqueWords();
    double getUniqueWordsPerSec();
    string getLyrics();
    int getTotalWordCount();

    // Setters
    void setSongName(string songName);
    void setSongLength(int songLength);
    void setLyrics(string lyrics);
    void setTotalWordCount(int totalWordCount);

    // uniqueWordCounter
    // Requires: nothing
    // Modifies: uniqueWord
    // Effects: number of unique words in the string vector
    void uniqueWordCounter();

    // calculateUniqueWordsPerSec
    // Requires: nothing
    // Modifies: uniqueWordPerSec
    // Effects: takes uniqueWords and divides it by length of song
    void calculateUniqueWordsPerSec();
};

#endif //BL_CH_CW_JS_FINAL_PROJECT_GRAPHICS_SONG_H
