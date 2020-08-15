#include <vector>
#include <iostream>
#include "functions.h"

using namespace std;

int computePathDistance(const vector<vector<int> > map, int row) {
    int pathDistance = 0;
    int cr = row;       // current row
    int cc = 0;         // current column
    int changeUp = 0, changeStraight = 0, changeDown = 0;
    
    
    while (cc < map.at(0).size() - 1) {
    if (cr == 0) {
        changeStraight = abs(map.at(cr).at(cc) - map.at(cr).at(cc + 1));
        changeDown = abs(map.at(cr).at(cc) - map.at(cr + 1).at(cc + 1));
        
        if (changeStraight <= changeDown) {
            cc++;
            pathDistance += changeStraight;
        }
        else {
            cr++;
            cc++;
            pathDistance += changeDown;
        }
    }
    else if (cr == map.size() - 1) {
        changeUp = abs(map.at(cr).at(cc) - map.at(cr - 1).at(cc + 1));
        changeStraight = abs(map.at(cr).at(cc) - map.at(cr).at(cc + 1));
        
        if (changeStraight <= changeUp) {
            cc++;
            pathDistance += changeStraight;
        }
        else {
            cr--;
            cc++;
            pathDistance += changeUp;
        }
        
    }
    else {              //i.e) in between the first and last rows in the map
        changeUp = abs(map.at(cr).at(cc) - map.at(cr - 1).at(cc + 1));
        changeStraight = abs(map.at(cr).at(cc) - map.at(cr).at(cc + 1));
        changeDown = abs(map.at(cr).at(cc) - map.at(cr + 1).at(cc + 1));
        
        if (changeUp == changeStraight && changeUp == changeDown) {
            cc++;
            pathDistance += changeStraight;
        } else if (changeStraight <= changeUp && changeStraight < changeDown) {
            cc++;
            pathDistance += changeStraight;
        }
        else if (changeStraight <= changeDown && changeStraight < changeUp) {
            cc++;
            pathDistance += changeStraight;
        }
        else if (changeUp < changeStraight && changeUp < changeDown) {
            cr--;
            cc++;
            pathDistance += changeUp;
        }
        else if (changeDown <= changeUp && changeDown < changeStraight) {
            cr++;
            cc++;
            pathDistance += changeDown;
            
        }
    }
    }
    return pathDistance;
    
}

int findShortestPath(const vector<int> paths) {
    int shortPath = paths.at(0);
    int index = 0;
    
    for (int i = 1; i < paths.size() - 1; i++) {
        if (paths.at(i) < shortPath) {
            shortPath = paths.at(i);
            index = i;
        }
    }
    return index;
}



int colorPath(const vector<vector<int>>& heightMap, vector<vector<int> >& r, vector<vector<int> >& g, vector<vector<int> >& b, int color_r, int color_g, int color_b, int start_row) {
    
	int dist = 0;
    
    int cr = start_row;       // current row
    int cc = 0;         // current column
    int changeUp = 0, changeStraight = 0, changeDown = 0;
    
    r.at(cr).at(0) = color_r;
    g.at(cr).at(0) = color_g;
    b.at(cr).at(0) = color_b;
    
    while (cc < heightMap.at(0).size() - 1) {
    if (cr == 0) {
        changeStraight = abs(heightMap.at(cr).at(cc) - heightMap.at(cr).at(cc + 1));
        changeDown = abs(heightMap.at(cr).at(cc) - heightMap.at(cr + 1).at(cc + 1));
        
        if (changeStraight <= changeDown) {
            cc++;
            r.at(cr).at(cc) = color_r;
            g.at(cr).at(cc) = color_g;
            b.at(cr).at(cc) = color_b;
        }
        else {
            cr++;
            cc++;
            r.at(cr).at(cc) = color_r;
            g.at(cr).at(cc) = color_g;
            b.at(cr).at(cc) = color_b;
        }
    }
    else if (cr == heightMap.size() - 1) {
        changeUp = abs(heightMap.at(cr).at(cc) - heightMap.at(cr - 1).at(cc + 1));
        changeStraight = abs(heightMap.at(cr).at(cc) - heightMap.at(cr).at(cc + 1));
        
        if (changeStraight <= changeUp) {
            cc++;
            r.at(cr).at(cc) = color_r;
            g.at(cr).at(cc) = color_g;
            b.at(cr).at(cc) = color_b;
        }
        else {
            cr--;
            cc++;
            r.at(cr).at(cc) = color_r;
            g.at(cr).at(cc) = color_g;
            b.at(cr).at(cc) = color_b;
        }
        
    }
    else {              //i.e) in between the first and last rows in the map
        changeUp = abs(heightMap.at(cr).at(cc) - heightMap.at(cr - 1).at(cc + 1));
        changeStraight = abs(heightMap.at(cr).at(cc) - heightMap.at(cr).at(cc + 1));
        changeDown = abs(heightMap.at(cr).at(cc) - heightMap.at(cr + 1).at(cc + 1));
        
        if (changeUp == changeStraight && changeUp == changeDown) {
            cc++;
            r.at(cr).at(cc) = color_r;
            g.at(cr).at(cc) = color_g;
            b.at(cr).at(cc) = color_b;
        } else if (changeStraight <= changeUp && changeStraight < changeDown) {
            cc++;
            r.at(cr).at(cc) = color_r;
            g.at(cr).at(cc) = color_g;
            b.at(cr).at(cc) = color_b;
        }
        else if (changeStraight <= changeDown && changeStraight < changeUp) {
            cc++;
            r.at(cr).at(cc) = color_r;
            g.at(cr).at(cc) = color_g;
            b.at(cr).at(cc) = color_b;
        }
        else if (changeUp < changeStraight && changeUp < changeDown) {
            cr--;
            cc++;
            r.at(cr).at(cc) = color_r;
            g.at(cr).at(cc) = color_g;
            b.at(cr).at(cc) = color_b;
        }
        else if (changeDown <= changeUp && changeDown < changeStraight) {
            cr++;
            cc++;
            r.at(cr).at(cc) = color_r;
            g.at(cr).at(cc) = color_g;
            b.at(cr).at(cc) = color_b;
        }
    }
    }
    dist = computePathDistance(heightMap, start_row);
    return dist;
}


vector<vector<int> > generateMapVector(int a, int b) {
    
    vector<vector<int> > vec(a, vector<int> (b, 0));
    return vec;
}


int findMinimumValue(vector<vector<int> > vec, int b, int c) {
   
    int minVal = vec.at(0).at(0);
    
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < c; j++) {
            if (vec.at(i).at(j) < minVal) {
                minVal = vec.at(i).at(j);
            }
        }
    }
    return minVal;
}


int findMaximumValue(vector<vector<int> > vec, int b, int c) { // b and c are just for iteration
   
    int maxVal = vec.at(0).at(0);
    
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < c; j++) {
            if (vec.at(i).at(j) > maxVal) {
                maxVal = vec.at(i).at(j);
            }
        }
    }
    return maxVal;
}

