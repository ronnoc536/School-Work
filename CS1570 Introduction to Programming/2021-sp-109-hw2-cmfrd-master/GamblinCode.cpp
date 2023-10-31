//Programmer: Connor Marler
//Student ID: 12573275
//Section: 109
//Date: 02/08/21
//File: GamblinCode.cpp
/*Purpose: Decipher Barts code to prevent cheating in the Casino*/

//====================================================
//
// Incorrect output: "We don't know" codes don't print anything
//
// Deductions: -10
//====================================================

#include <iostream>
using namespace std;

int main()
{
  //-------------Declarations----------------//
  const int MIN_DIGIT = 10000;
  const int MAX_DIGIT = 99999;
  int action_num;
  int odd = 1;
  int even = 0;
  int a;
  int b;
  int c;
  int d;
  int e;
  int times_through_sequence = 0;
  string yes_or_no = "y";
  string code_text;
  bool even_odd;

  //-------------Code Begins---------------// 
  cout << "                Bart's Security Service Analyzer\n";
  cout << endl;
  cout << endl;

  //-------------While Loop Began------------//
//====================================================
//
// Use consts for bounds (3)
//
// Deductions: -1
//====================================================
  while ((times_through_sequence <= 3) && (yes_or_no == "y"))
  /* run the below code if it has not been gone through 4 times already and that
   the player still wants to play*/
  {
    cout << "Enter code: ";
    cin >> action_num;
    while ((action_num < MIN_DIGIT) || (action_num > MAX_DIGIT))
    // throw the below error if out of bounds
    {
      cout << "\nThe code " << action_num << " is invalid; try again: ";
      cin >> action_num;
    } // out of bounds while closer


    //--Initialisation can not happen at the top--//

    //_______ISOLATING EACH DIGIT_______//
    // aquire digits left to right (decending)
    a = (action_num / 10000); // gets 10 thousands place
    b = (action_num % 10000) / 1000; // gets thousands place
    c = (action_num % 1000) / 100; // gets hundreds place
    d = (action_num % 100) / 10; // gets tens place
    e = (action_num % 10); // get ones place
    even_odd = (action_num % 2); // check if even or odd by the remainder

    //------specifications if-statement trees------//
    //EVEN
    if (even_odd == even)
      {
//====================================================
//
// Use consts (3, 3)
//
// Deductions: -2
//====================================================
        if (c == 3)
          code_text = "card counter is under the table";
        else if (c != 3)
          code_text = "card counter is still at the table";
      } // if statement about even closing bracket
    //ODD
    else if (even_odd == odd)
      {
//====================================================
//
// Use consts (4, 4, 11)
//
// Deductions: -3
//====================================================
        if (b == 4) 
          code_text = "card counter is on the run";
        else if (b + c == 4)
          code_text = "drank too much Duff Soda and is throwing up in the bathroom";
        else if ((a + c + e - (b + d)) % 11 == 0)
          code_text = "Lisa is trying to report Bart";
      }
    //-----if meets no specification---------//
    else
      code_text = "we don't know";
    
    //-------output data and analysis---------
    cout << "The code " << action_num << " means: " << code_text << endl;
    times_through_sequence += 1;  // count how many times we have done the while loop
//====================================================
//
// use consts for bounds (4)
//
// Deductions: -1
//====================================================
    if (times_through_sequence != 4) // check to see if we are on last lap through
    {
      cout << "Translate another code (y/n)? _ ";
      cin >>  yes_or_no; 
    } // end bracket for if statement to check if on last lap
  }
  cout << "\n..........signing off.....ciao for now\n";
  return 0;
} // end bracket for main 

// Thank you for grading, I hope you have a nice day. 
// Sincerly, Connor 

