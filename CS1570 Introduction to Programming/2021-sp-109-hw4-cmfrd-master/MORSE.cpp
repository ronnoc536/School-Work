//Programmer: Connor Marler
//Student ID: 12573275
//Section: 109
//Date: 03/02/21
//File: MORSE.cpp
/*Purpose: Convert things into morse code and at times, at random*/

#include <iostream>
#include <cstdlib>
using namespace std;

// GLOBAL VAR DECLARATIONS

const string GLOBAL_A_MORSE =  ".-";
const string GLOBAL_B_MORSE =  "-...";
const string GLOBAL_C_MORSE =  "-.-.";
const string GLOBAL_D_MORSE =  "-..";
const string GLOBAL_E_MORSE =  ".";
const string GLOBAL_F_MORSE =  "..-.";
const string GLOBAL_G_MORSE =  "--.";
const string GLOBAL_H_MORSE =  "....";
const string GLOBAL_I_MORSE =  "..";
const string GLOBAL_J_MORSE =  ".---";
const string GLOBAL_K_MORSE =  "-.-";
const string GLOBAL_L_MORSE =  ".-..";
const string GLOBAL_M_MORSE =  "--";
const string GLOBAL_N_MORSE =  "-.";
const string GLOBAL_O_MORSE =  "---";
const string GLOBAL_P_MORSE =  ".--.";
const string GLOBAL_Q_MORSE =  "--.-";
const string GLOBAL_R_MORSE =  ".-.";
const string GLOBAL_S_MORSE =  "...";
const string GLOBAL_T_MORSE =  "-";
const string GLOBAL_U_MORSE =  "..-";
const string GLOBAL_V_MORSE =  "...-";
const string GLOBAL_W_MORSE =  ".--";
const string GLOBAL_X_MORSE =  "-..-";
const string GLOBAL_Y_MORSE =  "-.--";
const string GLOBAL_Z_MORSE =  "--..";

//PROTOTYPES
void greet();
//Description: displays a greeting 
//Pre: none
//Post: displays a greeting on screen 
void display();
//Description: displays option menu
//Pre: done has to be false to get to the option handler
//Post: displays the menu on screen
bool option_menu_backend();
//Description: allows you to type in which option from menu that you want and calls appropriate func for task
//Pre: user must input a correct choice
//Post: calls proper function for the job, returns done 
char recieve_char();
//Description: requests a letter from user 
//Pre: user must select option one
//Post: returns character
void translate_char_to_morse(const char character);
//Description: displays translation from english to morse
//Pre: takes in character and must have a character
//Post: prints out the translation
void ascii_val(const char character);
//Description: converts character into the ascii value
//Pre: must have a character from input on selection one 
//Post: displays ascii conversion 
void secret_message();
//Description: prints a random four letter word, three letter word, and four letter word
//Pre: none
//Post: displays random secret message
void translate(char character);
//Description: actually does the translation between english and morse
//Pre: must have a character from input
//Post: displays the morse value on screen 



int main()
{
  srand(time(NULL));   // trying to make as random as I can by seeding at the time
  static bool done = false;  // this is my project termination variable
  greet();
  do                         // runs the program until done is changed
  {
    done = option_menu_backend();
  }
  while (done == false);
}
  

void greet()     
{
  cout << "     Bart's Morse Code Translator" << endl;
  cout << "         Software Courtesy of:" << endl;
  cout << "         B(art) S(impson)  inc."  << endl;
  return;
}

void display()
{
  cout << "    TRANSLATE" << endl;
  cout << "    ---------" << endl;
  cout << "1. Enter a character (alphabetic)" << endl;
  cout << "2. Morse code equivalent" << endl;
  cout << "3. ASCII value" << endl;
  cout << "4. Secret Message" << endl;
  cout << "5. Kwit";
  return;
}


bool option_menu_backend()
{
  int option_choice;
  char character;
  static bool has_been_chosen = false;
  bool done = false;


  display();                         // display the option menu
  cout << endl << "Your Choice:  ";
  cin >> option_choice;
  cout << endl;
  switch (option_choice)            // functionality of the option menu
  {  
    case 1: 
      character = recieve_char();
      has_been_chosen = true;      // once a character has been chosen, alter the var
      break;
    case 2:
      if (has_been_chosen == false)   // check if character has been inputted
      {
        cout << "Please go back and enter a character to translate..." << endl;
        option_menu_backend();
        break;
      }
      translate_char_to_morse(character);     //translates the character into morse code
      break;
    case 3:
      if (has_been_chosen == false)     // check if character has been inputted
      {
        cout << "Please go back and enter a character to translate..." << endl;
        break;
      }
      ascii_val(character);             // convert char to ascii value
      break;
    case 4:
      secret_message();                // call secret message 
      break;
    case 5:
      done = true;                     // terminate the program
      break;
    default:                           // error handler
      cout << endl << "Please enter a correct value." << endl; 
      break;
  }
  return done;
}

