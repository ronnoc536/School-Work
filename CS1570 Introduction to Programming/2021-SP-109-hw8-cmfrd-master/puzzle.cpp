#include <iostream>
#include "helper.h"
using namespace std;

/*___________________________________________________________________
  the instructions honestly confused me alot. Partially beacuse I am just dumb.
  But I really did try my best to make sense of this. Thank you grading 
  this semester. I really do appreciate you being so quick with these grades. 
  Thank You Richie.
  ~Connor
  ____________________________________________________________________*/

  
int main()
{
  srand(time(NULL)); // seed random
  int initial_play = 0; // set initial play to 0
  bool do_another = false; // initialize to prevent error
  int num_rows = 0;
  int num_cols = 0;
  string wanna_sol = "p";


  cout << "|*|PUZZLE|*|" << endl;
  do
  {
    cout << endl << "Do you wish to play a puzzle? (1 for yes, 0 for no)...";
    cin >> initial_play;  
    cout << endl;
    if(initial_play == 1) // alter do_another based on the input from the user
      do_another = true;
    else
      do_another = false;

    if(do_another == true)
    { 
      num_rows = row_input(); // take in how many rows
      num_cols = col_input(); // take in how many cols

      magic_skware skware(num_rows, num_cols); // create the original obj
      cout << endl << endl;
      magic_skware soln(skware); // make the solution object the same as the original
      cout << "Here's your puzzle....solve it if you can!";
      skware.remove_random(); // remove values from the original for puzzle
      skware.display_skware(); // display the puzzle
      do
      {
        cout << "   Wanna solution? (y or n) " << endl; // see if they want to see the solution
        cin >> wanna_sol;
      } while (wanna_sol != "y" && wanna_sol != "n"); // input filter
      if(wanna_sol == "y")
      {
        skware.solve(); // solve the puzzle
        skware.display_skware(); // print the solved puzzle
        if(skware == soln) // check if the match
          cout << "generated solution matches the original solution" << endl;
        else
          cout << "generated solution doesn't match the original solution" << endl;
      }

    }
  } while (do_another == true);  // do all while they are still wanting to play
  sign_off(); // say goodbye
  return 0;
}