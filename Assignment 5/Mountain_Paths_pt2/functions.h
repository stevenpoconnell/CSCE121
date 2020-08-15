#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<vector>

int colorPath(const std::vector<std::vector<int> >& elevations, std::vector<std::vector<int> >& r, std::vector<std::vector<int> >& g, std::vector<std::vector<int> >& b, int color_r, int color_g,
int color_b, int start_row);

int computePathDistance(const std::vector<std::vector<int> > map, int row);

int findShortestPath(const std::vector<int> paths);

std::vector<std::vector<int> > generateMapVector(int a, int b);

int findMinimumValue(std::vector<std::vector<int> > vec, int b, int c);

int findMaximumValue(std::vector<std::vector<int> > vec, int b, int c);

#endif
