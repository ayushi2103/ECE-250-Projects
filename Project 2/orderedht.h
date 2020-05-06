//
//  openhttest.h
//  openhttest
//
//  Created by Ayushi Tiwari on 2020-02-14.
//  Copyright © 2020 Ayushi Tiwari. All rights reserved.
//
#include "vector"
using namespace std;

class Node {
    
private:
    long numbers;
    string caller;
    Node* next;
    
public:
    //Node();
    friend class hashTable;
    //~Node();
};

class list {
    
private:
    Node* point;
    
public:
    //list();
    friend class hashTable;
    //~list();
};

class hashTable{
    
private:
    vector<list> table;
    Node* temp = nullptr;
    
public:
    //Sets the size of the vector
    hashTable(int m);
    //Inserts the key k and the associated caller
    void insert(long k, string caller);
    //Searches for the key k in the table
    void search(long k);
    //Deletes the key k from the table
    void deleteKey(long k);
    //Prints the chain of keys that starts at position i
    void print(int i);
    void resize(int m);
};
