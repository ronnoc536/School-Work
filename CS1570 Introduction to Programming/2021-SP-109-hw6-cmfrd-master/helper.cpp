#include "helper.h"
#include <iostream>
#include <fstream>
using namespace std;

ifstream fin;   
ofstream fout;

void populate_list (pant pants[], bool AVAIL)
{
  const int PANT_ARRAY_LEN = 100;
  const int COLOR_DIFF = 7;
  const int WAIST_DIFF = 21;
  const int WAIST_STARTER = 20;
  int rand_color;
  

  for (int i = 0; i <  PANT_ARRAY_LEN; i++)  // cycles through the pant array
  {
    rand_color = rand() % COLOR_DIFF;        // finds random number 
    pants[i].m_waistMeasure = rand() % WAIST_DIFF + WAIST_STARTER;     // These next few lines assign the member variables
    pants[i].m_inseamMeasure = get_inseams();
    pants[i].m_color = rand_color;
    pants[i].m_availability = AVAIL;
  }
}

void print_out_inventory(pant pants[], pants_of_size index_array[], const string COLORS[])
{
  const int INDEX_LEN = 21;
  const int PANTS_LEN = 100;
  for(int i = 0; i < INDEX_LEN; i++)   // cycles through index list
  {
    if(pants[i].m_availability == true)      // check if avail
    {
      cout << "waist " << index_array[i].m_waist_measure << endl;  
      
      for(int j = 0; j < PANTS_LEN; j++)   // cycles pants array

      {
        if(pants[i].m_availability == true)  // check if avail
        {
          if(pants[j].m_waistMeasure == index_array[i].m_waist_measure)  // check if they match
          {
            cout << "  inseam " << pants[j].m_inseamMeasure;
            cout << "  " << COLORS[pants[j].m_color] << endl;
          }
        }
      }
    }
  }
}

void sort_inventoryArray(pant pants[])
{
  const int SIZE = 100;

  for(int i = 1; i <= SIZE; i++)  // THIS IS A SORTING ALGORITHM
  {
    for (int j = 0; j < SIZE - i; j++) 
    {
      if(pants[j].m_waistMeasure > pants[j+1].m_waistMeasure)
      {
        pant swap = pants[j];
        pants[j] = pants[j+1];
        pants[j+1] = swap;
      }
    }
  }
  return;
}

int get_inseams()
{
  int random_line; 
  int line;
  string file = "inseams.dat";
  int len_of_file = find_len_of_file();

  random_line = rand() % (len_of_file + 1);  // finds random num for random line

  do      // open file
  {
    fin.clear();
    fin.open(file);
  } while(!fin);
  
  for(int i = 0; i < random_line; i++)   // cycles through and keeps re assigning line
  { 
    fin >>line;  
  }  

  fin.close();  // close file
  return line;
}

void populate_index_array(pant pants[], const string COLORS[], const int INDEX_ARRAY_LEN, pants_of_size index_array[])
{
  const int PANT_ARRAY_LEN = 100;

  for(int i = 0; i < PANT_ARRAY_LEN; i++) // cycles through pant array
  {
    for(int j = 0; j < INDEX_ARRAY_LEN; j++)  // cycles through index array
    {
      if((pants[i].m_waistMeasure != index_array[j].m_waist_measure) && (index_array[j].m_waist_measure == 0))  // check if within parameters
      {
        index_array[j].m_waist_measure = pants[i].m_waistMeasure;  // assign
        break;
      }
      else if (pants[i].m_waistMeasure == index_array[j].m_waist_measure)
        break;
      if(COLORS[pants[i].m_color] == "black")      // these populate the member array of index
        index_array[j].m_shorts[0] += 1;
      if(COLORS[pants[i].m_color] == "blue")
        index_array[j].m_shorts[1] += 1;
      if(COLORS[pants[i].m_color] == "red")
        index_array[j].m_shorts[2] += 1;
      if(COLORS[pants[i].m_color] == "rainbow")
        index_array[j].m_shorts[3] += 1;
      if(COLORS[pants[i].m_color] == "checkered")
        index_array[j].m_shorts[4] += 1;
      if(COLORS[pants[i].m_color] == "electric green")
        index_array[j].m_shorts[5] += 1;
      if(COLORS[pants[i].m_color] == "polka dot")
        index_array[j].m_shorts[6] += 1;
    }
  }
  return;
} 

int find_len_of_file()
{
  string file = "inseams.dat";
  int count = 0;
  int line;

  do                 // opens the file
  {
    fin.clear();
    fin.open(file);
  } while(!fin);

  while(fin>>line)    // count the the len of file by incrementing though
  {
    count++;
  }
  fin.close();  // close the file 

  return count;   // return the count
}

