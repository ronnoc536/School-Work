//Programmer: Connor Marler
//Student ID: 12573275
//Section: 109
//Date: 02/19/21
//File: KRUDD.cpp
/*Purpose: Scam Kids out of their life saving*/

#include <iostream>
using namespace std;

//====================================================
//
// Infinite loop: if you don't enter a 7 digit ID on the first run, the reprompt loop never exits
//
// Deductions: -10
//====================================================

//*************************************
//Description: this simply outputs a greeting
//Pre: none
//Post: displays greeting on screen
//*************************************
void greeting()
{
  cout << "**********************************************" << endl;
  cout << "Krusty Regional University of Dietary Disaster" << endl;
  cout << "      Bart's Totally Not Scam Calulator" << endl;
  cout << "            Proceed With Caution" << endl;
  cout << "**********************************************" << endl;
}
//*************************************
//Description: this simply outputs a signoff
//Pre: none
//Post: displays signoff on screen
//*************************************
void sign_off()
{
  cout << "                       \n";
  cout << "            Thank You For Using:" << endl;
  cout << "     *Bart's Totally Not Scam Calulator*\n";
}
//*************************************
//Description: this takes in and validates part of the student number
//Pre: inputs the student number
//Post: returns the student number if valid and outputs an error message if not 
//*************************************
int get_student_number()
{
  //_____________Declarations___________
  const int FIRST_DIGIT_ISOLATOR = 1000000;
  const int INVALID_FIRST_NUMBER = 0;
  int student_num = 0;
  int student_num_temp;
  int count = 0;
  bool first_digit_validator = true;
  //________________Body________________
//====================================================
//
// use consts (7, 10)
//
// Deductions: -3
//====================================================
  while ((count != 7) || (first_digit_validator == false))
  { 
    cout << "Enter Student Number... ";
    cin >> student_num;
    student_num_temp = student_num;

    while (student_num_temp > 0) // counts length
    {
      student_num_temp /= 10;
      count++;
    }
    if (count == 7)
    {
      if (student_num / FIRST_DIGIT_ISOLATOR == INVALID_FIRST_NUMBER) // checks first digit 
        first_digit_validator = false;
    }
    if (count != 7)
      cout << "ERROR: you entered an invalid number of digits\n";
    if (first_digit_validator == false)
      cout << "ERROR: 0 cannot be the first digit\n";
  }
  return student_num;
}
//************************************
//Description: validates that the student number is correct (further)
//Pre: has student_num as the parameter 
//Post: Determines if the first two digits are an actual students
//*************************************
bool validate_student_number(int student_num)
{
  //_____________Declarations___________
  int student_number = student_num;
  int first_two_digits = static_cast<int>(student_number / 100000);
  //________________Body________________
//====================================================
//
// Use consts
//
// Deductions: -5
//====================================================
  if ((first_two_digits == 15) ||
      (first_two_digits == 20) ||
      (first_two_digits == 25) ||
      (first_two_digits == 30) ||
      (first_two_digits == 35))
    {
      cout << "Valid!\n";
      return true;
    }
    
  else
    cout << "ERROR: you did not enter a student number\n";
    return false;
}
//*************************************
//Description: intakes and returns the monestary assests of customers
//Pre: inputs the assets and only takes in positive numbers 
//Post: returns the assets' monetary value
//*************************************
float input_assets()
{
  //_____________Declarations___________
  float assets = -1;
  //_________________Body_______________
  while (assets < 0)
  {
    cout << "enter your monetary assets, chungus... ";
    cin >> assets;
    if (assets < 0)
      cout << "enter a positive number you boob\n";
  } 
  return assets;
}

//*************************************
//Description: This calculates the financial aid package
//Pre: takes in the assets and digits in the student number after the first two
//Post: displays financial aid package on screen 
//*************************************
void asset_calculator(float assets, int c, int d, int e, int f, int g)
{
  float aid_wo_assets;
  float aid_w_assets;

  aid_wo_assets = (c * d * e * f * g);
//====================================================
//
// Use consts
//
// Deductions: -1
//====================================================
  aid_w_assets = (assets + (c + d + e + f + g) * 4.3);   
  if (assets == -1)
    cout << "Your aid is $" << aid_wo_assets << endl;
  else
    cout << "Your aid is $" << aid_w_assets << endl;
  return;
}
//*************************************
//*************************************
int main()
{ 
  //_____________Declarations___________
  int student_num;
  int menu_choice;
  int c;
  int d;
  int e;
  int f;
  int g;
  float assets = -1;
  float aid_wo_assets;
  float aid_w_assets;

  string menu_1 = "1. Enter student number\n";
  string menu_2 = "2. Validate this number\n";
  string menu_3 = "3. Assets\n";
  string menu_4 = "4. Calculate financial aid package\n";
  string menu_5 = "5. Quit\n";

  cout.setf(ios::fixed);     
  cout.setf(ios::showpoint);  // MAGIC
  cout.precision(2);

  //______________Body___________________
  greeting();
  while (menu_choice != 5)
  {
    cout << endl << menu_1 << menu_2 << menu_3 << menu_4 << menu_5;
    cout << "Enter Your Choice... ";
    cin >> menu_choice;
    switch (menu_choice)
    {
      case 1:
        student_num = get_student_number();
        c = (static_cast<int>(student_num % 100000) / 10000); // gets 10 thousands place
        d = (static_cast<int>(student_num % 10000) / 1000); // gets thousands place
        e = (static_cast<int>(student_num % 1000) / 100); // gets hundreds place
        f = (static_cast<int>(student_num % 100) / 10); // gets tens place
        g = (static_cast<int>(student_num % 10)); // get ones place
        break;
      case 2:
        validate_student_number(student_num);
        break;
      case 3:
        assets = input_assets();
        break;
      case 4:
        asset_calculator(assets, c, d, e, f, g);
        break;
      case 5:        
        sign_off();
        break;
    }
  }
}
