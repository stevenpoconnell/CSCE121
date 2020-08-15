#include "Store.h"
#include <iostream>

using namespace std;

Store::Store(string name) : name(name) {
    if (name.length() == 0)
        throw runtime_error("Store name cannot be empty.");
}

string Store::getName() {
    return name;
}

void Store::setName(string name) {
    this -> name = name;
}


/*
Product& Store:: getProduct(int productID) {

    cout << "fixme" << endl;
    
}

*/

/*
 
 Customer& getCustomer(int customerID, string customerName, bool credit = false) {
 
 }
 
 */

/*
 
 Customer& getCustomer(int customerID) {
 
 }
 
 */

void takeShipment(int productID, int quantity, double cost) {
    
}





