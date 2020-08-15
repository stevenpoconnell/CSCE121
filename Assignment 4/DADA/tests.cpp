#include <iostream>
#include <string>
#include "dada.h"
#include "test_helper.h"
#include <math.h>

using std::cout;
using std::endl;
using std::string;

bool test_amax() {
    bool pass = true;
    
    // each testcase goes in {...} to contain scope
    {
        // the testcase is just for display purposes
        string testcase = "amax ; 8 6 7 -5 3 0 9 , 7 ; 6";
        double x[] = {8, 6, 7, -5, 3, 0, 9};
        unsigned int len = 7;
        int expected = 6;
        int actual = amax(x, len);
        
        // abuse of &=, only safe because both args are bool
        // the 3rd arg is the message to print if the test fails
        pass &= EXPECT_EQ(actual, expected, testcase);
        if (pass) {
            cout << "PASS: " << testcase << endl;
        }
    }
    
    {
        string testcase = "amax ; -4 -5 -3 -2 -1 0 1 2, 8 ; 0";
        double x[] = {-4, -5, -3, -2, -1, 0, 1, 2};
        unsigned int len = 8;
        int expected = 1;
        int actual = amax(x, len);
        
        // abuse of &=, only safe because both args are bool
        pass &= EXPECT_EQ(actual, expected, testcase);
        if (pass) {
            cout << "PASS: " << testcase << endl;
        }
    }

    return pass;
}

bool test_axpy() {
    bool pass = true;
    
    {
        string testcase = "axpy ; 1 , 1 2 3 , 4 5 6 , 3 ; 5 7 9";
        double a = 1;
        double x[] = {1, 2, 3};
        double y[] = {4, 5, 6};
        unsigned int len = 3;
        double expected[] = {5, 7, 9};
        axpy(a, x, y, len);
        double* actual = y;
        
        // abuse of &=, only safe because both args are bool
        // note the new 3rd arg is the length of the arrays
        // the 4th arg is now the message to print on failure
        pass &= EXPECT_EQ(actual, expected, len, testcase);
        if (pass) {
            cout << "PASS: " << testcase << endl;
        }
    }
    
    return pass;
}

bool test_asum() {
    bool pass = true;
    {
        string testcase = "asum ; -3 -2 0 1 , 4 ; 6";
        double x[] = {-3, -2, 0, 1};
        unsigned int len = 4;
        double expected = 6;
        double actual = asum(x, len);
        
        pass &= EXPECT_EQ(actual, expected, testcase);
        if (pass) {
            cout << "PASS: " << testcase << endl;
        }
    }
    
    {
        string testcase = "asum ; -1.25 3 1 2 5.75 , 5 ; 13";
               double x[] = {-1.25, 3, 1, 2, 5.75};
               unsigned int len = 5;
               double expected = 13;
               double actual = asum(x, len);
               
               pass &= EXPECT_EQ(actual, expected, testcase);
               if (pass) {
                   cout << "PASS: " << testcase << endl;
            }
    return pass;
    }
}

bool test_copy() {
    bool pass = true;
    {
        string testcase = "copy ;  ,  , 0 ;";
        double x[] = { 0 };
        double y[] = { 0 };
        unsigned int len = 0;
        double expected[] ={ 0 };
        copy(x, y, len);
        double* actual = y;
        
        
        pass &= EXPECT_EQ(actual, expected, len, testcase);
        if (pass) {
            cout << "PASS: " << testcase << endl;
        }
      
    }
    
    {
        string testcase = "copy ; -1 -2 -3 , 9 -8 7 , 3 ; -1 -2 -3";
        double x[] = {-1, -2, -3 };
        double y[] = {9, -8, 7};
        unsigned int len = 3;
        double expected[] ={-1, -2, -3};
        copy(x, y, len);
        double* actual = y;
        
        
        pass &= EXPECT_EQ(actual, expected, len, testcase);
        if (pass) {
            cout << "PASS: " << testcase << endl;
        
    }
         return pass;
    }
   
}

bool test_dot() {
    bool pass = true;
    {
        string testcase = "dot ;  ,  , 0 ; 0";
        double x[] = { 0 };
        double y[] = { 0};
        unsigned int len = 0;
        double expected = 0;
        dot(x, y, len);
        double actual = dot(x, y, len);
        
        pass &= EXPECT_EQ(actual, expected, testcase);
           if (pass) {
               cout << "PASS: " << testcase << endl;
        }
    }
    
    {
       string testcase = "dot ; -1 -3 5 , -2 -4 6 , 3 ; 44";
        double x[] = {-1, -3, 5};
        double y[] = {-2, -4, 6};
        unsigned int len = 3;
        double expected = 44;
        dot(x, y, len);
        double actual = dot(x, y, len);
        
        pass &= EXPECT_EQ(actual, expected, testcase);
           if (pass) {
               cout << "PASS: " << testcase << endl;
        }
    }
    
    {
        string testcase = "dot ; 1.5 3 4.5 , 1 .5 .25 , 3 ; 4.125";
        double x[] = {1.5, 3, 4.5};
        double y[] = {1, .5, .25};
        unsigned int len = 3;
        double expected = 4.125;
        dot(x, y, len);
        double actual = dot(x, y, len);
        
        pass &= EXPECT_EQ(actual, expected, testcase);
           if (pass) {
               cout << "PASS: " << testcase << endl;
           }
    }
    
    {
      string testcase = "dot ; -3 4 2 , 2 -2 7 , 3 ; 0";
        double x[] = {-3, 4, 2};
        double y[] = {2, -2, 7};
        unsigned int len = 3;
        double expected = 0;
        dot(x, y, len);
        double actual = dot(x, y, len);
        
        pass &= EXPECT_EQ(actual, expected, testcase);
           if (pass) {
               cout << "PASS: " << testcase << endl;
           }
        return pass;
    }
}

