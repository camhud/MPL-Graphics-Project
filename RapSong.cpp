//
// Created by Cameron Hudson on 4/4/20.
//
#include "Song.h"
#include <sstream>
#include <map>
#include <algorithm>

Song::Song() : songName("song"), songLength(60), uniqueWords(30), uniqueWordsPerSec(0.5) {
}

Song::Song(string name, double length, string lyrics) {
    this->songName = name;
    this->songLength = length;
    this->lyrics = lyrics;
    this->totalWordCount = split(lyrics, ' ').size();
    uniqueWordCounter();
    calculateUniqueWordsPerSec();
}

string Song::getSongName() {
    return songName;
}

int Song::getSongLength() {
    return songLength;
}

int Song::getUniqueWords() {
    return uniqueWords;
}

double Song::getUniqueWordsPerSec() {
    return uniqueWordsPerSec;
}

string Song::getLyrics() {
    return lyrics;
}

int Song::getTotalWordCount() {
    return totalWordCount;
}

void Song::setSongName(string songName) {
    this->songName = songName;
}

void Song::setSongLength(int songLength) {
    this->songLength = songLength;
}

void Song::setLyrics(string lyrics) {
    this->lyrics = lyrics;
}

void Song::setTotalWordCount(int totalWordCount) {
    this->totalWordCount = totalWordCount;
}

void Song::uniqueWordCounter() {
    // call split here
    vector<string> lyr = split(this->lyrics, ' ');
    map<string, int> mp;
    for (int i = 0; i < lyr.size(); ++i) {
        if(!mp.count(lyr[i]))
            mp.insert(make_pair(lyr[i], 1));
        else
            mp[lyr[i]]++;
    }
    int uniqueWordCount = 0;
    for (map<string, int> :: iterator p = mp.begin(); p != mp.end(); p++) {
        if (p->second == 1) {
            uniqueWordCount++;
        }
    }
    this->uniqueWords = uniqueWordCount;
}

// make private out of class field
vector<string> Song::split(string str, char space) {
    vector<string> internal;
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    str.erase(remove(str.begin(), str.end(), '.'), str.end());
    str.erase(remove(str.begin(), str.end(), ','), str.end());
    str.erase(remove(str.begin(), str.end(), '?'), str.end());
    str.erase(remove(str.begin(), str.end(), '!'), str.end());
    str.erase(remove(str.begin(), str.end(), ':'), str.end());
    str.erase(remove(str.begin(), str.end(), ';'), str.end());
    str.erase(remove(str.begin(), str.end(), '\''), str.end());
    
    stringstream ss(str); // Turn the string into a stream.
    string tok;
    while(getline(ss, tok, space)) {
        internal.push_back(tok);
    }
    return internal;
}

void Song::calculateUniqueWordsPerSec() {
    this->uniqueWordsPerSec = this->uniqueWords / this->songLength;
}