bool user_interface(pant pants[], pants_of_size index_array[], const string COLORS[])
{
  int waist_size;
  const int PANTS_ARRAY_LEN = 100;
  const int MAX_CAP = 40;
  const int MIN_CAP = 20;
  int user_choice;
  bool switch_case_check = true;
  bool new_customer = true;
  int inseam_wanted;
  int price;
  char y_n;

  cout << endl << "Hello New Customer!" << endl;
  cout << "What is your waist size?...";
  cin >> waist_size;  // prompt for waist size
  if(waist_size > MAX_CAP || waist_size < MIN_CAP)  // check if withing parameters
  {
    cout << "We do not have your size. Please go somewhere else." <<endl;  // give em the boot
    return new_customer;
  }
    
  cout << endl;
  cout << "For size " << waist_size << " we have: ";
  for(int i = 0; i < PANTS_ARRAY_LEN; i++)                 // This shows what colors they have from that waist
  {
    if(pants[i].m_waistMeasure == waist_size && pants[i].m_availability == true)
      cout << COLORS[pants[i].m_color] << " (enter " << pants[i].m_color << ") ";
  }
  cout << "Enter your choice (-1 for none) ";
  cin >> user_choice;  // prompt for choice
  
  do
  {
    switch(user_choice)  // I know this ugly but i am really tired. cases 0-6 show the inseams matching that color
    {
      case 0:
        for (int i = 0; i < PANTS_ARRAY_LEN; i++)
        {
          if((pants[i].m_waistMeasure == waist_size) && (pants[i].m_color == user_choice))
            cout << pants[i].m_inseamMeasure << endl;
        }
        cout << "Which inseam do you want? ";
        cin >> inseam_wanted;
        break;
      case 1:
        for (int i = 0; i < PANTS_ARRAY_LEN; i++)
        {
          if((pants[i].m_waistMeasure == waist_size) && (pants[i].m_color == user_choice))
            cout << pants[i].m_inseamMeasure << endl;
        }
        cout << "Which inseam do you want? ";
        cin >> inseam_wanted;
        break;
      case 2:
        for (int i = 0; i < PANTS_ARRAY_LEN; i++)
        {
          if((pants[i].m_waistMeasure == waist_size) && (pants[i].m_color == user_choice))
            cout << pants[i].m_inseamMeasure << endl;
        }
        cout << "Which inseam do you want? ";
        cin >> inseam_wanted;
        break;
      case 3:
        for (int i = 0; i < PANTS_ARRAY_LEN; i++)
        {
          if((pants[i].m_waistMeasure == waist_size) && (pants[i].m_color == user_choice))
            cout << pants[i].m_inseamMeasure << endl;
        }
        cout << "Which inseam do you want? ";
        cin >> inseam_wanted;
        break;
      case 4:
        for (int i = 0; i < PANTS_ARRAY_LEN; i++)
        {
          if((pants[i].m_waistMeasure == waist_size) && (pants[i].m_color == user_choice))
            cout << pants[i].m_inseamMeasure << endl;
        }
        cout << "Which inseam do you want? ";
        cin >> inseam_wanted;
        break;
      case 5:
        for (int i = 0; i < PANTS_ARRAY_LEN; i++)
        {
          if((pants[i].m_waistMeasure == waist_size) && (pants[i].m_color == user_choice))
            cout << pants[i].m_inseamMeasure << endl;
        }
        cout << "Which inseam do you want? ";
        cin >> inseam_wanted;
        break;
      case 6:
        for (int i = 0; i < PANTS_ARRAY_LEN; i++)
        {
          if((pants[i].m_waistMeasure == waist_size) && (pants[i].m_color == user_choice))
            cout << pants[i].m_inseamMeasure << endl;
        }
        cout << "Which inseam do you want? ";
        cin >> inseam_wanted;
        break;
      case -1:                               // this ended the program if there are no new customers
        cout << "New Customer? (y/n)...";
        cin >> y_n;
        if(y_n == 'y' || y_n == 'Y')
          new_customer = true;
        if(y_n == 'n' || y_n == 'N')
        {
          new_customer = false;
          return new_customer;
        }
        break;
      default:
        cout << "Try again, degenerate." << endl;
          switch_case_check = false;
    }
  } while (switch_case_check != true);  // while bool to keep switch case working is not true

  price = price_calculator(waist_size, inseam_wanted);  // calculate price

  cout << "The cost will be...$" << price << endl;
  
  for (int i = 0; i < PANTS_ARRAY_LEN; i++)     // this for loop modifies the member array of the pants_of_size object to refelect the inventory
  {
    if((pants[i].m_waistMeasure == waist_size) && (pants[i].m_color == user_choice) && (pants[i].m_inseamMeasure == inseam_wanted))
    {
      pants[i].m_availability = false;
      for (int j = 0; j < PANTS_ARRAY_LEN; j++)
      {
        if(index_array[j].m_waist_measure == waist_size)
          index_array[j].m_shorts[user_choice] -= 1;
      }
    }
  }
  return new_customer;
}

int price_calculator(int waist_size, int inseam)
{
  const int HIGH_WATER = 40;
  const int TWO = 2;
  const float MODIFIER = 0.9;
  int cost;
  bool bonus_cost = false;

  if (inseam >= (MODIFIER * waist_size)-TWO)  // check if high water bonus is needed
    bonus_cost = true;  // assign to bool
  cost = waist_size + inseam + (HIGH_WATER * bonus_cost);  // perform the math and either add the high water charge or add 0
  return cost;
}