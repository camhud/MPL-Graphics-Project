//
// Created by Cameron Hudson on 4/4/20.
//
#include "PopSong.h"
#include <sstream>
#include <map>
#include <algorithm>

PopSong::PopSong() : Song(){
}

PopSong::PopSong(string name, double length, string lyrics, int popularityScore) : Song(name, length, lyrics) {
    this->popularity = popularityScore;
}

int PopSong::getPopularityScore() const {
    return popularity;
}

void PopSong::setPopularityScore(int popularityScore) const {
    popularity = popularityScore;
}

double PopSong::calculateUniqueStat(){
    double PopularityPerSec = ((double)(this->popularity))/(this->songLength);
    return PopularityPerSec;
}




