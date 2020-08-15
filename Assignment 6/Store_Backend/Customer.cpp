#include <iostream>
#include <stdexcept>
#include <sstream>
#include "Customer.h"

using namespace std;

ostringstream os;

Customer::Customer(int customerID, string name, bool credit) : customerID(customerID), customerName(name), credit(credit) {
    if (name.length() == 0)
        throw runtime_error("Customer name cannot be empty.");
}

int Customer::getID() {
    return customerID;
}

string Customer::getName() {
    return customerName;
}

void Customer::setName(string name) {
    if (name.length() == 0) {
        throw runtime_error("Customer name cannot be empty.");
    }
    this -> customerName = name;
}

bool Customer::getCredit() {
    if (credit == true)
        return true;
    else
        return false;
}

void Customer::setCredit(bool hasCredit) {
    credit = hasCredit;
}

double Customer::getBalance() {
    return balance;
}

void Customer::processPayment(double amount) {
    if (amount < 0)
        throw runtime_error("Payment must be positive.");
    balance += amount;
}

void Customer::processPurchase(double amount, Product product) {
    if (credit == true) {
        balance -= amount;
    }
    else if (balance >= amount) {
        balance -= amount;
    }
    else {
        throw runtime_error("Balance caannot be negative without credit.");
    }
    if (amount < 0) {
        throw runtime_error("Amount must be positive");
    }
    
    productsPurchased.push_back(product);
    
}

std::string Customer::getProductsPurchased() {

        for(int i = 0; i < productsPurchased.size(); i++) {
            os << productsPurchased.at(i) << endl;
        }

    string info = os.str();

    return info;
}

ostream& operator<<(ostream& os, const Customer& customer) {
    return os;
}

