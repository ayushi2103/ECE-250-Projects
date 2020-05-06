//
//  undirectedGraphtest.cpp
//  Dijktsra’s algorithm
//
//  Created by Ayushi Tiwari on 2020-04-24.
//  Copyright © 2020 Ayushi Tiwari. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include "undirectedGraph.h"
using namespace std;

int main() {
    string name, command, str, name1, name2, line;
    double d;
    int vertex1, vertex2, nodes, deg, edges, connected;
    Graph g;
    while(!cin.eof()){
        getline(cin, line);
        command = line.substr(0, line.find(" "));
        if (command == "i"){
            name = line.substr(line.find(" ")+1);
            g.insert(name);
        }
        else if (command == "setd"){
            stringstream subline(line.substr(line.find(" ")+1));
            getline(subline, str, ';');
            name1 = str;
            getline(subline, str, ';');
            name2 = str;
            getline(subline, str, ';');
            d = stod(str);
            g.assignEdge(name1, name2, d);
            
        }
        else if (command == "s"){
            stringstream subline(line.substr(line.find(" ")+1));
            getline(subline, str, ';');
            name = str;
            
            g.search(name);
        }
        else if (command == "degree"){
            stringstream subline(line.substr(line.find(" ")+1));
            getline(subline, str, ';');
            name = str;
           
            g.degree(name);
            
        }
        
        else if (command == "graph_nodes"){
            g.graphNodes();
        }
        else if (command == "graph_edges"){
            g.graphEdges();
        }
        
        else if (command == "d"){
            stringstream subline(line.substr(line.find(" ")+1));
            getline(subline, str, ';');
            name1 = str;
            getline(subline, str, ';');
            name2 = str;
            g.distance(name1, name2);
            
        }
        else if (command == "clear"){
            g.clear();
        }
        else if (command == "shortest_d"){
            stringstream subline(line.substr(line.find(" ")+1));
            getline(subline, str, ';');
            name1 = str;
            getline(subline, str, ';');
            name2 = str;

            d = g.dijkstra(name1, name2);
            cout << "shortest distance " << name1 << " to " << name2 << " " << d << endl;
        }
    }
    return 0;
}
