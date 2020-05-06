//
//  openht.hpp
//  openhttest
//
//  Created by Ayushi Tiwari on 2020-02-14.
//  Copyright © 2020 Ayushi Tiwari. All rights reserved.
//

#include <vector>
#include "string"
using namespace std;

class directory{
    
private:
    long number =  0;
    string caller = "";
    
public:
    friend class hashTable;
    };

class hashTable{
    
private:
    vector<directory> table;
    int count = 0;
    
public:
    //Sets the size of the vector
    hashTable(int m);
    //Inserts the key k and the associated caller
    void insert(long k, string caller);
    //Searches for the key k in the table
    void search(long k);
    //Deletes the key k from the table
    void deleteKey(long k);
    //to resize the table
    void resize(int m);
};
