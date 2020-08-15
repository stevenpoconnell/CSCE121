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
      image[col][row] = {0, 0, 0 };
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



int loadVerticalSeam(Pixel** image, int start_col, int width, int height, int* seam) {
    int straight = 0;
    int left = 0;
    int right = 0;
    int totalEnergy = 0;
    
    totalEnergy = energy(image, start_col, 0, width, height);
    seam[0] = start_col;
    
    // your prespective of what constitutes left and right is wrong according to the prompt
    // but conceptually (for you) it's right
 
    for (int i = 1; i < height; i++) {
        if (start_col == 0) {
            straight = energy(image, start_col, i, width, height);
            right = energy(image, start_col +1, i, width, height);
            left = straight + right;
        }
        else if (start_col == width -1) {
            straight = energy(image, start_col, i, width, height);
            left = energy(image, start_col - 1, i, width, height);
            right = left + straight;
        } else {
            straight = energy(image, start_col, i, width, height);
            left = energy(image, start_col - 1, i, width, height);
            right = energy(image, start_col + 1, i, width, height);
        }
        
        if ( left < straight && left < right) { //left strictly less than..
            start_col--;
            seam[i] = start_col;
            totalEnergy += left;
        }
        else if ( straight < left && straight < right) { //straight strictly less than...
            seam[i] = start_col;
            totalEnergy += straight;
        }
        else if (right < left && right < straight) { // right striclty less than...
            start_col++;
            seam[i] = start_col;
            totalEnergy += right;
        }
        else if (left == straight && left < right) { // >1 pixel with min energy value (pref: straight, right)
            seam[i] = start_col;
            totalEnergy += straight;
        }
        else if (straight == right && straight < left) { // >1 pixel with min energy value (pref: straight, right)
            seam[i] = start_col;
            totalEnergy += straight;
        }
        else if (left == right && left < straight) { // >1 pixel with min energy value (pref: straight, right)
            start_col++;
            seam[i] = start_col;
            totalEnergy += right;
        } else if (left == straight && straight == right) {
            seam[i] = start_col;
            totalEnergy += straight;
        }
        }
    
    return totalEnergy;
}

// Extra Credit: Do later

 int loadHorizontalSeam(Pixel** image, int start_row, int width, int height, int* seam) {
   int straight = 0;
      int left = 0;
      int right = 0;
      int totalEnergy = 0;
      
      totalEnergy = energy(image, start_row, 0, width, height);
      seam[0] = start_row;
   
      for (int i = 1; i < width; i++) {
          if (start_row == 0) {
              straight = energy(image, start_row, i, width, height);
              right = energy(image, start_row + 1, i, width, height);
              left = straight + right;
          }
          else if (start_row == height - 1) {
              straight = energy(image, start_row, i, width, height);
              left = energy(image, start_row - 1, i, width, height);
              right = left + straight;
          } else {
              straight = energy(image, start_row, i, width, height);
              left = energy(image, start_row - 1, i, width, height);
              right = energy(image, start_row + 1, i, width, height);
          }
          
          if ( left < straight && left < right) {
              start_row--;
              seam[i] = start_row;
              totalEnergy += left;
          }
          else if ( straight < left && straight < right) {
              seam[i] = start_row;
              totalEnergy += straight;
          }
          else if (right < left && right < straight) {
              start_row++;
              seam[i] = start_row;
              totalEnergy += right;
          }
          else if (left == straight && left < right) { // >1 pixel with min energy value (pref: straight, left)
              seam[i] = start_row;
              totalEnergy += straight;
          }
          else if (straight == right && straight < left) { // >1 pixel with min energy value (pref: straight, left)
              seam[i] = start_row;
              totalEnergy += straight;
          }
          else if (left == right && left < straight) { // >1 pixel with min energy value (pref: straight, left)
              start_row++;
              seam[i] = start_row;
              totalEnergy += right;
          } else if (left == straight && straight == right) {
              seam[i] = start_row;
              totalEnergy += straight;
          }
          }
      
      return totalEnergy;
  }



 
int* findMinVerticalSeam(Pixel** image, int width, int height) {
    int* min_Energy_Seam = new int[height];
    int* seam = new int[height];
    int min_Energy = 0;
    int current_Energy = 0;
    
    min_Energy = loadVerticalSeam(image, 0, width, height, seam);
    current_Energy = -1;
    
    for (int i = 0; i < height; i++) {
        min_Energy_Seam[i] = seam[i];
    }
    for (int i = 0; i < width; i++) {
        current_Energy  = loadVerticalSeam(image, i, width, height, seam);
        if (current_Energy < min_Energy) {
            min_Energy = current_Energy;
            for (int i = 0; i < height; i++) {
                min_Energy_Seam[i] = seam[i];
            }
        }
    }
 
    
    delete [] seam;
    seam = nullptr;
   
    
    return min_Energy_Seam;
}
        

// Extra Credit - Do later

 int* findMinHorizontalSeam(Pixel** image, int width, int height) {
  int* min_Energy_Seam = new int[width];
     int* seam = new int[width];
     int min_Energy = 0;
     int current_Energy = 0;
     
     min_Energy = loadHorizontalSeam(image, 0, width, height, seam);
     current_Energy = -1;
     
     for (int i = 0; i < width; i++) {
         min_Energy_Seam[i] = seam[i];
     }
     for (int i = 0; i < height; i++) {
         current_Energy  = loadHorizontalSeam(image, i, width, height, seam);
         if (current_Energy < min_Energy) {
             min_Energy = current_Energy;
             for (int i = 0; i < width; i++) {
                 min_Energy_Seam[i] = seam[i];
             }
         }
     }
  
     
     delete [] seam;
     seam = nullptr;
    
     
     return min_Energy_Seam;
}

 
void removeVerticalSeam(Pixel** image, int width, int height, int* verticalSeam) {
    Pixel temp;
    
    for (int i = 0; i < height; i++) {
        temp = image[verticalSeam[i]][i];
        
        for (int j = verticalSeam[i]; j < width -1; j++) {
            image[j][i] = image[j + 1][i];
        }
        
        image[width - 1][i] = temp;
    }
}

// Extra Credit - do later

void removeHorizontalSeam(Pixel** image, int width, int height, int* horizontalSeam) {
    Pixel temp;
    
    for (int i = 0; i < width; i++) {
        temp = image[i][horizontalSeam[i]];
        
        for (int j = horizontalSeam[i]; j < height -1; j++) {
            image[j][i] = image[j + 1][i];
        }
        
        image[i][height - 1]= temp;
    }
}
 
 
