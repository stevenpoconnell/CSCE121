#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;

Pixel** createImage(int width, int height) {
  cout << "Start createImage... " << endl;
  
  // Create a one dimensional array on the heap of pointers to Pixels 
  //    that has width elements (i.e. the number of columns)
  Pixel** image = new Pixel*[width];
  
  bool fail = false;
  
  for (int i=0; i < width; ++i) { // loop through each column
    // assign that column to a one dimensional array on the heap of Pixels
    //  that has height elements (i.e. the number of rows)
    image[i] = new Pixel[height];
    
    if (image[i] == nullptr) { // failed to allocate
      fail = true;
    }
  }
  
  if (fail) { // if any allocation fails, clean up and avoid memory leak
    // deallocate any arrays created in for loop
    for (int i=0; i < width; ++i) {
      delete [] image[i]; // deleting nullptr is not a problem
    }
    delete [] image; // dlete array of pointers
    return nullptr;
  }
  
  // initialize cells
  //cout << "Initializing cells..." << endl;
  for (int row=0; row<height; ++row) {
    for (int col=0; col<width; ++col) {
      //cout << "(" << col << ", " << row << ")" << endl;
      image[col][row] = { 0, 0, 0 };
    }
  }
  cout << "End createImage... " << endl;
  return image;
}

void deleteImage(Pixel** image, int width) {
  cout << "Start deleteImage..." << endl;
  // avoid memory leak by deleting the array
  for (int i=0; i<width; ++i) {
    delete [] image[i]; // delete each individual array placed on the heap
  }
  delete [] image;
  image = nullptr;
}

// implement for part 1

int* createSeam(int length) {
    int* seam = new int[length];
    for (int i = 0; i < length; i++) {
        seam[i] = 0;
    }
    return seam;
}

void deleteSeam(int* seam) {
    delete[] seam;
}

bool loadImage(string filename, Pixel** image, int width, int height) {
    cout << "Loading image..." << endl;
    ifstream fin(filename);
    if(!fin.is_open()) {
        cout << "Error: failed to open input file - " << filename;
        return false;
    }
    
    char type[3];
    fin >> type;
    if ((toupper(type[0] != 'P') || toupper(type[1] != '3'))) {
        cout << "Error: type is " << type[0] << type[1] << " instead of P3";
        return false;
    }
    
    int preambleWidth = 0;
    int preambleHeight = 0;
        
    fin >> preambleWidth;
    if (fin.fail()) {
        cout << "Error: read non-integer value";
        return false;
    }
        
    fin >> preambleHeight;
    if (fin.fail()) {
        cout << "Error: read non-integer value";
        return false;
    }
    
    if (preambleWidth != width) {
        cout << "Error: input width (" << width << ") does not match ";
        cout << "value in file (" << preambleWidth << ")";
        return false;
    }
        
    if (preambleHeight != height) {
        cout << "Error: input height (" << height << ") does not match ";
        cout << "value in file (" << preambleHeight << ")";
        return false;
    }
    
    int maxColor = 0;
    fin >> maxColor;
    if (fin.fail()) {
        cout << "Error: read non-integer value";
        return false;
    }
    
    int rows = 0;
    int cols = 0;
    
    for (rows = 0; rows < height; rows++) {
        for (cols = 0; cols < width; cols++) {
            int colorValue = 0;
            
            if (!(fin >> std::ws).eof()) {
                fin >> colorValue;
                if (fin.fail()) {
                    cout << "Error: read non-integer value";
                    return false;
                }
            
                if ((colorValue < 0) || (colorValue > 255)) {
                    cout << "Error: invalid color value " << colorValue;
                    return false;
                }
            
                image[cols][rows].r = colorValue;
            } else {
                cout << "Error: not enough color values";
                return false;
            }
            
            if (!(fin >> std::ws).eof()) {
                fin >> colorValue;
                if (fin.fail()) {
                    cout << "Error: read non-integer value";
                    return false;
                }
            
                if ((colorValue < 0) || (colorValue > 255)) {
                    cout << "Error: invalid color value " << colorValue;
                    return false;
                }
            
                image[cols][rows].g = colorValue;
            } else {
                cout << "Error: not enough color values";
                return false;
            }
            
            if (!(fin >> std::ws).eof()) {
                fin >> colorValue;
                if (fin.fail()) {
                    cout << "Error: read non-integer value";
                    return false;
                }
            
                if ((colorValue < 0) || (colorValue > 255)) {
                    cout << "Error: invalid color value " << colorValue;
                    return false;
                }
            
                image[cols][rows].b = colorValue;
            } else {
                cout << "Error: not enough color values";
                return false;
            }
        }
    }
    if (!(fin >> std::ws).eof()) {
        cout << "Error: too many color values";
        return false;
    }
    
    return true;
}

bool outputImage(string filename, Pixel** image, int width, int height) {
    ofstream fout(filename);
    cout << "Outputting image..." << endl;
    if (!fout.is_open()) {
        cout << "Error: failed to open out file - " << filename;
        return false;
    }
    
    fout << "P3" << endl;
    fout << width << " " << height << endl;
    fout << "255" << endl;
    
    for (int rows = 0; rows < height; rows++) {
        for (int cols = 0; cols < width; cols++) {
            fout << image[cols][rows].r << " ";
            fout << image[cols][rows].g << " ";
            fout << image[cols][rows].b << " ";
        }
        fout << endl;
    }

    return true;
}

int energy(Pixel** image, int x, int y, int width, int height) {
    int lowerCoordx = (x - 1 >= 0) ? (x - 1) : (width - 1);
    int upperCoordx = (x + 1 < width) ? (x + 1) : 0;
    int deltaRx = abs(image[upperCoordx][y].r - image[lowerCoordx][y].r);
    int deltaGx = abs(image[upperCoordx][y].g - image[lowerCoordx][y].g);
    int deltaBx = abs(image[upperCoordx][y].b - image[lowerCoordx][y].b);
    
    int Grad_x = pow(deltaRx, 2) + pow(deltaGx, 2) + pow(deltaBx, 2);
    
    int lowerCoordy = (y - 1 >= 0) ? (y - 1) : (height - 1);
    int upperCoordy = (y + 1 < height) ? (y + 1) : 0;
    int deltaRy = abs(image[x][upperCoordy].r - image[x][lowerCoordy].r);
    int deltaGy = abs(image[x][upperCoordy].g - image[x][lowerCoordy].g);
    int deltaBy = abs(image[x][upperCoordy].b - image[x][lowerCoordy].b);
    
    int Grad_y = pow(deltaRy, 2) + pow(deltaGy, 2) + pow(deltaBy, 2);
    
    int pixEnergy = Grad_x + Grad_y;

    return pixEnergy;
}

// implement for part 2

// uncomment for part 2
/* 

int loadVerticalSeam(Pixel** image, int start_col, int width, int height, int* seam) {
  return 0;
}

int loadHorizontalSeam(Pixel** image, int start_row, int width, int height, int* seam) {
  return 0;
}

int* findMinVerticalSeam(Pixel** image, int width, int height) {
  return nullptr;
}

int* findMinHorizontalSeam(Pixel** image, int width, int height) {
  return nullptr;
}

void removeVerticalSeam(Pixel** image, int width, int height, int* verticalSeam) {
}


void removeHorizontalSeam(Pixel** image, int width, int height, int* horizontalSeam) {
}
*/
