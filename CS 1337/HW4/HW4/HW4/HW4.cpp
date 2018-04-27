// CS 1337.001
// 02-14-2016
// Homework 4
// Reverse!
// Read a character array in from a input file
// Count the number of characters excluding the null
// Reverse the array
// my function only accepts on line, I could not figure out get line
// working long hours at work
// I accpet responsibility this won't happen again
#define _USE_MATH_DEFINES
#include <iostream>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <math.h>

using namespace std;

int countArray(char[], int);
int reverseArray(char[], int);


int main()
{
   int count = -1;																			   // initialize counters
   int reverse = -1;
   char value1;
   static char Array[100];																	   // static local to set array to 0's

   ifstream file("data.txt");																   // if stream file object
   if (file.is_open())																		   // if statement for file open
   {
      cin >> file >> Array;
      cin.getline(Array, 100);
      
      //for (int i = 0; i < 100; i++)													      // loop to fill array
      //{
       //  file >> Array[i];															         // send the line to the index of the array

      //}

   }


   cout << "The count is: " << endl;														//output block
   count = countArray(Array, count);
   cout << count << endl;
   cout << "The reverse is: " << endl;
   reverseArray(Array, count);
   system("pause");																		      // pause before closing
   return 0;
}                                                                             // end main

int countArray(char Array[100], int count)											   // array Counter
{


   for (int i = 0; i < 100; i++)															   // loop for i to 100
   {
      if (Array[i] == '\0')																   // if character is null
      {
         return count;																	      // return current counter value
      }

      count++;																			         // increment counter otherwise
   }

   return count;																			      // retrun counter if we make it to the end
}

int reverseArray(char Array[100], int count)												// reverse array function
{
   char value;
   int rmax = count;																		      // rmax to count
   static char reverseArray[100];



   int i2 = rmax;																			      // i2 counter variable to rmax
   for (int i = 0; i <= rmax; i++)
   {
      value = Array[i2];																	   // set value to the sub index of the inital array that corresponds to r2
      reverseArray[i] = value;															   // set new array sub index of i to this value
      i2--;																				         // decrement i2
   }

   for (int i = 0; i <= rmax; i++)															// print each index of the reversed array
   {
      cout << reverseArray[i] << endl;
   }


   return 0;
}