//
//  MinimumSpanningTree.cpp
//  Minimum Spanning Tree
//
//  Created by Ayushi Tiwari on 2020-04-02.
//  Copyright © 2020 Ayushi Tiwari. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include "MinimumSpanningTree.h"

using namespace std;

EdgeHelp:: EdgeHelp(int v1, int v2, double w){
    u = v1;
    v = v2;
    edgeweight = w;
}

//to create a matrix
Graph:: Graph(int n){
    adjMatrix = new double* [n];
    for (int i = 0; i < n; i++){
        adjMatrix[i] = new double [n];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            adjMatrix[i][j] = 0.0;
        }
    }
    vertex = n;
    edge = 0;
    
    degreeArr = new int [n];
    for (int i = 0; i < n; i++){
        degreeArr[i] = 0;
    }
    cout << "success" << endl;
}

Graph:: ~Graph(){}

void Graph:: insert ( int u, int v, double w){
    if (u < vertex && v < vertex && u >= 0 && v >= 0 && u != v && w > 0.0){
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w;
        
        degreeArr[u] += 1;
        degreeArr[v] += 1;
        edge += 1;
        cout << "success" << endl;
    }
    else {
        throw illegal_argument();
    }
}

void Graph:: deleteEdge (int u, int v){
    if (adjMatrix[u][v] == 0){
        cout << "failure" << endl;
    }
    else if (u < vertex && v < vertex && u >= 0 && v >= 0){
        adjMatrix[u][v] = 0;
        adjMatrix[v][u] = 0;
        
        degreeArr[u] -= 1;
        degreeArr[v] -= 1;
        edge -= 1;
        cout << "success" << endl;
    }
    else {
        throw illegal_argument();
    }
}

int Graph:: degree(int u) {
    if (u < vertex && u >= 0){
        return degreeArr[u];
    }
    else {
        throw illegal_argument();
    }
}

int Graph:: edge_count(){
    return edge;
}

void Graph:: clear(){
    for (int i = 0; i < vertex; i++){
        for (int j = 0; j < vertex; j++){
            adjMatrix[i][j] = 0.0;
        }
    }
    edge = 0;
    for (int i = 0; i < vertex; i++){
        degreeArr[i] = 0;
    }
    cout << "success" << endl;
}

double Graph:: mst(){
    double total = 0.0;

    disjointSet* dis = new disjointSet(vertex);

    for(int i = 0; i < vertex; i++){
        dis->makeSet(i);
    }
        
    for(int i = 0 ; i < vertex ; i++){
        for(int j = i ; j < vertex ; j++){
            if(adjMatrix[i][j] != 0.0){
                Edges.push_back({i, j, adjMatrix[i][j]});
            }
        }
    }

    sort(Edges.begin(), Edges.end(), [](EdgeHelp x, EdgeHelp y) {
        return x.edgeweight < y.edgeweight;});

    int i = 0;
    while(i != vertex && dis->numOfSets() > 1){
        if(dis->findSet(Edges[i].u) != dis->findSet(Edges[i].v)) {
            dis->unionSet(Edges[i].u, Edges[i].v);
            total = total + Edges[i].edgeweight;
        }
        i++;
    }

    Edges.clear();
    delete dis;
    return total;

}

int Graph:: connected(){
    int counter = 0;
    for(int i = 0 ; i < vertex ; i++){
        counter = 0;
        for(int j = 0 ; j < vertex ; j++){
            if(adjMatrix[j][i] != 0.0){
                counter = 1;
                break;
            }
        }
    }
    return counter;
}

Node:: Node(int i){
    this -> data = i;
    this -> info = nullptr;
    this -> next = nullptr;
}

linkedList:: linkedList(Node* Head, Node* Tail, int i){
    this->head = Head;
	this->tail = Tail;
	this->size = i;
}

disjointSet:: disjointSet(int n):
newNode(new Node* [n]), //creating a Node** type array to store info
Set (new linkedList *[n]), //creating a Set of type linked list
counter(n),
numberOfSets(n){ }

disjointSet:: ~disjointSet(){
    for(int i = 0; i < this->numberOfSets; i++) {
		if(this->newNode[i] != nullptr)
			delete this->newNode[i];

		if(this->Set[i] != nullptr)
			delete this->Set[i];
	}
	delete[] this->newNode;
	delete[] this->Set;
}

int disjointSet:: numOfSets(){
    return this->counter;
}

void disjointSet:: makeSet(int i){
    Node* node = new Node(i);
    newNode[i] = node;
    linkedList* list = new linkedList(node, node, 1);
    Set[i] = list;
    node->info = list;
}

int disjointSet:: findSet(int n) {
    return this-> newNode [n] -> info -> head -> data;
}

void disjointSet:: unionSet(int u, int v){
    if(u == v){
        
    }
        
        else {
            
            linkedList* set1 = this -> newNode[u] -> info;
            linkedList* set2 = this -> newNode[v] -> info;

            int index1 = set1 -> size >= set2 -> size ? u : v;
            int index2 = set1 -> size < set2 -> size ? u : v;

            set1 = this -> newNode [index1] -> info;
            set2 = this -> newNode [index2] -> info;
            Node* node = set2 -> head;

            /* iterate through the shorter list and modify the pointers */
            while (node != nullptr) {
                node -> info = set1;
                node = node -> next; 
            }

            Node* old_tail = set1 -> tail;
            old_tail -> next = set2 -> head;

            set1->tail = set2->tail;
            set1->size += set2->size;

            this->counter--;
        }
}

