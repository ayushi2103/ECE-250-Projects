//
//  undirectedGraph.cpp
//  Dijktsra’s algorithm
//
//  Created by Ayushi Tiwari on 2020-04-22.
//  Copyright © 2020 Ayushi Tiwari. All rights reserved.
//

#include <iostream>
#include "undirectedGraph.h"

using namespace std;


//Inserts a node (city) to a graph
void Graph:: insert ( string name){
    int flag = 0;
    for(int i = 0; i < vertex; i++ ){
        if(cityList[i].head -> city == name){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        cout << "failure" << endl;
    }
    else {
        info = new Node;
        info -> city = name;
        info -> edgeWeight = 0.0;
        info -> index = vertex;
        cityList.resize(vertex+1);
        cityList[vertex].tail = info;
        cityList[vertex].head = info;
        vertex++;
        cout << "success" << endl;
    }
}

void Graph:: assignEdge (string name1, string name2, double d){
    int index = -1;
    int flag = 0;
    
    for(int i = 0; i < cityList.size(); i++ ){
        if(cityList[i].head -> city == name1){
            index = i;
        }
    }
    
    int index1 = -1;
    for(int i = 0; i < cityList.size(); i++ ){
        if(cityList[i].head -> city == name2){
            index1 = i;
        }
    }
    
    if (index == -1 || index1 == -1 || d <= 0 || name1 == name2){
        cout << "failure" << endl;
    }
    else {
        for(Node* i = cityList[index].head -> next; i != nullptr; i = i -> next){
            if (i -> city == name2){
                i -> edgeWeight = d;
                flag = 1;
                break;
            }
        }
        
        for(Node* i = cityList[index1].head -> next; i != nullptr; i = i -> next){
            if (i -> city == name1){
                i -> edgeWeight = d;
                flag = 1;
                break;
            }
        }
        
        if (flag == 0){
            info = new Node;
            info -> city = name2;
            info -> edgeWeight = d;
            cityList[index].tail -> next = info;
            cityList[index].tail = info;
            
            info = new Node;
            info -> city = name1;
            info -> edgeWeight = d;
            cityList[index1].tail -> next = info;
            cityList[index1].tail = info;
        }
        cout << "success" << endl;
        edge++;
    }
}

void Graph:: search (string name){
    int flag = 0;
    for(int i = 0; i < cityList.size(); i++ ){
        if(cityList[i].head -> city == name){
            cout << "found " << name << endl;
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        cout << "not found" << endl;
    }
}

void Graph:: degree(string name){
    int count = 0;
    int index = -1;
    int flag = 0;
    for(int i = 0; i < cityList.size(); i++ ){
        if(cityList[i].head -> city == name){
            index = i;
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        for(Node* i = cityList[index].head -> next; i != nullptr; i = i -> next){
            count++;
        }
        cout << "degree of " << name << " " << count << endl;
    }
    else {
        cout << "failure" << endl;
    }
    
}

void Graph:: graphNodes(){
    cout << "number of nodes " << vertex << endl;
}

void Graph:: graphEdges(){
    cout << "number of edges " << edge << endl;
}

void Graph:: distance(string name1, string name2){
    int index = -1;
    int flag = 0;
    for(int i = 0; i < cityList.size(); i++ ){
        if(cityList[i].head -> city == name1){
            index = i;
            flag = 1;
        }
    }
    if (flag == 1){
        for(Node* i = cityList[index].head -> next; i != nullptr; i = i -> next){
            if(i -> city == name2){
                cout << "direct distance " << name1 << " to " << name2 << " " << i -> edgeWeight <<endl;
                break;
            }
        }
    }
    else {
        cout << "failure" << endl;
    }
    
}

void Graph:: clear(){
    for(int i = 0; i < cityList.size(); i++ ){
        cityList[i].head = nullptr;
        cityList[i].tail = nullptr;
    }
    edge = 0;
    vertex = 0;
    cout << "success" << endl;
}

double Graph:: dijkstra(string name1, string name2){
    double dist[vertex];

    bool sptSet[vertex];

    for (int i = 0; i < vertex; i++){
        dist[i] = numeric_limits<double>::infinity(), sptSet[i] = false; 
    }

    int index1 = -1;
    for(int i = 0; i < cityList.size(); i++ ){
        if(cityList[i].head -> city == name1){
            index1 = i;
        }
    }
    
    dist[index1] = 0.0; 

    for (int count = 0; count < vertex - 1; count++) { 
        int u = minDistance(dist, sptSet); 
  
        sptSet[u] = true; 
  
        for (int v = 0; v < vertex; v++){
            double weight = 0.0;
            for(Node* i = cityList[u].head -> next; i != nullptr; i = i -> next){
                if(i -> index == v){
                    weight = i -> edgeWeight;
                    break;
                }
            }
            if (!sptSet[v] && weight && dist[u] != numeric_limits<double>::infinity() && dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight; 
            }
        }    
    } 

}

int Graph:: minDistance(double dist[], bool sptSet[]){
    double min = numeric_limits<double>::infinity();
    int min_index;
  
    for (int v = 0; v < vertex; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index;
}




