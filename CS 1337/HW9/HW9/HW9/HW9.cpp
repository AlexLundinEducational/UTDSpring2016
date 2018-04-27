// Author: Alex M Lundin
// Course: CS1337
// Assignment: Lecture Homework 9
// Compiler: Visual C++ 2013
// Description: // 
// Use constructors to encrypt
// My constructor won't accept a int like the book asks for...
// I do appologize, I'm coding for a medium size company this semester.
// For my job, I taught myself AutoLISP over this past year (a version of the LISP languages for AutoCAD)
// I'm putting as much effort as I can into school and work, hope you can understand.

#include <iostream>
#include <string>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

const string INPUT_FILE_NAME = "input.txt";                                               // declare constant for file name

int posFirstVowel(string inStr, int firstVow);                                            // prototypes
string convertToPigLatin(string inStr, int firstVow, string pigStr);

int main()
{


   class FileFilter
   {
   public:

      char ch;
                                                                                          // default constructor
      FileFilter()
      {
         cout << "FileFilter constructor executing" << endl;
         cout << endl;
      }

      void doFilter(ifstream &inputFile, ofstream &output)
      {
         
         int cmax = 0;                                                                    // declare and initialize varaibles
         string inStr;
         string filterStr;
         inputFile.open(INPUT_FILE_NAME);                                                 // open input file
         if (!inputFile.fail())                                                           // error loop (will break if open fails)
         {
            cout << "Input file is open.\n";

            cout << "\nReading in the strings.\n\n";
            cout << right;


            while (inputFile >> inStr)                                                    // read string from file
            {
               cmax = inStr.length();
               for (int i = 0; i < cmax; i++)                                             // loop through each character 
               {
                  char ch = inStr.at(i);
                  ch = transform(ch);
                  output << ch;
               }
               
               output << endl;
            }



            cout << "\nClosing the input file.\n";                                        //Close the input file
            inputFile.close();
         }                                                                                // End if output file was opened
         else
         {
            cout << "\nError, unable to open input file "
               << INPUT_FILE_NAME << "." << endl;
         }
      }
      virtual char transform(char ch) const = 0;

   };


   class FileCopy : public FileFilter                                                     // dervied class
   {
   public:

      FileCopy() : FileFilter()                                                           // default constructor
      {

         cout << "FileCopy constructor executing" << endl;
         cout << endl;
      }



      virtual char transform(char ch) const                                              
      {
         ch = ch;
         return ch;
      }
   };


   class FileEncrypt : public FileFilter
   {
   public:

      FileEncrypt() : FileFilter()
      {

         cout << "FileEncrypt constructor executing" << endl;
         cout << endl;
      }
      
      virtual char transform(char ch) const
      {
         ch = (static_cast<int>(ch)) + 2;
         return ch;
      }
   };

   class FileCap : public FileFilter
   {
   public:

      FileCap() : FileFilter()
      {

         cout << "FileEncrypt constructor executing" << endl;
         cout << endl;
      }

      virtual char transform(char ch) const
      {
         ch = (static_cast<int>(ch)) - 32;
         return ch;
      }
   };

   ifstream inputFile;                                                                    // ifstream          
   ofstream output;                                                                       // ofsteam for output object
   output.open("output.txt");

   output << "Original Copy-----";                                                  
   output << endl;
   FileCopy file;
   file.doFilter(inputFile, output);

   output << "Encrypted Copy-----";
   output << endl;
   FileEncrypt fileE;
   fileE.doFilter(inputFile, output);

   output << "Capital Copy-----";
   output << endl;
   FileCap fileC;
   fileC.doFilter(inputFile, output);

   system("pause");														                              // pause before closing
   return 0;																                              // return 0 to end function
}																			                                 // end main














int posFirstVowel(string inStr, int firstVow)                                 // defintion
{
   firstVow = 1000;                                                           // reset variables upon entry
   int vowTag = 0;

   string vowels = "aeiou";                                                   // define strings
   string aVowel = "a";
   string eVowel = "e";
   string iVowel = "i";
   string oVowel = "o";
   string uVowel = "u";

   int aVow = 1000, eVow = 1000, iVow = 1000, oVow = 1000, uVow = 100;        // define ints to values larger than any position in a word

   vowTag = inStr.compare(vowels);                                            // look for any member of vowels in inStr, set result to vowTag

   if (vowTag == 1)                                                           // if vowTag is 1
   {
      aVow = inStr.find(aVowel, 0);                                           // set the positions of the first occurance of each vowel
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