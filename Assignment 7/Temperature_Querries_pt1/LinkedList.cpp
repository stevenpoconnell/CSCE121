#include <iostream>
#include <string>
#include <sstream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

LinkedList::LinkedList() {
	// Implement this function
    this -> head = nullptr;
    this -> tail = nullptr;
}

LinkedList::~LinkedList() {
    this -> clear();
}

LinkedList::LinkedList(const LinkedList& source) {
    head = nullptr;
    *this = source;
}

// FIX ME
LinkedList& LinkedList::operator=(const LinkedList& source) {
	// implement this function
    Node* current = source.getHead();
    
    while (current != nullptr) {
        TemperatureData& data = current -> data;
        insert(data.id, data.year, data.month, data.temperature);
        current = current -> next;
    }
    
    return *this;
}

void LinkedList::insert(string location, int year, int month, double temperature) {
    Node* newNode = new Node(location, year, month, temperature);
    newNode -> next = nullptr;
    if (head == nullptr) {
       head = newNode;
       tail = newNode;
       return;
    }
    else {
        tail -> next = newNode;
        tail = newNode;
    }
}

void LinkedList::clear() {
    Node* current = head;
    Node* temp;
    
    while (current != nullptr) {
        temp = current -> next;
        delete(current);
        current = temp;
    }
    
    head = nullptr;
}

Node* LinkedList::getHead() const {
    return this -> head;
}

string LinkedList::print() const {
	string outputString;
	// Implement this function
    ostringstream oss;
    Node* current = head;
    while (current != nullptr) {
        oss << current -> data.id << " ";
        oss << current -> data.year << " ";
        oss << current -> data.month << " ";
        oss << current -> data.temperature << " ";
        current = current -> next;
    }
    outputString = oss.str();
	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}


