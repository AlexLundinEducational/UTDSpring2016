// CS 1337.001
// 01-17-2016
// Homework 1 Example 1
// Distance Calculator
// Prompt user for distance and time
// calculate mph and kph

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   double time, distance, mph, kph;                                        // declare doubles
   cout << "Enter distance traveled in miles: " << endl;                   // promt user for input
   cin >> distance;                                                        // send value to variable

   cout << "Enter time traveled in hours: " << endl;                       // same as above
   cin >> time;

   mph = distance * time;                                                  // set up the definitions for calucating
   kph = distance * (1.609344) * time;

   cout << "Below are the rates of travel in English and metric." << endl; // output
   cout << setprecision(4) << showpoint << setw(5)                         // format doubles to show 4 significant figures, with decimal points added if necessary. 
      << mph << " miles per hour." << endl;                                // use set width to store each varaible in a 5 space window on each line
   cout << setw(5) << kph << " kilometers per hour." << endl;

   system ("pause");                                                       // pause before closing
}                                                                          // end main