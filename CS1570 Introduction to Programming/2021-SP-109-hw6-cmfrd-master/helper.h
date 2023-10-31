#ifndef HELPER_H
#define HELPER_H

#include <iostream>
using namespace std;

struct pant      // template for pants object
{
  int m_waistMeasure;
  int m_inseamMeasure;
  int m_color;
  bool m_availability;
};

struct pants_of_size  // this is the template for the pants_of_size object
{
  int m_waist_measure = 0;
  int m_shorts[7];
};

//Description: this populates the list of pant obj with its member vars
//Pre: takes in the pants array,  and availabilty bool
//Post: none
void populate_list (pant pants[], bool AVAIL);
//Description: takes in inseams from .dat file
//Pre: none
//Post: returns the inseams var
int get_inseams();
//Description: populates the index array with pants of size objects
//Pre: takes in the pants array, colors array, index length and the index array
//Post: none 
void populate_index_array(pant pants[],const string COLORS[], const int INDEX_ARRAY_LEN, pants_of_size index_array[]);
//Description: this find the length of a file
//Pre: none
//Post: returns the len of a file
int find_len_of_file();
//Description: this sorts the pants array in ascending order
//Pre: takes in the pants array
//Post: none
void sort_inventoryArray(pant pants[]);
//Description: prints out all of the inventory of the store
//Pre: takes in the pants array, index array, and the colors array
//Post: none
void print_out_inventory(pant pants[], pants_of_size index_array[], const string COLORS[]);
//Description: this is where all of the user interaction happens 
//Pre: takes in the pants array, index array, and the colors array
//Post: returns bool to continue shopping 
bool user_interface(pant pants[], pants_of_size index_array[],const string COLORS[]);
//Description: this calculates the cost of the pants
//Pre: takes in the waist size int and inseam int
//Post: returns the total cost
int price_calculator(int waist_size, int inseam);


#endif