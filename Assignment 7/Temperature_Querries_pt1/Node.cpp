#include <string>
#include "Node.h"

using namespace std;

// Default constructor
Node::Node() {
    next = nullptr;
} // remember to initialize next to nullptr

// Parameterized constructor
Node::Node(string id, int year, int month, double temperature) {
    // remember to initialize next to nullptr
    data.id = id;
    data.year = year;
    data.month = month;
    data.temperature = temperature;
    next = nullptr;
}

bool Node::operator<(const Node& b) {
    return this->data < b.data;
}



