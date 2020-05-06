//
//  Quadtree.cpp
//  Project3
//
//  Created by Ayushi Tiwari on 2020-03-10.
//  Copyright © 2020 Ayushi Tiwari. All rights reserved.
//

#include <iostream>
#include "Quadtree.h"

City::City(string cityName, double x1, double y1, int p1, int r1, int s1){
    Name = cityName;
    x = x1;
    y = y1;
    p = p1;
    r = r1;
    s = s1;
}

bool City:: insert(City *newCity, City *root){
    
    //to check if the node exists
    if ( (newCity -> x == root -> x) && (newCity -> y == root -> y)) {
        return false;
    }
    else if((newCity -> x >= root -> x) && (newCity -> y > root -> y)) {
        //if northEast node is empty, create a new node
        if(root -> northEast == nullptr) {
            root -> northEast =  newCity;
            return true;
        }
        else {
            //if not, recursively call the function
            return northEast -> insert(newCity, root -> northEast);
        }
    }
    
    else if((newCity -> x < root -> x) && (newCity -> y >= root -> y)) {
        //if northEast node is empty, create a new node
        if(root -> northWest == nullptr) {
            root -> northWest =  newCity;
            return true;
        }
        else {
            //if not, recursively call the function
            return northWest -> insert(newCity, root -> northWest);
        }
    }
    
    else if((newCity -> x <= root -> x) && (newCity -> y < root -> y)) {
        //if northEast node is empty, create a new node
        if(root -> southWest == nullptr) {
            root -> southWest =  newCity;
            return true;
        }
        else {
            //if not, recursively call the function
            return southWest -> insert(newCity, root -> southWest);
        }
    }
    
    else if((newCity -> x > root -> x) && (newCity -> y <= root -> y)) {
        //if northEast node is empty, create a new node
        if(root -> southEast == nullptr) {
            root -> southEast =  newCity;
            return true;
        }
        else {
            //if not, recursively call the function
            return southEast -> insert(newCity, root -> southEast);
        }
    }
}

City* City:: search(double x,double y, City *root){
    
    //to check if the node exists
    if ( (x == root -> x) && (y == root -> y)) {
        return root;
    }
    else if((x >= root -> x) && (y > root -> y)) {
        //if northEast node is empty, return false
        if(root -> northEast == nullptr) {
            return 0;
        }
        else {
            //if not, recursively call the function
            return northEast -> search( x, y, root -> northEast);
        }
    }
    
    else if(( x < root -> x) && (y >= root -> y)) {
        //if northWest node is empty, return false
        if(root -> northWest == nullptr) {
            return 0;
        }
        else {
            //if not, recursively call the function
            return northWest -> search( x, y, root -> northWest);
        }
    }
    
    else if(( x <= root -> x) && ( y < root -> y)) {
        //if southWest node is empty, return false
        if(root -> southWest == nullptr) {
            return 0;
        }
        else {
            //if not, recursively call the function
            return southWest -> search( x, y, root -> southWest);
        }
        
    }
    
    else if(( x > root -> x) && ( y <= root -> y)) {
        //if northEast node is empty, return false
        if(root -> southEast == nullptr) {
            return 0;
        }
        else {
            //if not, recursively call the function
            return southEast -> search( x, y, root -> southEast);
        }
    }
}

void City:: q_max(City *city, int &max, char attr){
    // If the node is not empty
    if(city != nullptr){
        //inorder traversal
        q_max (city -> northEast, max, attr);
        q_max (city -> northWest, max, attr);
        
        if(( city -> p > max) && (attr == 'p')){
            max = city -> p;
        }
        else if((city -> r > max) && (attr == 'r')){
            max = city -> r;
        }
        else if((city -> s > max) && (attr == 's')){
            max = city -> s;
        }
        q_max (city -> southWest, max, attr);
        q_max (city -> southEast, max, attr);
    }
}

void City:: q_min (City *city, int &min, char attr){
    // If the node is not empty
    if(city != nullptr){
        //inorder traversal
        q_min (city -> northEast, min, attr);
        q_min (city -> northWest, min, attr);
        
        if(( city -> p < min) && (attr == 'p')){
            min = city -> p;
        }
        else if((city -> r < min) && (attr == 'r')){
            min = city -> r;
        }
        else if((city -> s < min) && (attr == 's')){
            min = city -> s;
        }
        q_min (city -> southWest, min, attr);
        q_min (city -> southEast, min, attr);
    }
}

