//
// Created by Brandon Lee
//

#include "Album.h"
#include <cmath>

Album::Album() : name("missing"), artist("Alex Doe"), numSongs(0){
    vector<Song> empty;
    trackList = empty;
}

Album::Album(string title, string artist, map <string, string> songMap, map<string,double> lengthMap) {
    strReplace(artist, '-', ' ');
    strReplace(title, '-', ' ');
    this->artist = artist;
    this->name = title;
    for (auto const &[key, val] : songMap)
    {
        string songName = key;
        strReplace(songName, '-', ' ');
        Song song = Song(songName, lengthMap[key], val);
        trackList.push_back(song);
    }
    numSongs = trackList.size();
}

void Album::setTrackList(vector<Song> trackList){
    Album::trackList = trackList;
}
void Album::setName(string name){
    Album::name = name;
}
void Album::setArtist(string artist){
    Album::artist = artist;
}
void Album::setNumSongs(int numSongs){
    Album::numSongs = numSongs;
}

vector<Song> Album::getTrackList() const{
    return trackList;
}
string Album::getName() const{
    return name;
}
string Album::getArtist() const{
    return artist;
}
int Album::getNumSongs() const{
    return numSongs;
}

double Album::getMeanUniqueWordsPerSec(){
    double sum = 0.0;
    for(Song song : trackList){
        sum += song.getUniqueWordsPerSec();
    }
    double average = sum/((double)trackList.size());
    return average;
}

double Album::getSDUniqueWordsPerSec(){
    double mean = this->getMeanUniqueWordsPerSec();
    double sum = 0;
    for(Song song : trackList){
        double difference = (song.getUniqueWordsPerSec() - mean);
        sum += (difference*difference);
    }
    double quotient = sum / ((double)trackList.size());
    return sqrt(quotient);
}

// global functions
map<string,string> readFromFolder(string folder) {
    map<string,string> album;
    // iterate over directory (we can nest this to do multiple albums
    for(auto& p: fs::recursive_directory_iterator(folder)) {
        if (p.path() != "DS.Store") {
            string filename = p.path().string();
            ifstream file;
            file.open(filename);
            // read full contents into single string
            string content((std::istreambuf_iterator<char>(file) ),(std::istreambuf_iterator<char>()));
            // String cleaning
            string garbage = folder + "/";
            string trash = ".txt";
            // find index of the . for .txt in filename
            int trashPos = filename.find(trash);
            // gets rid of folder path and .txt extension so we are left with song name, just spaces replaced with -'s
            string songName = filename.erase(trashPos, filename.size()).erase(0, garbage.size());
            // insert into map
            strReplace(songName, '-', ' ');
            album.insert({songName, content});
            file.close();
        }
    }
    return album;
}

void strReplace(string& word, char old, char newCh) {
    while (word.find(old) != string::npos) {
        int index = word.find(old);
        word[index] = newCh;
    }
}