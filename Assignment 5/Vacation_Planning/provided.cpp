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
using std::size_t;

void readGameTitles(const string& fileName, const size_t ngames, string gameTitles[MAX_NB_GAMES]) {
    ifstream fin(fileName);
    if (!fin.is_open()) {  // error in opening the file
        throw runtime_error("Invalid titles file.");
    }

    for (size_t game = 0; game < MAX_NB_GAMES; game++) {
        gameTitles[game] = "Unknown Title";
    }

    size_t gameid;
    string title;
    while (!fin.eof()) {  // while not at the end of the file
        fin >> gameid;
        if (fin.good()) {  // no error reading integer game
            // read title as the rest of the line
            if (gameid < ngames) {
                // valid game
                // consume space
                char space;
                fin >> std::noskipws >> space;
                getline(fin, gameTitles[gameid]);
            } else {
                // ignoring invalid gameid, just consume title
                getline(fin, title);
            }
        } else {
            // read the rest of the line and ignore it
            fin.clear();
            getline(fin, title);
        }
    }
}

void printGamesPlayedInVacation(const size_t start, const size_t duration, int plan[], const string gameTitles[MAX_NB_GAMES], const size_t ngames) {
    bool title_included[MAX_NB_GAMES];
    for (size_t game = 0; game < ngames; game++) {
        title_included[game] = false;
    }
    for (size_t day = start; day < start + duration && day < 366; day++) {
        size_t gameid = plan[day];
        if (gameid < ngames && !title_included[gameid]) {
            cout << gameTitles[gameid] << endl;
            title_included[gameid] = true;
        }
    }
}
