//
//  undirectedGraph.h
//  Dijktsra’s algorithm
//
//  Created by Ayushi Tiwari on 2020-04-22.
//  Copyright © 2020 Ayushi Tiwari. All rights reserved.
//

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Node {
private:
    string city;
    int index;
    Node* next;
    double edgeWeight;
public:
    //Node();
    friend class Graph;
};

class linkedList {
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    
public:
    friend class Node;
    friend class Graph;

};

class Graph {
private:
    
    vector <linkedList> cityList;
    Node* info;
    int vertex = 0;
    int edge = 0;
    
public:
    //constructor that inserts the node to the graph
    //Graph();
    //~Graph();
    //insert
    void insert ( string name);
    //setd: Assigns a distance (d) to the edge (road) connecting two cities (name1 and name2)
    void assignEdge (string name1, string name2, double d);
    //search if the city exists
    void search (string name);
    //Returns the number of nodes (cities) in the graph
    void graphNodes();
    //Returns the number of edges (roads) in the graph.
    void graphEdges();
    //Prints the degree of the city (name)
    void degree (string name);
    //Prints the distance between two cities
    void distance(string name1, string name2);
    //removes all the edges from the graph
    void clear();
    double dijkstra(string name1, string name2);
    int minDistance(double dist[], bool sptSet[]);
  
};

