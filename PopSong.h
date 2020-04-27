//
// Created by Cameron Hudson on 4/4/20.
//
#ifndef BL_CH_CW_JS_FINAL_PROJECT_Graphics_SONG_H
#define BL_CH_CW_JS_FINAL_PROJECT_Graphics_SONG_H

#include <string>
#include <vector>
#include "SongV2.h"
using namespace std;

class PopSong: public Song {
protected:
    int popularity;

public:
// Constructor
    PopSong();

    explicit PopSong(string name, double length, string lyrics, int popularityScore);

    //getter
    int getPopularityScore() const;

    //setter
    void setPopularityScore(int popularityScore) const;

    // Requires: nothing
    // Modifies: nothing
    // Effects: takes popularity and divides it by length of song
    double calculateUniqueStat() override;
};


#endif //BL_CH_CW_JS_FINAL_PROJECT_Graphics_SONG_H
