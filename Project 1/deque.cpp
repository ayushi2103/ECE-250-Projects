//
//  deque.cpp
//  DequeDriver
//
//  Created by Ayushi Tiwari on 2020-01-31.
//  Copyright © 2020 Ayushi Tiwari. All rights reserved.
//

#include "deque.h"
using namespace std;

Node:: Node(){
    data = 0;
    next = nullptr;
    previous = nullptr;
};

Node:: ~Node(){
    next = NULL;
    previous = NULL;
}

Deque:: Deque(){
    head = NULL;
    tail = NULL;
}

Deque:: ~Deque(){
    head = NULL;
    tail = NULL;
}

void Deque:: enqueue_front(int new_data){
    Node* newNode = new Node;

    if (head == NULL){
        tail = head = newNode;
        newNode -> data = new_data;
    }
    else {
        newNode -> next = head;
        head -> previous = newNode;
        head = newNode;
        newNode -> data = new_data;
    }
    size++;
}

void Deque:: enqueue_back(int new_data){
    Node* newNode = new Node;
//    Node* tail = *head;
//    newNode -> data = new_data;
//    newNode -> next = NULL;
    if (head == NULL){
        tail = head = newNode;
        newNode -> data = new_data;
    }
    else {
        newNode -> previous = tail;
        tail -> next = newNode;
        tail = newNode;
        newNode -> data = new_data;
    }
    size++;
}
    
void Deque:: dequeue_front(){
    if (head != NULL){
        Node* temp = head;
        head = head -> next;
        if (head == NULL){
            tail = NULL;
        }
        else {
            head -> previous = NULL;
            delete temp;
        }
        size--;
        cout << "success";
       }
     else {
         cout << "failure";
       }
    
}

void Deque:: dequeue_back(){
    if (head != NULL){
       Node* temp = tail;
       tail = tail -> previous;
       if (tail == NULL){
           head = NULL;
       }
       else {
           tail -> next = NULL;
           delete temp;
       }
       size--;
       cout << "success";
      }
    else {
        cout << "failure";
      }
}

void Deque:: front(int i){
    if (head != NULL && i == (head->data)){
        cout << "success";
    }
    else {
        cout << "failure";
    }
}

void Deque:: back(int i){
    if (tail != NULL && i == (tail->data)){
        cout << "success";
    }
    else {
        cout << "failure";
    }
}

void Deque:: empty(){
    if (head == NULL){
        cout << "success";
    }
    else {
        cout << "failure";
    }
}

int Deque:: Size(){
    return size;
}


void Deque:: print(){
    if (head != NULL){
        Node *ptr;
        for ( ptr = head; ptr != tail; ptr = ptr -> next ) {
            cout << ptr -> data << " ";
        }
        cout << ptr -> data << endl;
        for ( ptr = tail; ptr != head; ptr = ptr -> previous ) {
             cout << ptr -> data << " ";
        }
        cout << ptr -> data << endl;
    }
}

void Deque:: clear(){
    tail = NULL; 
    while(head != NULL){ 
        Node* temp = head; 
        head = head -> next; 
        delete temp; 
    } 
    size = 0;
    cout << "success";
}
