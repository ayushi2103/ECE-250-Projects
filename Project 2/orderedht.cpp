//
//  openhttest.cpp
//  openhttest
//
//  Created by Ayushi Tiwari on 2020-02-14.
//  Copyright © 2020 Ayushi Tiwari. All rights reserved.
//

#include <iostream>
#include <vector>
#include "orderedht.h"
using namespace std;

hashTable:: hashTable (int m){
    table.resize(m);
};

void hashTable:: insert(long k, string caller){
    int probe = k % table.capacity();
    Node* newNode = new Node;
    temp = table[probe].point;
    
    if ( table[probe].point == nullptr){
        table[probe].point = newNode;
        newNode -> numbers = k;
        newNode -> caller = caller;
        newNode -> next = nullptr;
        cout << "success";
    }
    else {
        Node* prev = table[probe].point;
        int counter = 0;
        while(temp != nullptr){
            if(temp -> numbers == k){
                counter = 1;
                break;
            }
            prev = temp;
            temp = temp -> next;
        }
        if(counter != 1){
            prev -> next = newNode;
            newNode -> numbers = k;
            newNode -> caller = caller;
            newNode -> next = nullptr;
            cout << "success";
        }
        else{
            cout << "failure";
        }
    }
}

void hashTable:: search(long k){
    int probe = k % table.capacity();
    temp = table[probe].point;
    int counter = 0;
    for (temp = table[probe].point; temp != nullptr; temp = temp -> next){
        if(temp -> numbers == k){
            counter = 1;
            break;
        }
    }
    if(counter == 1){
        cout << "found " << temp -> caller << " in " << probe;
    }
    else{
        cout << "not found";
    }
}

void  hashTable:: deleteKey(long k){

    int probe = k % table.capacity();
    int counter = 0;
    temp = table[probe].point;
    Node* prev = table[probe].point;

    for (temp = table[probe].point; temp != nullptr; temp = temp -> next) {
        if (temp -> numbers == k){
            counter = 1;
            break;
        }
        prev = temp;
    }
    
    if(table[probe].point == nullptr || counter == 0){
        cout << "failure";
    }
    else if(counter == 1 && temp == table[probe].point){
        if(temp -> next == nullptr){
            table[probe].point = nullptr;
            cout << "success";
        }
        else{
            table[probe].point = temp -> next;
            cout << "success";
        }
    }
    else{
        prev -> next = temp -> next;
        cout << "success";
    }
}

void hashTable:: print(int i){
    if(table[i].point != nullptr){
        int count = 0;
        temp = table[i].point;
        vector<long> vec;
        for (temp = table[i].point; temp != nullptr; temp = temp -> next){
            vec.push_back(temp -> numbers);
            count ++;
        }
        int k, j;
        long key;
        for (k = 1; k < count; k++){
            key = vec[k];
            j = k - 1;
            while (k >= 0 && vec[j] > key)
            {
                vec[j + 1] = vec[j];
                j = j - 1;
            }
            vec[j + 1] = key;
        }
        for(int l = 0; l < count; l++){
            cout << vec[l] << " ";
        }
    }
}

void hashTable:: resize(int m){
    for (int i = 0; i < table.capacity(); i++){
        table[i].point = nullptr;
    }
    table.resize(m);
    cout << "success";
}
