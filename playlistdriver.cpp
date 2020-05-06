//
//  playlistdriver.cpp
//  PlaylistDriver
//
//  Created by Ayushi Tiwari on 2020-01-16.
//  Copyright © 2020 Ayushi Tiwari. All rights reserved.
//

#include <iostream>
using namespace std;

#include <string>
using namespace std;

#include <cmath>
using namespace std;


#include "Playlist.h"

int main() {
    string line;
    getline(std::cin,line);
    int params;
    int end_command;
    
    end_command = 1;
    params = stoi(line.substr(end_command + 1));
    Playlist song1(params);
    cout << "success";
    
    while (!cin.eof()) {
        getline(std::cin, line);
        string cmd;
        string titleArtist;
        cmd  = line.substr(0,1);
        
        cout << endl;

        if (cmd == "i") {
            titleArtist = line.substr(end_command + 1);
            song1.AddSong(titleArtist);
        }
        
        else if (cmd == "p") {
            params = stoi(line.substr(end_command + 1));
            song1.play(params);
        }
        
        else if (cmd == "e") {
            params = stoi(line.substr(end_command + 1));
            song1.erase(params);
        }
       
    }
    
    return 0;
}

