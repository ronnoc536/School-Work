//Programmer: Connor Marler
//Student ID: 12573275
//Section: 109
//Date: 03/28/21
//File: inseam.cpp
/*Purpose: */

#include <iostream>
#include "helper.h"
#include <fstream>

using namespace std;

//=====================================================================
//
// Should ask for a new user, not assume there is one
//
// Deductions: -5
//=====================================================================

int main ()
{
  srand(time(NULL));  // seed random

  ifstream fin;   
  ofstream fout;

  pant pants[100];  // initialize pants array
  const string COLORS[7] = {"black", "blue", "red", "rainbow", "checkered", "electric green", "polka dot"};  // array of colors avail
  bool avail = true;  // initializes if the availabilty is true
  bool new_customer = true; // initializes if there is a new customer

  populate_list (pants, avail);  // populates the list
  sort_inventoryArray(pants); // sorts that array

  const int INDEX_ARRAY_LEN = 21; 
  pants_of_size index_array[INDEX_ARRAY_LEN];

  populate_index_array(pants, COLORS, INDEX_ARRAY_LEN, index_array); // populates the index array
  print_out_inventory(pants, index_array, COLORS); // prints out everything



  cout << endl << endl << "WELCOME TO THE STORE" << endl;
  do                                              // does the user interface until until proven otherwise
  {
    new_customer = user_interface(pants, index_array, COLORS);
  } while (new_customer == true);
  return 0;
}

