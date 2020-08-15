#include "TemperatureDatabase.h"
#include "LinkedList.h"
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int currentYear = 2020;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}




void TemperatureDatabase::loadData(const string& filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Error: Unable to open " << filename << endl;
    }
    else {
        
        while (!fin.eof()) {
            string location = "";
            int year = 0;
            int month = 0;
            double temp = 0.0;

            fin >> location >> year >> month >> temp;
            
            if (year < 1800 || year > currentYear) {
                cout << "Error: Invalid year " << year << endl;
            }
            if (month < 1 || month > 12) {
                cout << "Error: Invalid month " << month << endl;
            }
            if (temp == -99.99) {

            }
            else if (temp < -50 || temp > 50) {
                cout << "Error: Invalid temperature " << temp << endl;
            }
            records.insert(location, year, month, temp);
        }
    }
    fin.close();
}

// Do not modify
void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename);
	
	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}
	dataout << records.print();
}

void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function for part 2
	//  Leave it blank for part 1
}
