#ifndef HELPER_H
#define HELPER_H

//Definition: signals the program is over
//Pre: none
//Post: none
void sign_off();

//Definition: takes in input for the rows
//Pre: none
//Post: returns the input from the user
int row_input();

//Definition: takes in input from the user for the cols
//Pre: none 
//Post: returns the input from the user
int col_input();

//Function: magic_skware(const int rows, const int cols)
//Definition: constructor for magic_skware
//Pre: takes in rows and cols
//Post: none

//Function: magic_skware(const magic_skware &skware)
//Definition: copy constructor
//Pre: takes in another magic_skware object
//Post: none

//Function: ~magic_skware()
//Definition: destructor
//Pre: none
//Post: none

//Function: display_skware()
//Definition: outputs the skware obj to screen
//Pre: none
//Post: outpus to screen

//Function: remove_random()
//Definition: takes out 5 random values
//Pre: none
//Post: none

//Function: solve()
//Definition: solves the puzzle algorithmically
//Pre: none
//Post:none

//Function: operator == (const magic_skware lhs, const magic_skware rhs)
//Definition: overloads the  == 
//Pre: tkaes in the left and right object
//Post: returns a boolean

class magic_skware
{
  private:
  int m_rows;
  int m_cols;
  int ** m_skware;

  public:
  magic_skware(const int rows, const int cols);
  magic_skware(const magic_skware &skware);
  ~magic_skware();
  void display_skware();
  void remove_random();
  void solve();
  friend bool operator == (const magic_skware lhs, const magic_skware rhs);
};

#endif