#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;

int main() {
  string filename;
  int width = 0;
  int height = 0;
  int originalWidth = 0;
  int originalHeight = 0;
  int targetWidth = 0;
  int targetHeight = 0;
  
  // Add code to validate input (Do in part 1)
    
    
  cout << "Input filename: ";
  cin >> filename;
    ifstream fin;
    fin.open(filename);
    if (!fin.is_open()) {
        cout << "Error: Invalid file.";
        return -1;
    }
  cout << "Input width and height: ";
    cin >> width;
    if(cin.fail()) {
        cout << "Error: width is a non-integer value";
        return -1;
    }
    if (width <= 0) {
        cout << "Error: width must be greater than 0. You entered " << width;
        return -1;
    }
    cin >> height;
    if (cin.fail()) {
        cout << "Error: height is a non-integer value";
        return -1;
    }
    if (height <= 0) {
        cout << "Error: height must be greater than 0. You entered " << height;
        return -1;
    }
    
  cout << "Input target width and target height: ";
    cin >> targetWidth;
    if (cin.fail()) {
        cout << "Error: target width is a non-integer value";
        return -1;
    }
    
    if(targetWidth <= 0) {
        cout << "Error: target width must be greater than 0. You entered " << targetWidth;
        return -1;
    }

    if(targetWidth > width) {
        cout << "Error: target width must be less than width, ";
        cout << targetWidth << " is greater than " << width;
        return -1;
    }
    
    cin >> targetHeight;
    if (cin.fail()) {
        cout << "Error: target height is a non-integer value";
        return -1;
    }
    
    if (targetHeight <= 0) {
        cout << "Error: target height must be greater than 0. You entered " << targetHeight;
        return -1;
    }
    
    if (targetHeight > height) {
        cout << "Error: target height must be less than height, ";
        cout << targetHeight << " is greater than " << height;
        return -1;
    }
  
  originalWidth = width; // need to delete image array at end of program
  originalHeight = height;

  Pixel** image = createImage(width, height); // create array of size that we need
  if (image != nullptr) {
    if (loadImage(filename, image, width, height)) {
      cout << "Start carving..." << endl;
      
      // Add code to remove seams from image (Do in part 2)

      // set up output filename
      stringstream ss;
      ss << "carved" << width << "X" << height << "." << filename;
      outputImage(ss.str().c_str(), image, width, height);
    } else {
        return -1;
    }
  }
  
    // call last to remove the memory from the heap
    deleteImage(image, originalWidth);
  }
  // else 
  


