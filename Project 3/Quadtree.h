//
//  Quadtree.h
//  Project3
//
//  Created by Ayushi Tiwari on 2020-03-10.
//  Copyright © 2020 Ayushi Tiwari. All rights reserved.
//
#include <iostream>
using namespace std;

class City {
private:
    string Name = "";//city name
    double x = 0.0;//Longitude
    double y = 0.0;//Latitude
    int p = 0;//Population
    int r = 0;//Cost of Living
    int s = 0;//Average Net Salary
    
    //boundary nodes of the tree
    
    //child node
    City *northWest;
    City *northEast;
    City *southWest;
    City *southEast;
    
public:
    City(string cityName, double x1, double y1, int p1, int r1, int s1);
    bool insert(City *newCity, City *root);
    City *search(double x,double y, City *root);
    void q_max (City *city, int &max, char attr);
    void q_min (City *city, int &min, char attr);
    void q_total (City *city, int &total, char attr);

    friend class Quadtree;

};

class Quadtree {
private:
    City *root = nullptr;
    int count = 0;
    
public:
    //~Quadtree(); //destructor
    //i: Inserts a node for a city containing city_info
    void insert(City *newCity);
    //s: searches for node(x, y)
    City *search(double x, double y, City *root);
    //q_max: Finds the max value in the d direction
    int q_max(double x, double y, string d, char attr);
    int q_min(double x, double y, string d, char attr);
    int q_total(double x, double y, string d, char attr);
    void print(City *root);
    void clear(City *Root);
    int size();
    City *returnRoot();
};
