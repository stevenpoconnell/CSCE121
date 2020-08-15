#include <iostream>
#include "functions.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    int a = 0, b = 0;
    cout << "Enter numbers 0 < a <= b <= 10000:" << endl;
    cin >> a;
    cin >> b;
    
    is_valid_range(a, b);
    
    if (is_valid_range(a, b) == false) {
        cout << "Invalid input" << endl;
    } else {
          for (int i = a; i <= b; i++) {
                 has_repeated_digits(i);
                 count_valid_numbers(a, b);
            }
             cout << "There are " << count_valid_numbers(a, b);
             cout << " valid numbers between ";
             cout << a << " and " << b << endl;
        }
    }
