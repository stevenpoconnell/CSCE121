#include "functions.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "provided.hpp"


using std::ifstream;
using std::string;
using std::getline;
using std::cout;
using std::endl;
using std::runtime_error;
using std::cin;
using std::cout;
using std::endl;

int main() {
    size_t ngames = 0;
    size_t duration = 0;
    size_t start = 0;
    string fileName;
    string gameTitles[MAX_NB_GAMES];
    int prefs[MAX_NB_GAMES];
    int plan[366];
    
    cout << "Please enter the number of games: ";
    cin >> ngames;
    cout << "Please enter the duration: ";
    cin >> duration;
    
    if ((!(ngames > 0 && ngames <= MAX_NB_GAMES)) || (!(duration > 0 && duration <= 365))) {
            
            cout << "Invalid input." << endl;
        }
        
        if (((ngames > 0 && ngames <= MAX_NB_GAMES)) && ((duration > 0 && duration <= 365))) {
            
            ifstream fin;
            cout <<  "Please enter name of file with titles: ";
            cin >> fileName;
            
            try {
                fin.open(fileName);
                if (!fin.is_open()) {
                    throw std::runtime_error("Invalid titles file.");
                    }
                
                readGameTitles(fileName, ngames, gameTitles);
            
                cout << "Please enter name of file with preferences: ";
                cin >> fileName;
                
                fin.open(fileName);
                if (!fin.is_open()) {
                    throw std::runtime_error("Invalid prefs file.");
                    }
                readPrefs(fileName, ngames, prefs);
                
                cout << "Please enter name of file with plan: ";
                cin >> fileName;
                
                fin.open(fileName);
                if (!fin.is_open()) {
                    throw std::runtime_error("Invalid plan file.");
                }
                readPlan(fileName, plan);
            }
            
            catch (std::runtime_error& excpt) {
                cout << excpt.what() << endl;
                return -1;
            }
        }
                    
        start = findBestVacation(duration, prefs, plan);
        cout << "\nBest start day is " << start << endl;
        cout << "Games to be played:";
        printGamesPlayedInVacation(start, duration, plan, gameTitles, ngames);
        cout << endl;
}
                

