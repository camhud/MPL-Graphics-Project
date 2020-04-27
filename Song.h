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
    int albumIndex;

public:

    // Constructor
    Song();

    virtual ~Song() = default;

    explicit Song(string name, int index, double length, string lyrics);

    // Getters
    virtual string getSongName() const;
    virtual double getSongLength() const;
    virtual string getLyrics() const;
    virtual int getTotalWordCount() const;
    virtual int getIndex() const;

    // Setters
    void setSongName(string songName);
    void setSongLength(int songLength);
    void setLyrics(string lyrics);
    void setTotalWordCount(int totalWordCount);
    void setIndex(int index);

    virtual double calculateUniqueStat() = 0;
};

// split
// Requires: string and a char
// Modifies: Nothing
// Effects: splits up a string into separate words of a vector
vector<string> split(string str, char space);

#endif //BL_CH_CW_JS_FINAL_PROJECT_Graphics_SONG_H
