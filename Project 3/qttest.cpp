//
//  qttest.cpp
//  Project3
//
//  Created by Ayushi Tiwari on 2020-03-10.
//  Copyright © 2020 Ayushi Tiwari. All rights reserved.
//
#include <iostream>
#include <string>
#include <sstream>
#include "Quadtree.h"
using namespace std;

int main() {
    string line, cmd, str, cityName, d;
    char attr;
    double x, y;
    int p, r, s, size;
    Quadtree q;

     while(!cin.eof()){
         getline(cin, line);
         cmd = line.substr(0, line.find(" "));
        if (cmd == "i"){
            stringstream subline(line.substr(line.find(" ")+1));
            getline(subline, str, ';');
            cityName = str;
            getline(subline, str, ';');
            x = stod(str);
            getline(subline, str, ';');
            y = stod(str);
            getline(subline, str, ';');
            p = stoi(str);
            getline(subline, str, ';');
            r = stoi(str);
            getline(subline, str);
            s = stoi(str);

            //cout << cityName << " " << x << " " << y << " " << p << " " << r << " " << s << endl;
            City *city = new City(cityName, x, y, p, r, s);
            q.insert(city);

        }
        else if (cmd == "s"){
            stringstream subline(line.substr(line.find(" ")+1));
            getline(subline, str, ';');
            x = stod(str);
            getline(subline, str, ';');
            y = stod(str);
            q.search(x,y, q.returnRoot());
            }
        else if (cmd == "q_max"){
            stringstream subline(line.substr(line.find(" ")+1));
            getline(subline, str, ';');
            x = stod(str);
            getline(subline, str, ';');
            y = stod(str);
            getline(subline, str, ';');
            d = str;
            getline(subline, str, ';');
            attr = str[0];

            if(q.q_max(x, y, d, attr) == 0){
                cout << "failure" << endl;
            }
            else{
                cout << "max " <<  q.q_max(x, y, d, attr) << endl;
            }
        }
        else if (cmd == "q_min"){
            stringstream subline(line.substr(line.find(" ")+1));
            getline(subline, str, ';');
            x = stod(str);
            getline(subline, str, ';');
            y = stod(str);
            getline(subline, str, ';');
            d = str;
            getline(subline, str, ';');
            attr = str[0];
            if(q.q_min(x, y, d, attr) == 0){
                cout << "failure" << endl;
            }
            else{
                cout << "min " <<  q.q_min(x, y, d, attr) << endl;
            }
        }
        else if (cmd == "q_total"){
            stringstream subline(line.substr(line.find(" ")+1));
            getline(subline, str, ';');
            x = stod(str);
            getline(subline, str, ';');
            y = stod(str);
            getline(subline, str, ';');
            d = str;
            getline(subline, str, ';');
            attr = str[0];
            if(q.q_total(x, y, d, attr) == 0){
                cout << "failure" << endl;
            }
            else{
                cout << "total " <<  q.q_total(x, y, d, attr) << endl;
            }
        }
        else if (cmd == "print"){
            q.print(q.returnRoot());
            cout << endl;
        }

        else if (cmd == "clear"){
            q.clear(q.returnRoot());
            cout << "success" << endl;
        }
        else if (cmd == "size"){
            size = q.size();
            cout << "tree size " << size << endl;
        }
     }
    return 0;
}