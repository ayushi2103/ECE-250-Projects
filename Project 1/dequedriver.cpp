//
//  main.cpp
//  DequeDriver
//
//  Created by Ayushi Tiwari on 2020-01-30.
//  Copyright © 2020 Ayushi Tiwari. All rights reserved.
//

#include <iostream>
#include <string>
#include "deque.h"
using namespace std;

int main() {
    string line, temp;
    int i, size;
    Deque d;
    for( getline(cin, line); (!cin.eof() == true) ; getline(cin, line)){

        temp = line.substr(0, 2);
        if(temp == "fr" || temp == "ba" || temp == "en"){
            if(temp == "en" && line.substr(0, 13) == "enqueue_front"){
                i = stoi(line.substr(13));
                d.enqueue_front(i);
                cout << "success" << endl;
            }
            else if(temp == "en" && line.substr(0, 12) == "enqueue_back"){
                i = stoi(line.substr(12));
                d.enqueue_back(i);
                cout << "success" << endl;
            }
            else if(temp == "fr"){
                i = stoi(line.substr(5));
                d.front(i);
                cout << endl;
            }
            else if(temp == "ba"){
                i = stoi(line.substr(4));
                d.back(i);
                cout << endl;
            }
        }
        else{
            if(line == "dequeue_front"){
                d.dequeue_front();
                cout << endl;
            }
            else if(line == "dequeue_back"){
                d.dequeue_back();
                cout << endl;
            }
            else if(line ==  "empty"){
                d.empty();
                cout << endl;
            }
            else if(line == "size"){
                size = d.Size();
                cout << "size is " << size << endl;
            }
            else if(line == "print"){
                d.print();
            }
            else if(line == "clear"){
                d.clear();
                cout << endl;
            }
        }
    }
    getline(cin, line);
    temp = line.substr(0, 2);
    if(temp == "fr" || temp == "ba" || temp == "en"){
        if(temp == "en" && line.substr(0, 13) == "enqueue_front"){
            i = stoi(line.substr(13));
            d.enqueue_front(i);
            cout << "success";
        }
        else if(temp == "en" && line.substr(0, 12) == "enqueue_back"){
            cout << "here" << endl;
            i = stoi(line.substr(12));
            d.enqueue_back(i);
            cout << "success";
        }
        else if(temp == "fr"){
            i = stoi(line.substr(5));
            d.front(i);
        }
        else if(temp == "ba"){
            i = stoi(line.substr(4));
            d.back(i);
        }
    }
    else{
        if(line == "dequeue_front"){
            d.dequeue_front();
        }
        else if(line == "dequeue_back"){
            d.dequeue_back();
        }
        else if(line ==  "empty"){
            d.empty();
        }
        else if(line == "size"){
            size = d.Size();
            cout << "size is " << size;
        }
        else if(line == "print"){
            d.print();
        }
        else if(line == "clear"){
            d.clear();
        }
    }

    return 0;

}
