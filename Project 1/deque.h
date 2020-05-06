//
//  deque.hpp
//  DequeDriver
//
//  Created by Ayushi Tiwari on 2020-01-31.
//  Copyright © 2020 Ayushi Tiwari. All rights reserved.
//

#include <iostream>

class deque_empty{};

class Node {
    private:
        int data;
        Node* next;
        Node* previous;
    
    public:
        Node();
        friend class Deque;
        ~Node();
    
};

class Deque {
    
    // class variables
    private:
    Node* head;
    Node* tail;
    int size = 0;
    // class functions
    public:
    Deque();
    ~Deque();
    //Add element at the front
    void enqueue_front(int new_data);
    //Add element at the end
    void enqueue_back(int new_data);
    //Remove element from front
    void dequeue_front();
    //Remove element from the back
    void dequeue_back();
    void front(int i);
    void back(int i);
    void empty();
    int Size();
    void print();
    void clear();
};