char recieve_char()
{
  char character = 9;
  do
  {
    cout << "Please enter a single character: ";
    cin >> character;
  }
  //this makes sure that the user actually enters a letter of the alphabet
//==============================================
//
// Use consts
//
// Deductions: -4
//==============================================
  while (!(((int)character >= 65) && ((int)character <= 90) || ((int)character >= 97) && ((int)character <= 122)));
  return character;
}

void translate_char_to_morse(const char character)
{
  cout << "Morse: ";
  translate(character);
  return;
}

void translate(char character)
// i hate this with my whole heart but but this outputs the morse translation according to the char
{
//==============================================
//
// Use switch case for something like this
//
// Deductions: -3
//==============================================
  if ((character == 'a') || character == 'A')
    cout << GLOBAL_A_MORSE << endl;
  else if ((character == 'b') || character == 'B')
    cout << GLOBAL_B_MORSE << endl;
  else if ((character == 'c') || character == 'C')
    cout << GLOBAL_C_MORSE << endl;
  else if ((character == 'd') || character == 'D')
    cout << GLOBAL_D_MORSE << endl;
  else if ((character == 'e') || character == 'E')
    cout << GLOBAL_E_MORSE << endl;
  else if ((character == 'f') || character == 'F')
    cout << GLOBAL_F_MORSE << endl;
  else if ((character == 'g') || character == 'G')
    cout << GLOBAL_G_MORSE << endl;
  else if ((character == 'h') || character == 'H')
    cout << GLOBAL_H_MORSE << endl;
  else if ((character == 'i') || character == 'I')
    cout << GLOBAL_I_MORSE << endl;
  else if ((character == 'j') || character == 'J')
    cout << GLOBAL_J_MORSE << endl;
  else if ((character == 'k') || character == 'K')
    cout << GLOBAL_K_MORSE << endl;
  else if ((character == 'l') || character == 'L')
    cout << GLOBAL_L_MORSE << endl;
  else if ((character == 'm') || character == 'M')
    cout << GLOBAL_M_MORSE << endl;
  else if ((character == 'n') || character == 'N')
    cout << GLOBAL_N_MORSE << endl;
  else if ((character == 'o') || character == 'O')
    cout << GLOBAL_O_MORSE << endl;
  else if ((character == 'p') || character == 'P')
    cout << GLOBAL_P_MORSE << endl;
  else if ((character == 'q') || character == 'Q')
    cout << GLOBAL_Q_MORSE << endl;
  else if ((character == 'r') || character == 'R')
    cout << GLOBAL_R_MORSE << endl;
  else if ((character == 's') || character == 'S')
    cout << GLOBAL_S_MORSE << endl;
  else if ((character == 't') || character == 'T')
    cout << GLOBAL_T_MORSE << endl;
  else if ((character == 'u') || character == 'U')
    cout << GLOBAL_U_MORSE << endl;
  else if ((character == 'v') || character == 'V')
    cout << GLOBAL_V_MORSE << endl;
  else if ((character == 'w') || character == 'W')
    cout << GLOBAL_W_MORSE << endl;
  else if ((character == 'x') || character == 'X')
    cout << GLOBAL_X_MORSE << endl;
  else if ((character == 'y') || character == 'Y')
    cout << GLOBAL_Y_MORSE << endl;
  else if ((character == 'z') || character == 'Z')
    cout << GLOBAL_Z_MORSE << endl;
  return;
}


void ascii_val(const char character)
{
  cout <<  endl << (int)character << endl;  // converts to an int, aka the ascii val
  return;
}

void secret_message()
{
  int randNumber;
  char secret_character;

  for (int i = 1; i < 12; i++)  // loops through the appropriate amount of times, wow i am sleepy it is 3am
  {
//==============================================
//
// Use consts
//
// Deductions: -5
//==============================================
    randNumber = rand() % 26 + 65;   // this creates the randon number that fits within the appropriate range of ascii characters
    secret_character = (char)randNumber;  // convert ascii to a character
    cout << secret_character << "    ";
    translate(secret_character);      // translate char to morse
    if ((i == 4) || (i == 7) || (i == 11))    // if end of word, add an extra space
      cout << endl;
  }
  return;
}
