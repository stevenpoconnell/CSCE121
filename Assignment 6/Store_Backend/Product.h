

#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>

class Product {

private:
    int id;
    int inventory;
    int numSold;
    double totalPaid;
    std::string name;
    std::string description;
    
public:
    Product(int, std::string);
    int getID();
    std::string getName();
    void setName(std::string);
    std::string getDescription();
    void setDescription(std::string);
    int getNumberSold();
    int getInventoryCount();
    double getTotalPaid();
    double getPrice(); // avoid integer division
    void addShipment(int, double);;
    void reduceInventory(int);
};

std::ostream& operator<<(std::ostream& os, const Product& product);

#endif /* Product_h */
