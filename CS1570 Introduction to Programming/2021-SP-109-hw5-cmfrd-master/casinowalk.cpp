//Programmer: Connor Marler
//Student ID: 12573275
//Section: 109
//Date: 03/14/21
//File: casinowalk.cpp
/*Purpose: calculates probability that an adult will make it to the casino*/

#include <iostream>
#include "helper.h"

using namespace std;

int main ()
{
  int min; 
  int max;

  srand(time(NULL)); // seed the random at time
  greeting();  // calls the greeting function
  cout << "Please enter a minimum vale of blocks: ";
  cin >> min; // take in the minimum number of blocks
  cout << "Please enter a maximum vale of blocks: ";
  cin >> max; // takes in the maximum number of blocks
  loops(min, max); // call the loops function and pass in the minimum and maximum value
  return 0;
} 

