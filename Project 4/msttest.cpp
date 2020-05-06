//
//  msttest.cpp
//  Minimum Spanning Tree
//
//  Created by Ayushi Tiwari on 2020-04-03.
//  Copyright © 2020 Ayushi Tiwari. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include "MinimumSpanningTree.h"
using namespace std;

int main() {
    string line, command, str;
    double weight, mst;
    int vertex1, vertex2, nodes, deg, edges, connected;
    getline(cin, line);
    nodes = stoi(line.substr(line.find(" ") + 1));
    Graph g(nodes);
    
     while(!cin.eof()){
         getline(cin, line);
         command = line.substr(0, line.find(" "));

        if (command == "i"){
            stringstream subline(line.substr(line.find(" ")+1));
            getline(subline, str, ';');
            vertex1 = stoi(str);
            getline(subline, str, ';');
            vertex2 = stoi(str);
            getline(subline, str, ';');
            weight = stod(str);

            try {
                g.insert(vertex1, vertex2, weight);
            }
            catch(illegal_argument){
                cout << "failure" << endl;
            } 
        }
        else if (command == "d"){
            stringstream subline(line.substr(line.find(" ")+1));
            getline(subline, str, ';');
            vertex1 = stoi(str);
            getline(subline, str, ';');
            vertex2 = stoi(str);

            try{
                g.deleteEdge(vertex1, vertex2);
            }
            catch(illegal_argument){
                cout << "failure" << endl;
            }
        }
        else if (command == "degree"){
            stringstream subline(line.substr(line.find(" ")+1));
            getline(subline, str, ';');
            vertex1 = stoi(str);

            try{
                deg = g.degree(vertex1);
                cout << "degree of " << vertex1 << " is " << deg << endl;
            }
            catch(illegal_argument){
                cout << "failure" << endl;
            }
        }
        else if (command == "edge_count"){
            edges = g.edge_count();
            cout << "edge count is " << edges << endl;
        }
        else if (command == "clear"){
            g.clear();
        }

        else if (command == "mst"){
            connected = g.connected();
            if(connected == 1){
                mst = g.mst();
                cout << "mst " << mst << endl;
            }
            else{
                cout << "not connected" << endl;
            } 
        }
     }
    return 0;
}
