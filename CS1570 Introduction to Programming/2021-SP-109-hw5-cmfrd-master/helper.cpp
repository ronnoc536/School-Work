#include "helper.h"
#include <iostream>
using namespace std;

void greeting()
{
  cout << "Welcome to the Mid-Life Crisis Simulator" << endl;
}

void loops(const int min, const int max)
{
  int counter;
  bool got_to_casino; 
  
  for (int i=min; i <= max; i++) // loop through all of the blocks
  {
    counter = 0;                 // initialize the counter of how many times the adult made it to the casino
    for (int j = 0; j < 10000; j++)  // run this 10,000 times
    {
      got_to_casino = move_adult(i);  // call the move adult function
      if (got_to_casino == true)  // if this function returns true, then increment the counter
        counter += 1;  
    }
    percentage_execute(counter, i);  // call to create to create the percentage after has been run 10000x
  }
}

void percentage_execute(const int counter, const int i)
{
  float total_value = 10000.0;  // initialize the total number of trials as 10,000
  float percentage = (counter/total_value) * 100;  // calculate the percentage 
  cout << "The adult gets to casino " << percentage << "% of the time with " << i << " blocks." << endl;
} // ^^^^ print out the value 

bool move_adult(const int num_of_blocks)
{
  int moves_made = 0;
  int prob;
  int placement = 1;
  const int INCREMENTER = 5;
  const int RANGE_OF_OPTIONS = 100;
  int rand_chance = rand() % RANGE_OF_OPTIONS +1; // calculates random number between 1-100
  bool back_home = false;
  bool arrived_casino = false;
  
  do
  {
    prob = 100 - (moves_made * INCREMENTER); // if after every move, the percentage of a moce forward decreases by 5
    if (rand_chance <= prob)  // if the random number is within the probability to move forward then it does
      placement+=1; // move the placement forward
    else
      placement -= 1;  // move the placement backward
    moves_made += 1;  // increment the moves made
    if (placement ==  0) // check if back home
      back_home = true;
    if (placement == num_of_blocks)  // check if at casino
      arrived_casino = true; 
  
  } while(back_home == false && arrived_casino == false); // do all that until reaches a destination
  if (arrived_casino == true) // return true if reached the casino
    return true;
  return false;
}