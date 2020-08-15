
#include <iostream>

#include <vector>

#include <string>

#include <fstream>

#include <limits.h>

using namespace std;

//Main

int main()

{

     //Variable declaration

     int row, col, number;

     double value;

     int min_val = INT_MAX, max_val = INT_MIN;

     std::string fileName;

     //Get the input from the user

     std::cout << "Enter number of rows in file: ";

     std::cin >> row;

     std::cout << "Enter number of columns in file: ";

     std::cin >> col;

     std::cout << "Enter the file name: ";

     std::cin >> fileName;

     //Name the output file

     std::string outFileName = fileName + ".ppm";

     //Vector creation

     std::vector<int> v;

     std::vector<std::vector<int> > data;

     std::ifstream f(fileName.c_str());

     //Check file is not available

     if (!f.is_open())

     {

          //Condition true, display the error message

std::cerr << "Error message: Could not open file." << std::endl;

          return -1;

     }

     //Read the file using while loop

     while (f >> number)

     {

          //Check, given numberber less than min_value

          if (number < min_val)

              //True, assign numberber to min_value

              min_val = number;

          //Check, given numberber greater than max_value

          if (number > max_val)

              //True, assign numberber to max_value

              max_val = number;

          //Push the numberber into stack

          v.push_back(number);

          //Check, vector size is equal to the column size

          if (v.size() == col)

          {

              //True, push the value into stack

              data.push_back(v);

              //Clear the value

              v.clear();

          }

     }

     //Check, required amount of data is available in file

     if (data.size() != row && v.size() != 0)

     {

/*Data is not available, display the error message*/

std::cerr << "Error message: Received value is lesser or greater than expected data values." << std::endl;

          return -1;

     }

     std::vector<std::vector<int> > R(row);

     std::vector<std::vector<int> > G(row);

     std::vector<std::vector<int> > B(row);

     //Get the value using for loop

     for (int i = 0; i<data.size(); i++)

     {

          for (int j = 0; j<data.at(i).size(); j++)

          {

              //Calculate the grayscale values

              if (max_val == min_val)

                   value = 0;

             

              //Otherwise, do the following

              else

value = (data.at(i).at(j) - min_val)*255.0 / (max_val - min_val);

              R.at(i).push_back((int)value);

              G.at(i).push_back((int)value);

              B.at(i).push_back((int)value);

          }

     }

     std::ofstream of(outFileName.c_str());

     //Check output file is not available

     if (!of.is_open())

     {

          //True, display the error message

std::cerr << "Error message: Could not open output file for writing." << std::endl;

          return -1;

     }

     //Output file in PPM format
    ofstream ofs;
    ofs.open(fileName + ".ppm");
    
    if ( !ofs.is_open()) {
        cout << "Error: could not convert data to .ppm file." << endl;
    }
     ofs << "P3" << std::endl;

     ofs << row << " " << col << std::endl;

     ofs << 255 << std::endl;

     //Print the output using for loop

     for (int i = 0; i<data.size(); i++)

     {

          for (int j = 0; j<data.at(i).size(); j++)

ofs << R.at(i).at(j) << " " << G.at(i).at(j) << " " << B.at(i).at(j) << " ";

          ofs << std::endl;

     }

     return 0;

}

























