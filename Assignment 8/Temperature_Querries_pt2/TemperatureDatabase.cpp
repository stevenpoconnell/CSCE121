#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
#include "TemperatureDatabase.h"
#include "TemperatureData.h"

using namespace std;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	// Implement this function for part 1
	ifstream dataIn(filename);
	if (!dataIn.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}
	while (!dataIn.eof()) {
		string line, location;
		int year=0, month=0;
		double temperature=0.0;
		getline(dataIn, line);
		stringstream ss(line);
		ss >> location >> year >> month >> temperature;
		if (ss.bad() || ss.fail()) {
			if (line.size() != 0) // ignore blank lines in file
				cout << "Error: Other invalid input " << line << endl;
		}
		else {
			if (temperature != -99.99) { // check for special case
				// validate inputs
				bool valid = true;
				if (!TemperatureData::validYear(year)) {
					valid = false;
					cout << "Error: Invalid year " << year << endl;
				}
				if (!TemperatureData::validMonth(month)) {
					valid = false;
					cout << "Error: Invalid month " << month << endl;
				}
				if (!TemperatureData::validTemperature(temperature)) {
					valid = false;
					cout << "Error: Invalid temperature " << temperature << endl;
				}
				if (valid)
					records.insert(location,year,month,temperature);
			}
			// else do nothing
		}
	}
    dataIn.close();
}

void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function for part 2
    ofstream ofs("result.dat");
    string line = "";
    string query = "";
    string location;
    int startYear;
    int endYear;
    
    ifstream ifs;
    ifs.open(filename);
    
    if (!ifs.is_open()) {
        cout << "Error: unable to open " << filename << endl;
    }
    
   
    
    
    while (getline(ifs, line)) {
        istringstream iss(line);
        iss >> location >> query >> startYear >> endYear;
        
        if (iss.fail()) {
            cout << "Error: Other invalid query" << endl;
        }
        else {
            if (startYear > endYear || startYear < 1800 || startYear > 2020 || endYear < 1800 || endYear > 2020) {
                cout << "Error: Invalid range " << startYear << "-" << endYear << endl;
            }
            if (query != "MODE" && query != "AVG") {
                cout << "Error: Unsupported query " << query << endl;
            }
        }
        
        ofs << location << " " << startYear << " " << endYear << " " << query << " ";
        
        if( query == "AVG") {
            double average = -9999;
            average = records.getAvg(location, startYear, endYear);
            if (TemperatureData::validTemperature(average) == false)
                ofs << "unknown" << endl;
            else
                ofs << average << endl;
        }
        else if (query == "MODE") {
            int mode = -9999;
            mode = records.getMode(location, startYear, endYear);
            
            if (TemperatureData::validTemperature(mode) == false)
                ofs << "unknown" << endl;
            else
                ofs << mode << endl;
        }
    }
    ofs.close();
}

void TemperatureDatabase::myTest() {
}
