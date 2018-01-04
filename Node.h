/*
 * Header file for the Node class
 *
 * Author: Connor Shu
 * Class: CS162
 */

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstdlib>
#include "Student.h"
#include <cstring>
using namespace std;

class Node {
    private:
        //member variables
        Node* previous; //previous Node in the linked list
        Student* content; //the content stored in the Node
        Node* next;

    public:
        Node(Student* content); //constructor
        ~Node(); //destructor

        //getters
        Node* getPrevious();
        Student* getContent();
        Node* getNext();

        //setters
        void setPrevious(Node* previous);
        void setNext(Node* next);
};

#endif
