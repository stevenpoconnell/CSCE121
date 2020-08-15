#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <algorithm>

using namespace std;


bool isCodeValid(vector<int> code) {
    int numDuplicates = 0;
    for (int i = 0; i < code.size() - 1; i++) {
        if (code.size() - i > 1)
            if (code.at(i) == code.at(i + 1)) {
                numDuplicates++;
            }
        }
    
    if (numDuplicates == 0) {
       // cout << "The digits must all be different numbers" << endl;
        return true;
    }
    else
        return false;
}

bool isGuessValid(vector<int> guess) {
    int numDuplicates = 0;
        for (int i = 0; i < guess.size() - 1; i++) {
            if (guess.size() - i > 1)
                if (guess.at(i) == guess.at(i + 1)) {
                    numDuplicates++;
                }
            }
        
        if (numDuplicates == 0) {
            return true;
        }
        else {
            //cout << "Each number must be different." << endl;
            return false;
        }
    }



int main() {
    
    srand(std::chrono::duration_cast<std::chrono::milliseconds>
     (std::chrono::system_clock::now().time_since_epoch()).count()%2000000000);
 
    vector<int> randomSet;
    vector<int> code;
    vector<int> guess;
    int setting = 1;
    int usrGuess = 0;
    int numBulls = 0, numCows = 0;
    int secretCode = 0, codeLength = 0, guessLength = 0;
    int digit = 0, number = 0;
    int digitCount = 0;
    bool code_is_good = false;
    bool guess_is_good = false;
    
    while (setting != 0 && setting != 3 && setting != 4 && setting != 5) {
        cout << "Enter number of digits in code (3, 4 or 5): ";
        cin >> setting;
    }

    
    
    
    if (setting == 0) {
        code_is_good = false;
        code.clear();
        while (code_is_good != true) {
            code.clear();
            cout << "Enter code: ";
            cin >> secretCode;
            number = secretCode;
            digit = number;
        
        //vector<int> code;
        
            while (number != 0) {
                digit = number % 10;
                code.push_back(digit);
                number /= 10;
                codeLength++;
            }
            
            while (codeLength > 5) {
                code.clear();
                codeLength = 0;
                cout << "You can't enter more than 5 digits." << endl;
                cout << "Enter code: ";
                cin >> secretCode;
                number = secretCode;
                digit = number;
            
                //vector<int> code;
                
                while (number != 0) {
                    digit = number % 10;
                    code.push_back(digit);
                    number /= 10;
                    codeLength++;
                }
            }

            cout << "Enter number of digits in code: ";
            cin >> digitCount;
            
            if (digitCount - codeLength > 1) {
               // cout << "Each number must be different." << endl;
                break;
            }
            else if (digitCount > codeLength) {
                for (int i = 0; i < (digitCount - codeLength); i++) {
                    code.push_back(0);
                }
            }
            else if (codeLength > digitCount) {
                cout << "You can only enter " << digitCount << " digits." << endl;
            }
                code_is_good = isCodeValid(code);
                if (code_is_good == false) {
                    codeLength = 0;
                    number = 0;
                    secretCode = 0;
                    digit = 0;
                    digitCount = 0;
                    cin.clear();
                    code.clear();
                }
        }
        //see note above, but by this point the leading 0s thing should be solves and code.size() should == setting;
        cout << "Number to guess: ";
        for (int i = digitCount - 1; i >= 1; i--) {
            cout << code.at(i) << "-";
        }
        cout << code.at(0) << endl;
        
        /*
        cout << "test to see the actual order of the vector" << endl;
        
        for (int i = 0; i < code.size() - 1; i++) {
            cout << code.at(i) << "-";
        }
        cout << code.at(code.size()-1) << endl;
         
         */
        
        
        
        
        //The following code in between the ****** was copied from the else statement below
        //i.e) what happens in the cases that setting = 3 or 4 or 5
        //***************************************************************************************
        while (numBulls != code.size()) {
            guess.clear();
            guess_is_good = false;
            while (guess_is_good != true) {
            cin.clear();
            guessLength = 0;
                guess.clear();
            numBulls = 0;
            numCows = 0;
            digit = 0;
                usrGuess = 0;
        cout << "Enter Guess: ";
              cin >> usrGuess;
          int temp1 = usrGuess;
          while (temp1 != 0) {
              guessLength++;
              temp1 /= 10;
          }
                while (usrGuess != 0) {
                    digit = usrGuess % 10;
                    guess.push_back(digit);
                    usrGuess /= 10;
                }
            
                if (guessLength < code.size()) {
                    for (int i = 0; i < (code.size() - guessLength); i++) {
                        guess.push_back(0);
                    }
                    reverse(guess.begin(), guess.end());
                }
          else if (guessLength > digitCount) {
              cout << "You can only enter " << digitCount << " digits." << endl;
              guess_is_good = false;
              guess.clear();
              cin.clear();
                }
          else{
              isGuessValid(guess);
                guess_is_good = isGuessValid(guess);
                if (guess_is_good == false) {
                    cout << "Each number must be different." << endl;
                    guess.clear();
                    cin.clear();
                }
          }
            }
            ///TEST
            /*
            cout << "\nthe actual guess vector looks like:\n";
            for (int i = 0; i < guess.size(); i++)
                cout << guess.at(i) << "-";
            cout << endl;
             */
            

        
        
        /*
              //test
              cout << "the user thinks the code is: ";
          for (int i = 0; i < code.size() - 1; i++) {
              cout << guess.at(i) << "-";
          }
        cout << guess.at(code.size() - 1) << endl;
        cout << "However, the actual code is: ";
        for (int i = 0; i < code.size() - 1; i++) {
            cout << code.at(i) << "-";
        }
        cout << code.at(code.size() - 1) << endl;
         
         */
        
        //****************************************************************************************
        
        for (int i = 0; i < guess.size(); i++) {
            if (guess.at(i) == code.at(i)) {
                numBulls++;
            }
            else if (count(code.begin(), code.end(), guess.at(i)) > 0) {
                numCows++;
            }
        }
            

            if (numBulls == digitCount) {
                cout << numBulls << " bulls... ";
                for (int i = digitCount - 1; i > 0; i--) {
                    cout << code.at(i) << "-";
                }
                cout << code.at(0) << " is correct!" << endl;
            } else {
        cout << numBulls << " bulls" << endl;
        cout << numCows << " cows" << endl;
        
            }
            guess.clear();


        }
    }
    
    else {
//********************************************************************************************************
//********************************************************************************************************
    //Code for settings = 3, 4 or 5
//********************************************************************************************************
//********************************************************************************************************
    
        randomSet.clear();
        for (int i = 0; i < 10; i++) {
            randomSet.push_back(i);
        }
        
        for (int i = 0; i <  (rand() % (rand() % 256) ) + 1; i++) {
            random_shuffle (randomSet.begin(), randomSet.end() );
        }
        
        for (int i = 0; i < setting; i++) {
             code.push_back(randomSet.at(i));
        }
        
        cout << "The number to guess is: ";
        for (int i = 0; i < setting - 1; i++) {
            cout << code.at(i) << "-";
        }
        cout << code.at(setting - 1) << endl;
        
        while (numBulls != code.size()) {
            guess.clear();
            guess_is_good = false;
            while (guess_is_good != true) {
                cin.clear();
                guess.clear();
                guessLength = 0;
                numBulls = 0;
                numCows = 0;
                digit = 0;
                usrGuess = 0;
                
                cout << "Enter guess: ";
                cin >> usrGuess;
                
                int temp2 = usrGuess;
                
                while (temp2 != 0) {
                    guessLength++;
                    temp2 /= 10;
                }
                
                while (usrGuess != 0) {
                    digit = usrGuess % 10;
                    guess.push_back(digit);
                    usrGuess /= 10;
                }
                
                reverse(guess.begin(), guess.end());
                
                if (guessLength < code.size()) {
                    for (int i = 0; i < (code.size() - guessLength); i++) {
                        guess.push_back(0);
                    }
                    rotate(guess.rbegin(), guess.rbegin() + 1, guess.rend());
                }
                
                else if (guessLength > setting) {
                    cout << "You can only enter " << setting << " digits." << endl;
                    guess_is_good = false;
                    guess.clear();
                    cin.clear();
                }
                else {
                    guess_is_good = isGuessValid(guess);
                    if (guess_is_good == false) {
                        guess.clear();
                        cin.clear();
                    }
                }
            }
            
            for (int i = 0; i < guess.size(); i++) {
                if (guess.at(i) == code.at(i)) {
                    numBulls++;
                }
                else if (count(code.begin(), code.end(), guess.at(i)) > 0) {
                    numCows++;
                }
            }
            
            if (numBulls == setting) {
                cout << numBulls << " bulls...";
                for (int i = 0; i < code.size() - 1; i++) {
                    cout << code.at(i) << "-";
                }
                cout << code.at(code.size() - 1) << " is correct!" << endl;
            }
            else {
                cout << numBulls << " bulls" << endl;
                cout << numCows << " cows" << endl;
            }
            
            guess.clear();
        }
        
    }

    
}

