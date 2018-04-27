// CS 1337.001
// 01-31-2016
// Homework 2 Example 1
// Distance Calculator
// Prompt user for distance
// Validate data
// Verify data
// Do same for time
// Calculate mph and kph and nano lightyears per minute

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   double time, distance, mph, kph;                                                             // declare doubles
   double lightyearspermin = 0;
   int verify = -1;
   int verify2 = -1;
   cout << "Enter distance traveled in miles: " << endl;                                        // promt user for input
   cin >> distance;                                                                             // send value to variable

   if (distance <= 0)                                                                           // if statement for bad data validation       
   {
      cout << "You entered a negative or zero distance." << 
         "Please enter a positive, non zero distance." << endl;
      system("pause");
      return 0;
   }

   cout << "You entered " << distance << " . Is this correct?" << endl;                         // prompt for user verification
   cout << "Type any key for yes. Type 0 for no." << endl;
   cin >> verify;

   if (verify == 0)                                                                             // if statement for verification
   {
      cout << "You have verified that the data entered is invalid. " <<
         "Please enter valid data." << endl;
      system("pause");
      return 0;
   }



   cout << "Enter time traveled in hours: " << endl;                                            // same as above
   cin >> time;

   if (time <= 0)
   {
      cout << "You entered a negative or zero time. " <<
         "Please enter a positive, non zero time." << endl;
      system("pause");
      return 0;
   }

   cout << "You entered " << time << " . Is this correct?" << endl;
   cout << "Type any key for yes. Type 0 for no." << endl;
   cin >> verify2;

   if (verify2 == 0)                                                         
   {
      cout << "You have verified that the data entered is invalid. " <<
         "Please enter valid data." << endl;
      system("pause");
      return 0;
   }





   mph = distance * time;                                                                    // set up the definitions for calucating
   kph = distance * (1.609344) * time;
   lightyearspermin = mph * (1.0 / 5879000000000.0) * (1.0 / 60.0) * (1.0 / 1000000000);     // this is nano lightyears per minute

   cout << "Below are the rates of travel in English and metric." << endl;                   // output
   cout << setprecision(4) << showpoint << setw(10)                                          // format doubles to show 4 significant figures, with decimal points added if necessary. 
      << mph << " miles per hour." << endl;                                                  // use set width to store each varaible in a 5 space window on each line
   cout << setw(10) << kph << " kilometers per hour." << endl;
   cout << setw(10) << lightyearspermin << " nano lightyears per minute." << endl;
   system("pause");                                                                          // pause before closing
   return 0;
}                                                                                            // end main
