//
//  Playlist.hpp
//  PlaylistDriver
//
//  Created by Ayushi Tiwari on 2020-01-14.
//  Copyright © 2020 Ayushi Tiwari. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


class Playlist {
    
    // class variables
    private:
    int size;
    int n; //position of a song in the list
    string *songs; //dynamically allocated array
    int NumSongs = 0;
    int flag = 0;
    
    // class functions
    public:

    //Sets the maximum size of song list (m)
    Playlist(const int& size_p);
    
    //Adds a song (i)
    void AddSong(string TitleArtist);
    
    //Plays song at position n (p)
    void play(int i);
    
    //Erases song at position n (e)
    void erase(int n);
    
    ~Playlist();
};



