//Programmer: Connor Marler
//Student ID: 12573275
//Section: 109
//Date: 01/27/21
//File: bsmc.cpp
/*Purpose: finds the optimal number of pounds of sugar needed to keep the 
gamblers going*/

#include <iostream>
using namespace std;

//=================================
//
// Bossa nova!
//
//=================================

int main()
{
  //----------DECLARATIONS----------
  const int GUT_FEELING = 20;
  const int LBS_PER_BOTTLE = 3;
  const int LUNCH_LIMIT = 6;
  const float AVG_LB_SUGAR = 2;
  int num_gamblers;
  int does_selm_exist;
  int bottles_duff;
  float avg_weight_og;
  float selm;
  float lb_of_sugar;

  //---------INPUT AND LABELS-----------  
  cout << "                 Welcome to Bart's Sugar Monster Calculator\n";
  cout << "Please enter the following:\n";
  cout << "        Number of people gambling:     ";
  cin >> num_gamblers;  // Intake the number of gamblers
  cout << endl;
  cout << "        Their average weight:          ";
  cin >> avg_weight_og; // Intake the avg weight of each gambler 
  cout << endl;
  cout << "        Lunch money index:             ";
  cin >> selm;  //Intake springfield elementary lunch money 
  cout << endl;


  //-------------MATH----------------
  does_selm_exist = static_cast<bool>(num_gamblers/(LUNCH_LIMIT));
  // ^^ This is forces does_selm_exist into a 1 if over 5 and a 0 if under 5
  selm = selm * does_selm_exist;
  // ^^ I reassing selm as either itself or 0 dependent on the value of 
  // does selm exist
  lb_of_sugar = num_gamblers * (avg_weight_og * (AVG_LB_SUGAR
  /GUT_FEELING) + (selm));
  // I find the total pounds of sugar using the given formula
  bottles_duff = lb_of_sugar / LBS_PER_BOTTLE;
  // I find the number of duff bottles that is equivelent to the amnt of sugar

  //---------PRINTING------------- 
  cout << "Thanks.  What you need is....\n";
  cout << "       " << lb_of_sugar << " lbs. of sugar is needed for the day\n";
  cout << "         This is equivalent to " << bottles_duff 
       << " bottles of Duff Soda\n";
  cout << "....You have been using another awesome Bart-SoftTM\n product."
       << " Have a nice day.";
  return 0;
// Thank you for grading, I hope you have a nice day. 
// Sincerly, Connor 

}
