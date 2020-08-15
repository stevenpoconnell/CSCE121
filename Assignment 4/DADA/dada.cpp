/*
DADA function definitions
*/

#include "dada.h"
#include <cmath>

int amax(const double x[], const unsigned int len) {
  if (len == 0) {
           return -1;
} else {
    int returnIndex = 0;
    double max = 0;
    unsigned int i;
    for (i = 0; i < len; i++) {
        if (abs(x[i]) > max) {
            max = abs(x[i]);
            returnIndex = i;
        }
    }
    return returnIndex;
  }
}

double asum(const double x[], const unsigned int len) {
    if (len == 0) {
        return 0;
    } else {
    unsigned int i = 0;
    double sum = 0;
    for (i = 0; i < len; i++) {
        sum += abs(x[i]);
    }
    return sum;
    }
}

void axpy(const double a, const double x[], double y[], const unsigned int len) {
    unsigned int i;
    for (i = 0; i < len; i++) {
       y[i] = (a * x[i]) + y[i];
    }
}

void copy(const double src[], double dest[], const unsigned int len) {
    unsigned int i;
    for (i = 0; i < len; i++) {
       dest[i] = src[i];
       }
}

double dot(const double x[], const double y[], const unsigned int len) {
    unsigned int i = 0;
    double dotProduct = 0;
    for (i = 0; i < len; i++) {
        dotProduct += x[i] * y[i];
    }
    
    return dotProduct;
}

double norm2(const double x[], const unsigned int len) {
    unsigned int i = 0;
    double radicand = 0;
    double normal = 0;
    for (i = 0; i < len; i++) {
        radicand += (x[i] * x[i]);
    }
    normal = sqrt(radicand);
    return normal;
}

void scale(const double a, double x[], const unsigned int len) {
    unsigned int i = 0;
    
    for (i = 0; i < len; i++) {
        x[i] *= a;
    }
}

void swap(double x[], double y[], const unsigned int len) {
        unsigned int i = 0;
        double temp[10];
    
        for (i = 0; i < len; i++) {
            temp[i] = x[i];
            x[i] = y[i];
            y[i] = temp[i];
        }
}
