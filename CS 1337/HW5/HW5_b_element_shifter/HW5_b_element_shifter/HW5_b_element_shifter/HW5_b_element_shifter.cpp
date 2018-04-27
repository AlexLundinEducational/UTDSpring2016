// CS 1337.001
// 02-28-2016
// Homework 5_b
// Element Shifter
#define _USE_MATH_DEFINES
#include <iostream>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <math.h>

using namespace std;

int *elementShifter(int[], int);

int main()
{
	int array1[10] = { 1,1,1,1,1,1,1,1,1,1 };												// initialize array1 to 10 elements, all 1's

	int sizeInBytes = 0;																	// initialize more vairables
	int sizeOfElement = 0;
	int sizeOfArray = 0;
	int* ptr;

	sizeInBytes = sizeof(array1);															// size of array1 in bytes
	sizeOfElement = sizeof(array1[0]);														// size on a single element from array1
	sizeOfArray = (sizeInBytes / sizeOfElement);											// divide size of total size in bytes by size of a single element to get number of elements in array1
	cout << "The size of the first array is " << endl;										// output
	cout << sizeOfArray << endl;


	ptr = elementShifter(array1, sizeOfArray);												// function call, return value to ptr
	cout << "The address of the array created in elementShifter function was " << endl;		// output
	cout << ptr << endl;
	cout << "This array was destroyed once we returned to main" << endl;
	system("pause");																		// pause before closing
	return 0;
}                                                                                           // end main

int *elementShifter(int array1[10], int sizeOfArray)
{
	int array2[11];
	int counterMax = 10;
	int counter2Max = 11;
	int counter = -1;
	int counter2 = 0;

	for (counter2 = 0; counter2 < counter2Max; counter2++)									// for loop, to fill out array2
	{
		if ((counter < counterMax) && ( counter2 != 0))										// if we are still in bounds for array 1
		{
			array2[counter2] = array1[counter];												// put index value into array 2
		}
		else
		{
			array2[counter2] = 0;															// else put zero into array 2
		}

		counter++;
	}

	cout << "The size of array 2 is "<< endl;
	cout << counter2Max << endl;
	cout << "Here are the values in array 2:" << endl;
	
	for (counter2 = 0; counter2 < counter2Max; counter2++)									// for loop, to output array 2
	{
			cout << array2[counter2] << endl;
		
	}



	return array2;																			// return pointer to first index of array 2 to main
}																							// end elementShifter function