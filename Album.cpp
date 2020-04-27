//
// Created by Brandon Lee
//

#include "Album.h"

Album::Album() : name("missing"), artist("Alex Doe"), numSongs(0), rap(true){
}

Album::Album(string title, string artist, map<string, unique_ptr<Song>>& songMap, bool rap) {
    strReplace(artist, '-', ' ');
    strReplace(title, '-', ' ');
    this->artist = artist;
    this->name = title;
    this-> rap = rap;
    numSongs = trackList.size();
}

void Album::setTrackList(map<string, unique_ptr<Song>>& songMap){
    if (rap) {
        for( auto const& [key, val] : songMap )
        {
            trackList.insert({key, make_unique<RapSong>(RapSong(val->getSongName(), val->getIndex(), val->getSongLength(), val->getLyrics()))});
        }
    } else {
        for( auto const& [key, val] : songMap )
        {
            trackList.insert({key, make_unique<RapSong>(PopSong(val->getSongName(), val->getIndex(), val->getSongLength(), val->getLyrics(), val->getPopularityScore()))});
        }
    }
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

map<string, unique_ptr<Song>>& Album::getTrackList() {
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

// global functions
map<string,unique_ptr<Song>> readFromFolder(string folder, bool rap) {
    map<string,unique_ptr<Song>> album;
    unique_ptr<RapSong> rapSong = make_unique<RapSong>(RapSong());
    // iterate over directory (we can nest this to do multiple albums
    for(auto& p: fs::recursive_directory_iterator(folder)) {
        if (p.path() != "DS.Store") {
            RapSong song;
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
            if (rap){
                album.insert({songName, make_unique<RapSong>(RapSong("hi", 0, 0, content))});
            } else {
                album.insert({songName, make_unique<PopSong>(PopSong("hi", 0, 0, content, 0))});
            }
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