void City:: q_total (City *city, int &total, char attr){
    // If the node is not empty
    if(city != nullptr){
        //inorder traversal
        q_total (city -> northEast, total, attr);
        q_total (city -> northWest, total, attr);
        
        if(attr == 'p'){
            total += city -> p;
        }
        else if(attr == 'r'){
            total += city -> r;
        }
        else if(attr == 's'){
            total += city -> s;
        }
        q_total (city -> southWest, total, attr);
        q_total (city -> southEast, total, attr);
    }
}

void Quadtree:: insert(City *newCity){
    //If tree is empty
    if (count == 0){
        // new node of type city
        root = newCity;
        count ++;
        cout << "success" << endl;
    }
    else {
        //Insert a new node using the insert function in node
        if(root -> insert(newCity, root)){
            count ++;
            cout << "success" << endl;
        }
        else {
            cout << "failure" << endl;
        }
    }
}

City* Quadtree:: search(double x, double y, City *root){
    //If tree is empty
    if (count == 0){
        cout << "not found" << endl;
        return nullptr;
    }
    else {
        //Insert a new node using the insert function in node
        if(root -> search(x, y, root) != 0){
            City *city = root -> search(x, y, root);
            cout << "found " << city -> Name << endl;
            return city;
        }
        else {
            cout << "not found" << endl;
            return 0;
        }
    }
}

int Quadtree:: q_max(double x, double y, string d, char attr){
    if (root == nullptr){
        return 0;
    }
    else if(root -> search(x, y, root) != 0){
        City *city = root -> search(x, y, root);
        if(d == "NE"){
            city = city -> northEast;
        }
        else if(d == "NW"){
            city = city -> northWest;
        }
        else if(d == "SE"){
            city = city -> southEast;
        }
        else if(d == "SW"){
            city = city -> southWest;
        }
        
        if(city == 0){
            return 0;
        }

        int max;
        
        if (attr == 'p') {
            max = city -> p;
        }
        else if (attr == 'r') {
            max = city -> r;
        }
        else if (attr == 's') {
            max = city -> s;
        }
        
        city -> q_max( city, max, attr);
        return max;
    }
    return 0;
}

int Quadtree:: q_min (double x, double y, string d, char attr){
    if (root == nullptr){
        return 0;
    }
    else if(root -> search(x, y, root) != 0){
        City *city = root -> search(x, y, root);
        if(d == "NE"){
            city = city -> northEast;
        }
        else if(d == "NW"){
            city = city -> northWest;
        }
        else if(d == "SE"){
            city = city -> southEast;
        }
        else if(d == "SW"){
            city = city -> southWest;
        }
        
        if(city == 0){
            return 0;
        }

        int min;
        
        if (attr == 'p') {
            min = city -> p;
        }
        else if (attr == 'r') {
            min = city -> r;
        }
        else if (attr == 's') {
            min = city -> s;
        }
        
        city -> q_min( city, min, attr);
        return min;
    }
    return 0;
}

int Quadtree:: q_total(double x, double y, string d, char attr) {
    if (root == nullptr){
        return 0;
    }
    else if(root -> search(x, y, root) != 0){
        City *city = root -> search(x, y, root);
        if(d == "NE"){
            city = city -> northEast;
        }
        else if(d == "NW"){
            city = city -> northWest;
        }
        else if(d == "SE"){
            city = city -> southEast;
        }
        else if(d == "SW"){
            city = city -> southWest;
        }

        if(city == 0){
            return 0;
        }
        
        int total = 0;
        
        city -> q_total( city, total, attr);
        return total;
    }
    return 0;
}


void Quadtree:: print(City *root){
    if (root != nullptr){
        print(root -> northEast);
        print(root -> northWest);
        cout << root -> Name << " ";
        print(root -> southWest);
        print(root -> southEast);
    }
}

int Quadtree:: size(){
    return count;
}

void Quadtree:: clear(City *Root){
    if (Root != nullptr){
        clear(Root -> northEast);
        clear(Root -> northWest);
        clear(Root -> southWest);
        clear(Root -> southEast);
        delete Root;
        Root = nullptr; 
        count--;
    }
    if(count == 0){
        root = nullptr;
    }
}

City* Quadtree:: returnRoot(){
    return root;
}

// QuadTree:: ~QuadTree(){
//     root -> clear(root);
// }
