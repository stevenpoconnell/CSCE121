#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include "functions.h"

using namespace std;


int main() {
    
    //Declarations/Initializations
    ifstream fin;
    ofstream fout;
    string fileName;
    int data = 0;
    int numRows = 0, numColumns = 0;
    int SoG = 0;                                     // Shade of Grey
    vector<int> dataStream;
    vector<vector<int>> map;
    vector<vector<int>> r;                           // Red value vector
    vector<vector<int>> g;                           // Green value vector
    vector<vector<int>> b;                           // Blue value vector
    int minElevation = 0, maxElevation = 0;
    // pt. 2 stuff
    vector<int> pathLengths;
    
    cout << "Enter the number of rows in the map: ";
    cin >> numRows;
    if (!(cin.good()) || numRows <=  0) {
        cout << "Error: Invalid input." << endl;
        return -1;
    }
    
    cout << "Enter the number of columns in the map: ";
    cin >> numColumns;
    if(!(cin.good()) || numColumns <= 0) {
        cout << "Error: Invalid input." << endl;
        return -1;
    }
    
    cout << "Enter the name of the file containing the map data: ";
    cin >> fileName;
    
    fin.open(fileName);
    
    if (!(fin.is_open())) {
        cout << "Error: File not found." << endl;
        return -1;
    }
    
    r = generateMapVector(numRows, numColumns);
    g = generateMapVector(numRows, numColumns);
    b = generateMapVector(numRows, numColumns);


    while (fin >> data) {
        if (fin.fail()) {
            cout << "Error: File contains invalid data..." << endl;
            return -1;
        }
        dataStream.push_back(data);
        if (dataStream.size() == numColumns) {
            map.push_back(dataStream);
            dataStream.clear();
        }
    }
    
    fin.close();
    
    if (map.size() != numRows || dataStream.size() != 0) {
        cout << "Error: More or less data than expected..." << endl;
        return -1;
    }
    
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            if (map.at(i).at(j) == 0) {
                
            }
        }
    }
    
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            
        }
    }
    
    minElevation = findMinimumValue(map, numRows, numColumns);
    maxElevation = findMaximumValue(map, numRows, numColumns);
    
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            
            SoG = round((map.at(i).at(j) - minElevation) * 255.0 /(maxElevation - minElevation));
            r.at(i).at(j) = SoG;
            g.at(i).at(j) = SoG;
            b.at(i).at(j) = SoG;
        }
    }
    
    // start of pt. 2 code
    
    for (int i = 0; i < map.size(); i++) {
        pathLengths.push_back( computePathDistance(map, i));
    }
    
    // cout << "The shortest path start at row " << findShortestPath(pathLengths) << endl;
    
    /*
    for (int i = 0; i < map.size(); i++) {
        r.at(i).at(0) = 252;
        g.at(i).at(0) = 25;
        b.at(i).at(0) = 63;
    }
    */
     
     
    for (int i = 0; i < map.size(); i++) {
        colorPath(map, r, g, b, 252, 25, 63, i);
    }
    
    /*
    int startIndex = findShortestPath(pathLengths);
    r.at(startIndex).at(0) = 31;
    g.at(startIndex).at(0) = 253;
    b.at(startIndex).at(0)
    
    */
     
    colorPath(map, r, g, b, 31, 253, 13, findShortestPath(pathLengths));
 
    fout.open(fileName + ".ppm");
    
    if (!(fout.is_open())) {
        cout << "Error: could not open or generate the file: " << fileName << endl;
        return -1;
    }
    
    fout << "P3" << endl;
    fout << numColumns << " " << numRows << endl;
    fout << "255" << endl;
    
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            fout << r.at(i).at(j) << " ";
            fout << g.at(i).at(j) << " ";
            fout << b.at(i).at(j) << " ";
        }
    }
    
}


