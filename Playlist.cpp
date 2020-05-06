//
//  Playlist.cpp
//  PlaylistDriver
//
//  Created by Ayushi Tiwari on 2020-01-14.
//  Copyright © 2020 Ayushi Tiwari. All rights reserved.
//

#include <iostream>
using namespace std;

#include <math.h>
using namespace std;

#include <cmath>
using namespace std;

#include "Playlist.h"

Playlist:: Playlist(const int& size_p) {
    size= size_p;
    songs = new string[size];
    }

void Playlist:: AddSong(string TitleArtist) {

    for (int i = 0; i < NumSongs; i++){
        if ((TitleArtist.compare(songs[i]) == 0) || ( NumSongs >= size)) {
            cout << "can not insert " << TitleArtist;
            flag += 1;
            break;
        }
}
    
    if (flag == 0) {
        songs[NumSongs] = TitleArtist;
        NumSongs++;
        cout << "success";
    }
    flag = 0;
}

void Playlist:: play(int i) {
    if (i > NumSongs) {
        cout << "can not play " << i;
    }
    else {
        cout << "played " << i << " " << songs[i - 1];
    }
}

void Playlist:: erase(int n) {
    if (n > NumSongs) {
        cout << "can not erase " << n;
    }
    else {
        songs[n - 1] = "";
        for(int i = n - 1; i < NumSongs; i++) {
            songs[i] = songs[i + 1];
            }
        songs[NumSongs] = "";
        cout << "success";
        NumSongs += -1;
    }
}

Playlist:: ~Playlist() {
    delete [] songs;
}
