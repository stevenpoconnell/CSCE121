#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {
	// Implement this function
}

LinkedList::~LinkedList() {
	// Implement this function
	clear();
}

LinkedList::LinkedList(const LinkedList& source) {
	// Implement this function
	Node* cur = source.head;
	Node* prev = cur;
	while (cur) {
		Node* newNode = new Node(cur->data.id, cur->data.year, cur->data.month, cur->data.temperature);
		if (cur == source.head) {
			head = newNode;
		}
		else {
			prev->next = newNode;
			if (cur == source.tail) {
				tail = newNode;
			}
		}
		prev = newNode;
		cur = cur->next;
	}
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	// Implement this function
	if (&source != this) {
		clear();
		Node* cur = source.head;
		Node* prev = cur;
		while (cur) {
			Node* newNode = new Node(cur->data.id, cur->data.year, cur->data.month, cur->data.temperature);
			if (cur == source.head) {
				head = newNode;
			}
			else {
				prev->next = newNode;
				if (cur == source.tail) {
					tail = newNode;
				}
			}
			prev = newNode;
			cur = cur->next;
		}
	}
	return *this;
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	// Implement this function
	// cout << "Start: " << location << year << " " << month << " " << temperature << endl;
	Node* newNode = new Node(location, year, month, temperature);
	if (head==nullptr) { //empty list
		head = newNode;
		tail = newNode;
	}
	else {
		Node* cur = head;
		Node* prev = head;
		while (cur!=nullptr && cur->data < newNode->data) {
			prev = cur;
			cur = cur->next;
		}
		// exit loop either because came to end of list
		//  OR cur is greater than the newNode
		if (cur==head && prev==head) { // new head
			newNode->next = cur;
			head = newNode;
		}
		else { // add to middle or new tail
			newNode->next = cur;
			prev->next = newNode;
			if (prev==tail) { // new tail
				tail = newNode;
			}
		}
	}
}

void LinkedList::clear() {
	// Implement this function
	Node* cur = head;
	while (cur) {
		Node* del = cur;
		cur = cur->next;
		delete del;
	}
	head = nullptr;
	tail = nullptr;
}

Node* LinkedList::getHead() const {
	// Implement this function it will be used to help grade other functions
	return head;
}

string LinkedList::print() const {
	stringstream ss;
	// Implement this function
	Node* cur = head;
	while (cur) {
		ss << cur->data.id << " " << cur->data.year << " " << cur->data.month << " " << cur->data.temperature << endl;
		cur = cur->next;
	}

	return ss.str();
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}



double LinkedList::getAvg(std::string location, int startYear, int endYear) {
    double sum = 0.0;
    double average = 0.0;
    double count = 0.0;
    Node* current = head;
    
    while (current != nullptr) {
        if (location == current -> data.id) {
            if (current -> data.temperature != -99.99) {
                if (current -> data.year >= startYear) {
                    if (current -> data.year <= endYear) {
                        sum += current -> data.temperature;
                        count++;
                    }
                }
            }
        }
        current = current -> next;
    }
    
    average = (sum / count);
    return average;
}


int LinkedList::getMode(std::string location , int startYear, int endYear) {
    int mode = 0;
    int currentValue;
    int previousValue = 0;
    vector<int> values;
    Node* current = head;
    
    for (int i = 0; i < 101; i++) {
        values.push_back(0);
    }
    
    while (current != nullptr) {
        if (current -> data.id == location) {
            if (current -> data.temperature != -99.99) {
                if (current -> data.year >= startYear) {
                    if (current -> data.year <= endYear) {
                        currentValue = round(current -> data.temperature);
                        values.at(currentValue)++;
                    }
                }
            }
        }
        current = current -> next;
    }
    
    for (int i = 0; i < 101; i++) {
        if (values.at(i) >= previousValue) {
            previousValue = values.at(i);
            mode = i;
        }
    }
    
    return mode;
}
