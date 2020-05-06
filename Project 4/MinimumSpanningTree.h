//
//  MinimumSpanningTree.hpp
//  Minimum Spanning Tree
//
//  Created by Ayushi Tiwari on 2020-04-02.
//  Copyright © 2020 Ayushi Tiwari. All rights reserved.
//


#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

class EdgeHelp{
private:
    int u;
    int v;
    double edgeweight;

public:
    EdgeHelp(int v1, int v2, double w);
    friend class Graph;
};

class Graph {
private:
    int vertex;
    int edge;
    double **adjMatrix;
    int *degreeArr;
    vector<EdgeHelp> Edges;
    
public:
    Graph( int n );
    ~Graph();
    //insert
    void insert ( int u, int v, double w);
    //deletes an edge
    void deleteEdge (int u, int v);
    //returns the degree of the vertex
    int degree (int u);
    //returns the total number of edges
    int edge_count();
    //removes all the edges from the graph
    void clear();
    double mst();
    int connected();

    friend class EdgeHelp;
};
class Node;
class linkedList;
class disjointSet;

class linkedList {
private:
    Node* head; 
    Node* tail;
    int size;
    
public:
    linkedList(Node* Head, Node* Tail, int i);
    friend class Node;
    friend class disjointSet;
};

class Node {
private:
    int data;
    Node* next;
    linkedList* info;
    
public: 
    Node(int i);
    friend class linkedList;
    friend class disjointSet;
};


class disjointSet {
private:
    Node** newNode;
    linkedList** Set;
    int counter;
    int numberOfSets;
    
public:
    disjointSet(int n);
    ~disjointSet();
    int numOfSets();
    void makeSet(int i);
    int findSet(int n);
    void unionSet (int u, int v);
    friend class linkedList;
};

class illegal_argument {};
