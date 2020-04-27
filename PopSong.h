//
// Created by Cameron Hudson on 4/4/20.
//
#ifndef BL_CH_CW_JS_FINAL_PROJECT_Graphics_SONG_H
#define BL_CH_CW_JS_FINAL_PROJECT_Graphics_SONG_H

#include <string>
#include <vector>
using namespace std;

class Song {
protected:
    string songName;
    double songLength;
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

    virtual ~Song() = default;

    explicit Song(string name, double length, string lyrics);

    // Getters
    virtual string getSongName();
    virtual int getSongLength();
    virtual int getUniqueWords();
    virtual double getUniqueWordsPerSec();
    virtual string getLyrics();
    virtual int getTotalWordCount();

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

#endif //BL_CH_CW_JS_FINAL_PROJECT_MPL_SONG_H
