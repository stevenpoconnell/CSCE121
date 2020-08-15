#include "functions.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

const int MAX_NB_GAMES = 200;

using std::ifstream;
using std::string;
using std::getline;
using std::cout;
using std::endl;
using std::runtime_error;



size_t computeFunLevel(size_t start, size_t duration, int prefs[], int plan[]) {
    
    
    if (start + duration  > 366) {
        throw std::invalid_argument("Invalid argument");
    }
    
    int funLevel = 0;
    
    for (size_t i = start; i < (start + duration); i++) {
        funLevel += prefs[plan[i]];
    }
    return funLevel;
}


size_t findBestVacation(size_t duration, int prefs[], int plan[]) {

    size_t optimalStart = 0;
    
    for (size_t i = 0; i < (366 - duration); i++) {
        
        computeFunLevel(i, duration, prefs, plan);
        computeFunLevel(i + 1, duration, prefs, plan);
        
        if (computeFunLevel(i + 1, duration, prefs, plan) > computeFunLevel(i, duration, prefs, plan)) {
           
            optimalStart = i + 1;
            
        } else {
           
            optimalStart = i;
        }
    }
    return optimalStart;
}


void readPrefs(string fileName, size_t ngames, int prefs[]) {
   
    for (size_t i = 0; i < ngames; i++) {
        prefs[i] = 0;
    }
    
    ifstream fin;
    fin.open(fileName);
    if(!fin.is_open()) {
        throw runtime_error("Invalid preferences file.");
    }

   if(fin.is_open())
   {
       int gameid, rating;
       
       while(!fin.eof())
       {
           fin >> gameid;
           fin >> rating;
           if(gameid >= 0 && gameid < MAX_NB_GAMES  && rating >=0 && rating <= 5)
           {
               prefs[gameid] = rating;
           }
            else if(fin.fail())
           {
               fin.clear();
           }
       }
       fin.close();
   }
}


void readPlan(string fileName, int plan[])
{
  
    for(int i = 1; i < 366; i++) {
       plan[i] = 0;
    }
   ifstream fin;
   fin.open(fileName);
    if (!fin.is_open()) {
        throw runtime_error("Invalid plan file.");
    }

  
   if(fin.is_open())
   {
        int day;
        int gameid;
      
        while(!fin.eof())
       {
           fin >> day;
           fin >> gameid;
           if(day >= 1 && day <= 366 && gameid >= 0 && gameid <= MAX_NB_GAMES)
           {
               plan[day] = gameid;
           } else if(fin.fail())
           {
               fin.clear();
               
           }
       }
         fin.close();
}
}

            


