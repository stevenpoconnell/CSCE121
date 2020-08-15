#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    
    int dollarsGiven = 0, centsGiven = 0, totalAmount = 0;
    int numQuarters = 0, numDimes = 0;
    int numNickels = 0, numPennies = 0;
    
    cout << "Enter dollars: ";
    cin >> dollarsGiven;
    cout << "Enter cents: ";
    cin >> centsGiven;

    totalAmount = (dollarsGiven * 100) + centsGiven;
    // becuase 1 dollar = 100 cents
    
    numQuarters = totalAmount / 25;
    totalAmount = totalAmount % 25;
    numDimes = totalAmount / 10;
    totalAmount = totalAmount % 10;
    numNickels = totalAmount / 5;
    totalAmount = totalAmount % 5;
    numPennies = totalAmount / 1;
    
    cout << "Pennies: " << numPennies << endl;
    cout << "Nickels: " << numNickels << endl;
    cout << "Dimes: " << numDimes << endl;
    cout << "Quarters: " << numQuarters << endl;
    cout << "\nTotal coins used: ";
    cout << (numPennies + numNickels + numDimes + numQuarters) << endl;
}
