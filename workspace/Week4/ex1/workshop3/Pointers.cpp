//filename: exchange.cpp
//Demonstrates simple pointer use

#include <string.h>
#include <iostream>
using namespace std;

int main ()
{
   int alpha = 5;
   int beta = 20;
   int* alphaPtr = &alpha;
   int* betaPtr = &beta;

   cout << "Manipulating alpha through alphaPtr" << endl;
   cout << "Before: alpha= " << alpha << endl;
   cout << "Adding 5 to value pointed to by alphaPtr" << endl;
   *alphaPtr += 5;
   cout << "After: alpha= " << alpha << endl;

   cout << "\nPrinting beta through betaPtr" << endl;
   cout << "Value pointed to by betaPtr: " << *betaPtr << endl;
   cout << "Adding 5 to beta" << endl;
   beta += 5;
   cout << "Value pointed to by betaPtr: " << *betaPtr << endl;

   // Swap the values sotered in alpha and beta using pointers

   cout << "\nWrite code to swap the pointers" << endl;


   //use a three handed swap to swap variable in alphaPtr and betaPtr

   
   //output the values pointed to by both pointers



   return 0;
}
