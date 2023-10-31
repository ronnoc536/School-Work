#ifndef HELPER_H
#define HELPER_H

#include <iostream>
using namespace std;

//Description: Displays a greeting on screen 
//Pre: none 
//Post: displays greeting 
void greeting();

//Description: This loops through the walk 10,000 times for each road length
//Pre: takes in two intergers, the min and max 
//Post: none 
void loops(const int min, const int max);

//Description: this determines the moves forward and backwards and the probability of each.
//Pre: takes in how many blocks are on the individual road
//Post: returns a true bool if the casino is reached
bool move_adult(const int num_of_blocks);

//Description: this displays and calculates the percent of adults that reached the casino
//Pre: takes in two ints, the counter of how many succesuful trips to the casino there were and the road length
//Post: returns nothing but prints the percentage
void percentage_execute(const int counter, const int i);


#endif