//
//  openht.cpp
//  openhttest
//
//  Created by Ayushi Tiwari on 2020-02-14.
//  Copyright © 2020 Ayushi Tiwari. All rights reserved.
//

#include <iostream>
#include "openht.h"
#include <cmath>
using namespace std;

hashTable:: hashTable (int m){
    table.resize(m);
};

void hashTable:: insert(long k, string caller){
    int probe = k % table.capacity();
    int offset = int(floor(k / table.capacity())) % table.capacity();
    if(offset % 2 == 0){
        offset ++;
    }
    if(table[probe].number != 0){
        if(count == table.capacity()){
            cout << "failure";
        }
        else {
            while (table[probe].number != 0){
                if(table[probe].number ==  k){
                    cout << "failure";
                    break;
                }
                probe = (probe + offset) % table.capacity();
            }
            if(table[probe].number !=  k){
                table[probe].number = k;
                table[probe].caller = caller;
                count ++;
                cout << "success";
            }
        }
    }
    else {
        table[probe].number = k;
        table[probe].caller = caller;
        count ++;
        cout << "success";
    }
}

void hashTable:: search(long k){
    int i, counter = 0;
    for (i = 0; i < table.capacity(); i++){
        if(table[i].number == k){
            counter = 1;
            break;
        }
    }
    if(counter == 1){
        cout << "found " << table[i].caller << " in " << i;
    }
    else{
        cout << "not found";
    }
}

void hashTable:: deleteKey(long k){
    int counter = 0;
    for (int i = 0; i < table.capacity(); i++){
        if(table[i].number == k){
            table[i].number = 0;
            table[i].caller = "";
            count --;
            counter = 1;
            cout << "success";
        }
    }
    if(counter == 0){
        cout << "failure";
    }
}

void hashTable:: resize(int m){
    for (int i = 0; i < table.capacity(); i++){
        table[i].number = 0;
        table[i].caller = "";
    }
    table.resize(m);
    cout << "success";
}
