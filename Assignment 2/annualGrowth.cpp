#include <iostream>

using namespace std;

int main() {
    
    string firstname;
    string lastname;
    int birthYear = 0;
    int age = 0;
    double height_feet = 0;
    double height_inches = 0;
    double height_cm = 0;
    double total_growth = 0;
    double avg_growth = 0;
    
    cout << "First name: ";
    cin >> firstname;
    cout << "Last name: ";
    cin >> lastname;
    cout << "Birth year: ";
    cin >> birthYear;
    cout << "Height in feet (do not include inches): ";
    cin >> height_feet;
    cout << "Height in inches (do not include feet): ";
    cin >> height_inches;
    
    age = 2020 - birthYear;
    height_cm = (((height_feet * 12) + height_inches) * 2.54);
    total_growth = height_cm - 51;
    avg_growth = (total_growth / age);
    
    
    cout << "\nHello " << firstname << " " << lastname << "." << endl;
    cout << "You are " << age << " years old in 2020." << endl;
    cout << "Your height is " << height_cm << " cm." << endl;
    cout << "You grew an average of " << avg_growth << " cm per year (assuming you were 51 cm at birth)." << endl;
    
}
