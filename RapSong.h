//
// Created by Cameron Hudson on 4/4/20.
//
#ifndef BL_CH_CW_JS_FINAL_PROJECT_Graphics_SONG_H
#define BL_CH_CW_JS_FINAL_PROJECT_Graphics_SONG_H

#include <string>
#include <vector>
#include "Song.h"
using namespace std;

class RapSong: public Song {

protected:
    int uniqueWords;
public:

    // Constructor
    RapSong();

    explicit RapSong(string name, double length, string lyrics);

    // uniqueWordCounter
    // Requires: nothing
    // Modifies: uniqueWord
    // Effects: number of unique words in the string vector
    void uniqueWordCounter();

    // Requires: nothing
    // Modifies: nothing
    // Effects: takes uniqueWords and divides it by length of song and returns it
    double calculateUniqueStat() override;
};

#endif //BL_CH_CW_JS_FINAL_PROJECT_Graphics_SONG_H
