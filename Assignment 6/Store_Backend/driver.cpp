#include <iostream>
#include "Product.h"
#include "Store.h"
#include "Customer.h"

using namespace std;

int main() {
    
    /*
    try {
        Product p(32498, "Coozie");
        p.setDescription("A great way to keep a beverage cold.");
        
        cout << "Product Name: " << p.getName() << endl;
        cout << "Product ID: " << p.getID() << endl;
        cout << "Product Description: " << p.getDescription() << endl;
        
        //Product q(183, "Tom");
        //cout << "q (id): " << q.getID() << endl;
        //cout << "sdq (name): " << q.getName() << endl;
        
        //Product badP(222, "");
        //cout << "badP (id): " << badP.getID() << endl;
        //cout << "badP (name): " << badP.getName() << endl;
        
        //p.setName("Jill Extreme");
        //cout << "p (name): " << p.getName() << endl;
        
        //q.setName("");
        //cout << "q (name): " << q.getName() << endl;
       
        
        /*
        cout << "Before 1st shipment" << endl;
        cout << "inventory: " << p.getInventoryCount() << endl;
        cout << "totalPaid: " << p.getTotalPaid() << endl;

        p.addShipment(88, 230.44);

        cout << "After 1st shipment" << endl;
        cout << "inventory: " << p.getInventoryCount() << endl;
        cout << "totalPaid: " << p.getTotalPaid() << endl;
        
        p.addShipment(133, 142.11);
        
        cout << "After 2nd shipment" << endl;
        cout << "inventory: " << p.getInventoryCount() << endl;
        cout << "totalPaid: " << p.getTotalPaid() << endl;
        
        // cout << "Testing negative quantity" << endl;
        
        // p.addShipment(-5, 22.55);
        
        // cout << "Testing negative shipment cost" << endl;
        
        // p.addShipment(5, -22.55);
         
         */
    
    /*
        p.addShipment(10, 150);
        
    }
    catch (runtime_error& exc) {
        cout << "Exception caught: "<< exc.what() << endl;
    }
        
        */
    
    
    // testing Customer output
    try {
        Customer c(128002247, "Steven O'Connell");
        Product p(32498, "Coozie");
        Product a(12345, "Aggie Socks");
        c.setCredit(true);
        c.processPurchase(3, p);
        
        Customer::productsPurchased.push_back(c);
        Customer::productsPurchased.push_back(a);
        
        cout << c.getProductsPurchased() << endl;
        
        cout << "TESTING: \n\nproducts in the vector after 2 purchases: " << endl;
        cout << c.getProductsPurchased() << endl;
        
        cout << "Customer name: " << c.getName() << endl;
        cout << "Customer ID: " << c.getID() << endl;
        cout << "Has credit : ";
        if (c.getCredit() == true)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        
        cout << "Balance: " << c.getBalance() << endl;
        cout << "Products purchased -- " << c.getProductsPurchased() << endl;
        
    }
    catch (runtime_error& exc) {
        cout << "Exception caught: " << exc.what() << endl;
    }
}
