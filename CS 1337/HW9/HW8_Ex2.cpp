// Author: Alex M Lundin
// Course: CS1336.008 //
// Assignment: Lecture Homework 8 Exercise 2
// Compiler: Visual C++ 2013
// Description: // 
// Create pig latin words from input file
// store to output

#include <iostream>
#include <string>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int posFirstVowel(string inStr, int firstVow);                          // prototypes
string convertToPigLatin(string inStr, int firstVow, string pigStr);

int main()
{

   const string INPUT_FILE_NAME = "pigLatinIn.txt";                     // declare constant for file name
   ifstream inputFile;                                                  // ifstream          
   ofstream output;                                                     // ofsteam for output object
   output.open("pigLatinOut.txt");                                      // open output text (no error loop required, c++ creates file or overwrites depending)
                                           
   string inStr, pigStr;                                                // declare and initialize varaibles
   int firstVow = 1000;


   inputFile.open(INPUT_FILE_NAME);                                     // open input file
   if (!inputFile.fail())                                               // error loop (will break if open fails)
   {
      cout << "Input file is open.\n";

      cout << "\nReading in the strings.\n\n";
      cout << right;

      cout << "English word            Pig Latin Word" << endl;
      cout << "------------            --------------" << endl;

      while (inputFile >> inStr)                                        // read numbers from input to varaible value
      {

         firstVow = posFirstVowel(inStr, firstVow);                     // set firstVow to result of posFirstVowel

         cout << setw(12) << right << inStr;                            // print to screen
         cout << "            ";

         if (firstVow != -1)                                            // if firstVow is not -1
         {
            pigStr = convertToPigLatin(inStr, firstVow, pigStr);        // set pigStr to result of convertToPigLatin
            output << pigStr;                                           // send pigStr to txt file
            output << endl;                                             // print a new line in txt file
         }

         cout << setw(12) << left << pigStr;                            // print to screen
         cout << endl;
      }


      
      cout << "\nClosing the input file.\n";                            //Close the input file
      inputFile.close();
   }                                                                    // End if output file was opened
   else
   {
      cout << "\nError, unable to open input file "
         << INPUT_FILE_NAME << "." << endl;
   }




   system("pause");														            // pause before closing
   return 0;																            // return 0 to end function
}																			               // end main

int posFirstVowel(string inStr, int firstVow)                           // defintion
{
   firstVow = 1000;                                                     // reset variables upon entry
   int vowTag = 0;

   string vowels = "aeiou";                                             // define strings
   string aVowel = "a";
   string eVowel = "e";
   string iVowel = "i";
   string oVowel = "o";
   string uVowel = "u";

   int aVow = 1000, eVow = 1000, iVow = 1000, oVow = 1000, uVow = 100;  // define ints to values larger than any position in a word

   vowTag = inStr.compare(vowels);                                      // look for any member of vowels in inStr, set result to vowTag

   if (vowTag == 1)                                                     // if vowTag is 1
   {
      aVow = inStr.find(aVowel, 0);                                     // set the positions of the first occurance of each vowel
      eVow = inStr.find(eVowel, 0);
      iVow = inStr.find(iVowel, 0);
      oVow = inStr.find(oVowel, 0);
      uVow = inStr.find(uVowel, 0);
   }

   if ((aVow < firstVow) && (aVow != -1))                               // if the first position of a vowel is LESS than firstVow and not -1
   {

      firstVow = aVow;                                                  // set this as current firstVow
   }
      
   if ((eVow < firstVow) && (eVow != -1))                               // repeat for each vowel
   {
      firstVow = eVow;
   }


   if ((iVow < firstVow) && (iVow != -1))
   {
      firstVow = iVow;
   }

   if ((oVow < firstVow) && (oVow != -1))
   {
      firstVow = oVow;
   }

   if ((uVow < firstVow) && (uVow != -1))
   {
      firstVow = uVow;
   }

   if (firstVow == 1000)
   {
      firstVow = -1;
   }

   return firstVow;                                                     // return firstVow to main (this will be the vowel with the least greatest index
}

string convertToPigLatin(string inStr, int firstVow, string pigStr)
{
                                                                        // define strings
   string way = "-way";
   string hyphen = "-";
   string ay = "ay";
   string residualStrFirst, residualStrLast;                            
   int lengthStr, n;

   if (firstVow == 0)                                                   // if our vowel is in first position
   {
      pigStr = inStr;                                                   // set pigStr equal to inStr
      pigStr.append(way);                                               // append way string to the end of pigStr
   }

   else                                                                 // else
   {
      lengthStr = inStr.length();                                       // get inStr length
      n = (lengthStr - firstVow);                                       // set n to inStr length minus location of firstVow
      residualStrFirst = inStr.substr(0, firstVow);                     // create first substring from beginning to firstVow of inStr
      residualStrLast = inStr.substr(firstVow, n);                      // create second substring from firstVow to end of inStr

      pigStr = residualStrLast.append(hyphen);                          // cobble together pigStr from each peice
      pigStr = pigStr.append(residualStrFirst);
      pigStr = pigStr.append(ay);


   }

   return pigStr;                                                       // return pigStr
}