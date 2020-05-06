//
//  openhttest.cpp
//  openhttest
//
//  Created by Ayushi Tiwari on 2020-02-14.
//  Copyright © 2020 Ayushi Tiwari. All rights reserved.
//

#include <iostream>
using namespace std;

#include <string>
using namespace std;

#include <cmath>
using namespace std;

#include "openht.h"

int main() {
    string line;
    getline(std::cin,line);
    int params;
    int end_command = 1;
    params = stoi(line.substr(end_command + 1));
    hashTable directory1(params);
    cout << "success";
    
    while (!cin.eof()) {
        getline(std::cin, line);
        string cmd;
        string caller;
        long number;
        
        cmd  = line.substr(0,1);
        cout << endl;
        if (cmd == "i") {
            number = stol(line.substr(2,10));
            caller = line.substr(13);
            directory1.insert(number, caller);
        }
        
        else if (cmd == "s") {
            number = stol(line.substr(2));
            directory1.search(number);
        }
        
        else if (cmd == "d") {
            number = stol(line.substr(2));
            directory1.deleteKey(number);
        }
        
        else if (cmd == "n") {
            params = stoi(line.substr(end_command + 1));
            directory1.resize(params);
        }
        
    }
    cout << endl;
    return 0;
}



