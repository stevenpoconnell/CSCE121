#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using std::string;

void readPrefs(string fileName, size_t ngames, int prefs[]);

void readPlan(string fileName, int plan[]);

size_t computeFunLevel(size_t start, size_t duration, int prefs[], int plan[]);

size_t findBestVacation(size_t duration, int prefs[], int plan[]);

#endif
