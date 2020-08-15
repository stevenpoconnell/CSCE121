//
//  Store.hpp
//  HW6[Store_Backend_pt1]
//
//  Created by Steven O'Connell on 7/10/20.
//  Copyright © 2020 Steven O'Connell. All rights reserved.
//

#ifndef STORE_H
#define STORE_H

#include <iostream>
#include "Customer.h"
#include "Product.h"

class Store {
    
private:
    std::string name;
    std::vector<Product> products;
    std::vector<Customer> customers;
    
public:
    Store();
    Store(std::string name);
    std::string getName();
    void setName(std::string name);
    void addProduct(int productID, std::string productName);
    Product& getProduct(int productID);
    void addCustomer(int customerID, std::string customerName, bool credit = false);
    Customer& getCustomer(int customerID);
    void takeShipment(int productID, int quantity, double cost);
    void takepayment(int customerID, double amount);
    void sellProduct(int customerID, int productID, int quantity);
    std::string listProducts();
    std::string listCustomer(); // Use overloaded output operator for Customer;
    
    
};


#endif /* Store_h */
