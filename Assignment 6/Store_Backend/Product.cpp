#include <iostream>
#include <string>
#include <stdexcept>
#include "Product.h"

using namespace std;

Product::Product(int id, string name) : id(id), name(name),
    inventory(0), numSold(0), totalPaid(0.0) /*, description("")*/ {
        if (name.length()==0)
            throw runtime_error("Product name cannot be empty.");
    }
    // Note a string's default constructor already sets the string to
    //   "" so we don't have to do that explicitly here
    //   I showed what it would look like but commented it out.

int Product::getID() {
    return id;
}

string Product::getName() {
    return name;
}

void Product::setName(std::string name) {
    if (name.length()==0)
        throw runtime_error("Product name cannot be empty.");
    this->name = name; // could use an else, but it will only get here
                       //   if there was not an exception!
}

string Product::getDescription() {
    return description;
}

void Product::setDescription(std::string description){
    this->description = description;
}

int Product::getNumberSold() {
    return numSold;
}

double Product::getTotalPaid() {
    return totalPaid;
}

int Product::getInventoryCount() {
    return inventory;
}

double Product::getPrice() {
    double price = ( (totalPaid * 1.0) / (inventory + numSold) ) * 1.25;
    
    if ( !(price > 0))
        throw runtime_error("Price must be positive.");
    return price;
}

void Product::addShipment(int shipmentQuantity, double shipmentCost) {
    if (shipmentQuantity < 0)
        throw runtime_error("Shipment quantity must be positive.");
    if (shipmentCost < 0)
        throw runtime_error("Shipment cost must be positive.");
    //cout << "quantity: " << quantity << endl;
    //cout << "inventory: " << inventory << endl;
    inventory += shipmentQuantity;
    totalPaid += shipmentCost;
}

void Product::reduceInventory(int purchaseQuantity) {
    if (inventory - purchaseQuantity < 0)
        throw runtime_error("Not enough inventory.");
    if (purchaseQuantity < 0)
        throw runtime_error("Purchase quantity must be positive.");
    inventory -= purchaseQuantity;
    numSold += purchaseQuantity;
}


std::ostream& operator<<(std::ostream& os, const Product& product) {
    return os;
}
