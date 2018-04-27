// CS 1337.001
// Date
// Homework #
// Program Name
// Desc

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
   fstream inFile("input.txt", ios::in);
   string item;
   inFile >> item;
   while (inFile)
   {
      cout << item << endl;
      inFile >> item;
   }
   inFile.close();
   system("pause");                                                                          // pause before closing
   return 0;
}