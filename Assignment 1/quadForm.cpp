#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    double a = 0, b = 0, c = 0;
    double disc = 0;
    double r1 = 0, r2 = 0;
    double realPart = 0, imagPart = 0;
    
    cin >> a >> b >> c;
    
    disc = b * b - (4 * a * c);
    
    if (disc >= 0) {
        if (a == 0 && b == 0) {
            if (c < 0) {
            cout << a << "x^2 + " << b << "x - " << -c << " = 0 \n";
            cout << "Unable to determine root(s)." << endl;
            }
            else {
                cout << a << "x^2 + " << b << "x + " << c << " = 0 \n";
                cout << "Unable to determine root(s)." << endl;
            }
        }
        else if (a == 0 && b > 0) {
            if (c < 0) {
            r1 = -c/b;
            cout << a << "x^2 + " << b << "x - " << -c << " = 0 \n";
            cout << "x = " << r1 << endl;
            }
            if (c > 0) {
                r1 = -c/b;
                cout << a << "x^2 + " << b << "x - " << -c << " = 0 \n";
                cout << "x = " << r1 << endl;
            }
        }
        else if (a == 0 && b < 0) {
            r1 = -c/b;
            cout << a << "x^2 - " << -b << "x + " << c << " = 0 \n";
            cout << "x = " << r1 << endl;
        }
        else if (b == 0 && c == 0) {
            cout << "x = all real numbers" << endl;
        }
        else if (b < 0 && c != 0) {
            cout << a << "x^2 - " << -b << "x + " << c << " = 0 \n";
            r1 = ( (-b - sqrt(disc)) / (2*a));
            r2 = ( (-b + sqrt(disc)) / (2*a));
            if (r1 == r2) {
                cout << "x = " << r1 << endl;
            }
            else {
            cout << "x = " << r1 << endl;
            cout << "x = " << r2 << endl;
            }
        }
        else if (a != 0 && b > 0 && c < 0) {
            cout << a << "x^2 + " << b << "x - " << -c << " = 0 \n";
            r1 = ( (-b - sqrt(disc)) / (2*a));
            r2 = ( (-b + sqrt(disc)) / (2*a));
            cout << "x = " << r1 << endl;
            cout << "x = " << r2 << endl;
        }
        else {
            cout << a << "x^2 + " << b << "x + " << c << " = 0 \n";
            r1 = ( (-b - sqrt(disc)) / (2*a));
            r2 = ( (-b + sqrt(disc)) / (2*a));
                
            if (r1 == r2) {
                cout << "x = " << r1 << endl;
            }
            else {
            cout << "x = " << r1 << endl;
            cout << "x = " << r2 << endl;
            }
        }
    }
   
    if (disc < 0) {
        disc = fabs(disc);
        realPart = -b / (2 * a);
        imagPart = sqrt(disc) / (2 * a);
        
        if (a < 0 && b > 0 && c < 0) {
            cout << a << "x^2 + " << b << "x - " << -c << " = 0 \n";
        
            cout << "x = " << realPart << " + " << -imagPart << "i" << endl;
            cout << "x = " << realPart << " - " << -imagPart << "i" << endl;
        
        }
        if ( a < 0 && b < 0 && c < 0) {
            cout << a << "x^2 - " << -b << "x - " << -c << " = 0 \n";
            cout << "x = " << realPart << " + " << -imagPart << "i" << endl;
            cout << "x = " << realPart << " - " << -imagPart << "i" << endl;
        }
        if (a > 0 && c > 0) {
            cout << a << "x^2 + " << b << "x + " << c << " = 0 \n";
            cout << "x = " << realPart << " - " << imagPart << "i" << endl;
            cout << "x = " << realPart << " + " << imagPart << "i" << endl;
            
        }
        if (a > 0 && c < 0) {
            cout << a << "x^2 + " << b << "x - " << -c << " = 0 \n";
            cout << "x = " << realPart << " - " << -imagPart << "i" << endl;
            cout << "x = " << realPart << " + " << -imagPart << "i" << endl;
            
        }
        
 
}
}
