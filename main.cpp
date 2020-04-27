#include <iostream>
#include <map>
#include <filesystem>
#include "Song.h"
#include "Album.h"
using namespace std;
namespace fs = filesystem;
#ifdef _WIN32
const string python = "python";
#else
const string python = "python3";
#endif

void getInput(string artist, string album, map<string,string>& songMap);

int main() {
    // root directory where everything will be stored
    string root = "albums";
    // creates directory if it doesnt exist
    if (!fs::exists(root)) {
        fs::create_directories(root);
    }

    string artist;
    string album;
    map<string,string> songMap;
    map<string, double> songLengths;

    getInput(artist, album, songMap);

    // validate that the album exists
    while (songMap.empty()) {
        cout << "It seems the album you typed in doesn't exist or has a typo." << endl;
        getInput(artist, album, songMap);
    }

    for (auto const &[key, val] : songMap)
    {
        double length;
        cout << "Please enter the length of " << key << " in seconds: ";

        while((!(cin >> length)) || length <= 0) {
            cout << "It seems you have entered an incorrect data type. Please enter the length of " << key << " in seconds: ";
            // Clear input stream
            cin.clear();

            // Discard previous input
            cin.ignore(123, '\n');
        }
        songLengths.insert({key, length});
    }
    Album owbum = Album(album, artist, songMap, songLengths);
    cout << "The mean unique words per second of your album is: " << owbum.getMeanUniqueWordsPerSec() << endl;
    cout << "The standard deviation of unique words per second of your album is: " << owbum.getSDUniqueWordsPerSec() << endl;
    fs::remove_all("albums");
    return 0;
}

void getInput(string artist, string album, map<string,string>& songMap){
    string root = "albums";
    cout << "Please enter the name of the album you would like to analyze: ";
    getline(cin, album);
    cout << "Please enter the artist whom the album is by: ";
    getline(cin, artist);
    strReplace(artist, ' ', '-');
    strReplace(album, ' ', '-');

    // run python script
    string command = python + " ../lyrics.py " + artist + " " + album;
    system(command.c_str());
    // get map where keys are song names and values are songs(one full string)
    songMap = readFromFolder(root + "/" + album + "_" + artist);
}