#ifndef TEST_FUNCTIONS_H
#define TEST_FUNCTIONS_H

#include <string>
#include "test_functions.h"

struct Pixel {
int r; // red
int g; // green
int b; // blue
};


Pixel** createImage(int width, int height);
void deleteImage(Pixel** image, int width);

int* createSeam(int length);
void deleteSeam(int* seam);
bool loadImage(std::string filename, Pixel** image, int width, int height);
bool outputImage(std::string filename, Pixel** image, int width, int height);
int energy(Pixel** image, int x, int y, int width, int height);

int loadVerticalSeam(Pixel** image, int start_col, int width, int height, int* seam);
int loadHorizontalSeam(Pixel** image, int start_row, int width, int height, int* seam);
int* findMinVerticalSeam(Pixel** image, int width, int height);
int* findMinHorizontalSeam(Pixel** image, int width, int height);
void removeVerticalSeam(Pixel** image, int width, int height, int* verticalSeam);
void removeHorizontalSeam(Pixel** image, int width, int height, int* horizontalSeam);


#endif