bool test_norm2() {
    bool pass = true;
    {
        string testcase = "norm2 ;  , 0 ; 0";
        double x[] = { 0 };
        unsigned int len = 0;
        double expected = 0;
        norm2(x, len);
        double actual = norm2(x, len);
        
        pass &= EXPECT_EQ(actual, expected, testcase);
        if (pass) {
            cout << "PASS: " << testcase << endl;
        }
    }
    
    {
        string testcase = "norm2 ; -f5 0 0 , 3 ; 5";
        double x[] = {-5, 0, 0};
        unsigned int len = 3;
        double expected = 5;
        norm2(x, len);
        double actual = norm2(x, len);
               
        pass &= EXPECT_EQ(actual, expected, testcase);
        if (pass) {
            cout << "PASS: " << testcase << endl;
        }
    }
    
    {
      string testcase = "norm2 ; .8  1.5 , 2 ; 1.7";
        double x[] = {.8, 1.5};
        unsigned int len = 2;
        double expected = 1.7;
        norm2(x, len);
        double actual = norm2(x, len);
        
        pass &= EXPECT_EQ(actual, expected, testcase);
        if (pass) {
            cout << "PASS: " << testcase << endl;
        }
        return pass;
    }
}

bool test_scale() {
    bool pass = true;
    {
        string testcase = "scale ; 3 ,  , 0 ;";
        double a = 3;
        double x[] = { 0 };
        unsigned int len = 0;
        double expected[] = { 0};
        scale(a, x,len);
        double* actual = x;
        
        pass &= EXPECT_EQ(actual, expected, len, testcase);
           if (pass) {
               cout << "PASS: " << testcase << endl;
        }
    }
    
    {
        string testcase = "scale ; 1.5 , 1.5 3 4.5 , 3 ; 2.25 4.5 6.75";
        double a = 1.5;
        double x[] = {1.5, 3, 4.5};
        unsigned int len = 3;
        double expected[] = {2.25, 4.5, 6.75};
        scale(a, x, len);
        double* actual = x;
        
        pass &= EXPECT_EQ(actual, expected, len, testcase);
           if (pass) {
               cout << "PASS: " << testcase << endl;
        }
    }
    
    {
        string testcase = "scale ; 0 , 7 8 5 , 3 ; 0 0 0";
        double a = 0;
        double x[] = {7, 8, 5};
        unsigned int len = 3;
        double expected[] = { 0, 0, 0};
        scale(a, x, len);
        double* actual = x;
        
        pass &= EXPECT_EQ(actual, expected, len, testcase);
           if (pass) {
               cout << "PASS: " << testcase << endl;
        }
        return pass;
    }
}



bool test_swap() {
    bool pass = true;
    {
        string testcase = "swap ;  ,  ,  0 ;   ,";
        double x[] = { 0 };
        double y[] = { 0 };
        unsigned int len = 0;
        double expected[] = { 0 };
        swap(x, y, len);
        double* actual = y;
        
        pass &= EXPECT_EQ(actual, expected, len, testcase);
               if (pass) {
                   cout << "PASS: " << testcase << endl;
            }
        
    }
    
    {
        string testcase = "swap ; -6 2 -4 , 5 -9 9 , 3 ; 5 -9 9 , -6 2 -4";
        double x[] = {-6, 2, -4};
        double y[] = {5, -9, 9};
        unsigned int len = 3;
        double expected[] = {-6, 2, -4};
        swap(x, y, len);
        double* actual = y;
        
        pass &= EXPECT_EQ(actual, expected, len, testcase);
               if (pass) {
                   cout << "PASS: " << testcase << endl;
            }
        
     return pass;
    }
}


int main() {
    int failing = 0;
    // add 1 to failing if function returns false
    failing += test_amax() ? 0 : 1;
    
    failing += test_axpy() ? 0 : 1;
    
    failing += test_asum() ? 0 : 1;
    
    failing += test_copy() ? 0 : 1;
    
    failing += test_swap() ? 0 : 1;
    
    failing += test_dot() ? 0 : 1;
    
    failing += test_norm2() ? 0 : 1;
    
    failing += test_scale() ? 0 : 1;
    
    if (!failing) {
        cout << "ALL TESTS PASSING" << endl;
    } else {
        cout << endl << "Failing: " << failing << endl;
    }
    
    return 0;
}
