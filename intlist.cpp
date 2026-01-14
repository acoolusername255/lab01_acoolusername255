// intlist.cpp
// Implements class IntList
// Lucas Huang 1/13/2026

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    head = nullptr, tail = nullptr;
    Node* currentNode = source.head;
    while (currentNode) {
        push_back(currentNode->info);
        currentNode = currentNode->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    clear();
}

// return sum of values in list
int IntList::sum() const {
    int result = 0;
    Node* currentNode = head;
    while (currentNode) {
        result += currentNode->info;
        currentNode = currentNode->next;
    }
    return result;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    
    // If the list is empty then return false
    if (!head) return false;

    // If the tail has the value, then return true
    // Makes it more efficient when the value is only found at the tail
    if (tail->info == value) return true;

    // Otherwise, check every node but the last
    // (since we already checked the tail)
    Node* currentNode = head;
    while (currentNode->next) {
        if (currentNode->info == value) return true;
        currentNode = currentNode->next;
    }

    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (!head) return 0;
    Node* currentNode = head;
    int result = currentNode->info;
    currentNode = currentNode->next;
    while (currentNode) {
        if (currentNode->info > result) {
            result = currentNode->info;
        }
        currentNode = currentNode->next;
    }
    return result;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (!head) return 0.0;

    // I could just use the implementations of sum and count,
    // but it is more efficient to just traverse the list once
    double sum_of_values = 0.0;
    int number_of_values = 0;
    Node* currentNode = head;
    while (currentNode) {
        sum_of_values += currentNode->info;
        number_of_values++;
        currentNode = currentNode->next;
    }
    return sum_of_values / number_of_values;
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* newNode = new Node {value, head};
    head = newNode;
    if (!tail) tail = newNode;
}

// append value at end of list
void IntList::push_back(int value) {
    Node* newNode = new Node {value, nullptr};
    if (tail) {
        tail->next = newNode;
    } else {
        head = newNode;
    }
    tail = newNode;
}

// return count of values
int IntList::count() const {
   //IMPLEMENT THIS
   int number_of_values = 0;
   Node* currentNode = head;
   while (currentNode) {
    number_of_values++;
    currentNode = currentNode->next;
   }
   return number_of_values;
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this != &source) {
        //Delete all current nodes
        clear();
        Node* currentNode = source.head;
        while (currentNode) {
            push_back(currentNode->info);
            currentNode = currentNode->next;
        }
    }
    return *this;
}

// constructor sets up empty list
IntList::IntList() {
    head = nullptr, tail = nullptr;
}

// Clear helper function
void IntList::clear() {
    Node* currentNode = head;
    while (currentNode) {
        Node* nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
    head = nullptr, tail = nullptr;
}

// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}