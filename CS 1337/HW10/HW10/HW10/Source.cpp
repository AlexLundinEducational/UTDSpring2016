// Homework 10
// Alex Lundin
// CS1337.001
// Ackermann function with driver program


#include <stdio.h>
#include <iostream>

using namespace std;

int ack(int m, int n)                                          // Ackermann function
{
   if (m == 0) return n + 1;
   if (n == 0) return ack(m - 1, 1);
   return ack(m - 1, ack(m, n - 1));
}                                                              // end Ackermann

int main()                                                     // driver
{
   int i, j;
   i = 0, j = 0;                                               // set i and j
   printf("ack(%d,%d) = %d\n", i, j, ack(i, j));               // call Ackermann during print
   i = 0, j = 1;
   printf("ack(%d,%d) = %d\n", i, j, ack(i, j));
   i = 1, j = 1;
   printf("ack(%d,%d) = %d\n", i, j, ack(i, j));
   i = 1, j = 2;
   printf("ack(%d,%d) = %d\n", i, j, ack(i, j));
   i = 1, j = 3;
   printf("ack(%d,%d) = %d\n", i, j, ack(i, j));
   i = 2, j = 2;
   printf("ack(%d,%d) = %d\n", i, j, ack(i, j));
   i = 3, j = 2;
   printf("ack(%d,%d) = %d\n", i, j, ack(i, j));

   system("PAUSE");                                            // pause before closing
   return 0;                                                   // return 0
}                                                              // end main