// Author: Alex M Lundin
// Course: CS1336.008 // Date: 11/15/2015
// Assignment: Lecture Homework 6 Exercise 2
// Compiler: Visual C++ 2015
// Description: // File I/O maxs and mins
// open file are parse data into max, min, average, sum, secondmax and secondmin

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int main()
{


   const string INPUT_FILE_NAME = "random.txt";                                                                // declare constant for file name
   ifstream inputFile;                                                                                         // ifstream
   int value;                                                                                                  // declare value as int (to accept numbers specified in pdf from input)
   double count = 0, average = 0;                                                                              // declare count and average as double (to avoide integer division)
   int sum = 0, maxValue = 0, secondmaxValue = 0 , minValue = 1000 , secondminValue = 1000;                    // initialize the sum, maximuns and minumumns based on text file parameters


   inputFile.open(INPUT_FILE_NAME);                                                                            // open input file
   if (!inputFile.fail())                                                                                      // error loop (will break if open fails)
   {
      cout << "Input file is open.\n";

      cout << "\nReading in the numbers.\n\n";
      cout << right;

      while (inputFile >> value)                                                                               // read numbers from input to varaible value
      {
         count++;                                                                                              // increment loop count each run

         sum = sum + value;

         if (value > maxValue)                                                                                 // if value is bigger than current max
         {
            secondmaxValue = maxValue;                                                                         // set secondmax to old max
            maxValue = value;                                                                                  // set max to current value
         }

         if ((value > secondmaxValue) && (value != maxValue))                                                  // when we come across a bigger value for the second max
         {
            secondmaxValue = value;                                                                            // store that value in second max
         }


         if (value < minValue)                                                                                 // same structure as above for minimuns
         {
            secondminValue = minValue;
            minValue = value;
         }

         if ((value < secondminValue) && (value != minValue))
         {
            secondminValue = value;
         }

      }                                                                                                         // print the information from the file

      cout << "There were " << count << " total numbers" << endl;

      cout << "The sum of all numbers is " << sum << endl;

      average = sum / count;                                                                                   // average and count are doubles to avoid integer division
      cout << "The average of all numbers is " << fixed << setprecision(1) << average << endl;                 // setprecision to print one decimal

      cout << "The largest number is " << maxValue << endl;
      cout << "The second largest number is " << secondmaxValue << endl;
      cout << "The smallest number is " << minValue << endl;
      cout << "The second smallest number is " << secondminValue << endl;


                                                                                                               //Close the input file
      cout << "\nClosing the input file.\n";
      inputFile.close();
   }                                                                                                           // End if output file was opened
   else
   {
      cout << "\nError, unable to open input file "
         << INPUT_FILE_NAME << "." << endl;
   }




   system("pause");														                                                      // pause before closing
   return 0;															                                                         // return 0 to end function
}                                                                                                                 // end main