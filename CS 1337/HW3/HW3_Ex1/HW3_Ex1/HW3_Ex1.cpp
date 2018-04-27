// CS 1337.001
// 02-07-2016
// Homework 3
// Calculating Pi
// Calculate pi with a summation formula
// compare to standard value of pi
// output error
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
   long double calculatedPi = 0;                                                             // initialize and declare variables
   int n = 1;
   int i = 0;
   double i2 = 1.0;
   int i3 = -1;
   int t = 0;

   cout << "Enter number of terms: " << endl;                                                // enter number of iterations to t
   cin >> t;                                                                                 // console in to t

   for (i = 0; i < t; i++)                                                                   // for loop to run through each iteration
   {
      calculatedPi = calculatedPi + (i2 * (4.0 / (i3 + 2)));                                 // Leibniz formula accumulator
      i3 += 2;                                                                               // add two to denominator term each iteration
      i2 *= -1;                                                                              // change sign of i2 each iteration

   }

   cout << "Number of iterations " << i << endl;                                             // outputs
   cout << "Calculated pi " << setprecision(20) << calculatedPi << endl;
   cout << "Set value for pi " << setprecision(20) << M_PI << endl;
   cout << "Error "<< setprecision(3) << M_PI - calculatedPi << endl;

   system("pause");                                                                          // pause before closing
   return 0;
}                                                                                            // end main
