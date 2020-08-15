//
//  customer.hpp
//  HW6[Store_Backend_pt1]
//
//  Created by Steven O'Connell on 7/10/20.
//  Copyright © 2020 Steven O'Connell. All rights reserved.
//

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include "Product.h"
#include <vector>

class Customer {

private:
    int customerID;
    std::string customerName;
    bool credit;
    double balance;
    std::vector<Product> productsPurchased;
    
public:
    Customer(int customerID, std::string name, bool credit = false);
    int getID();
    std::string getName();
    void setName(std::string name);
    bool getCredit();
    void setCredit(bool hasCredit);
    double getBalance();
    void processPayment(double amount);
    void processPurchase (double amount, Product product);
    std::string getProductsPurchased();
};

std::ostream& operator<<(std::ostream os, const Customer& Customer);

#endif /* customer_h */
