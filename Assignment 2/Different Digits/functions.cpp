#include <iostream>
#include "functions.h"

int valid_count = 0;

using std::cin;
using std::cout;
using std::endl;

bool is_valid_range(int a, int b) {
    if ( (a > 0) && (a <= b) && (b <= 10000) ) {
        return true;
    }
    else {
        return false;
    }
}

int count_digit_occurrences(int number, int digit) {
    int count = 0;
    int remainder = 0;
    while (number > 0) {
        remainder = number % 10;
        if (remainder == digit) {
            count++;
        }
        number = number / 10;
    }
    return count;
}

bool has_repeated_digits(int number) {
    int remainder = 0, value = number;
    int count = 0;
    while (value > 0) {
        remainder = value % 10;
        count = count_digit_occurrences(number, remainder);
        if (count > 1) {
            return true;
        }
        value = value / 10;
    }
    return false;
}

int count_valid_numbers(int a, int b) {
    int j = 0, valid_count = 0;
    for (j = a; j <= b; j++) {
        if (has_repeated_digits(j) == false) {
            valid_count++;
        }
    }
    return valid_count;
}

