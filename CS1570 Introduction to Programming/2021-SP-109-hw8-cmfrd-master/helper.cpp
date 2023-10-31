#include <iostream>
#include "helper.h"
using namespace std;

void sign_off()
{
  cout << endl
       << "Salutations, my friends. Thank you for playing." << endl;
}

int row_input()
{
  const int MAX = 10;
  const int MIN = 6;
  int rows = 20;
  do
  {
    cout << "Enter desired rows between 6-10:" << endl;
    cin >> rows;
  } while (!(rows <= MAX && rows >= MIN)); // make sure is in bounds
  return rows;
}

int col_input()
{
  const int MAX = 10;
  const int MIN = 6;
  int cols = 20;
  do
  {
    cout << "Enter desired cols between 6-10:" << endl;
    cin >> cols;
  } while (!(cols <= MAX && cols >= MIN)); // make sure is in bounds
  return cols;
}

bool operator == (const magic_skware lhs, const magic_skware rhs)
{
  bool perfect = true; // establish a baseline for the perfect
  for(int i = 0; i < lhs.m_rows; i++) // for all rows
  {
    for(int j = 0; j < lhs.m_cols; j++) // for all colls
    {
      if(lhs.m_skware[i][j] != rhs.m_skware[i][j]) // check to see if they are the same
        perfect = false; // perfect proved wrong 
    }
  }
  return perfect; // return whether it was perfect or not
}

magic_skware :: magic_skware(const int rows, const int cols)
{
  const int VAL_BAL = 1;
  const int MAX = 7;
  const int MIN = 1;
  m_rows = rows + VAL_BAL; // rows entered plus the sum
  m_cols = cols + VAL_BAL; // cols entered plus the sum
  int row_sum = 0;
  int col_sum = 0;

  m_skware = new int *[m_rows]; // create the rows
  for (int i = 0; i < m_rows; i++) // for each row
  {
    m_skware[i] = new int[m_cols]; // create the cols
    row_sum = 0;
    for (int j = 0; j < m_cols; j++) // for each of the cols
    {
      if (j + 1 == m_cols) // check its the last element
      {
        m_skware[i][m_cols] = row_sum; // maje that the sum
      }
      else // if not 
      {
        m_skware[i][j] = (rand() % MAX) + MIN; // set element to random value 
        row_sum += m_skware[i][j]; // add it to the total
      }
    }
  }
  for (int h = 0; h < m_cols; h++) // for each of the cols 
  {
    col_sum = 0;
    for (int k = 0; k < m_rows; k++) // for each of the rows
    {
      if (k + MIN == m_rows)  // if its the last row
      {
        m_skware[m_rows - MIN][h] = col_sum; // make it the sum
      }
      else
        col_sum += m_skware[k][h]; // else add it to the sum
    }
  }
}

magic_skware ::~magic_skware()
{
  for (int i = 0; i < m_rows; i++) // for all the rows
  {
    delete[] m_skware[i]; // destroy
    m_skware[i] = nullptr; // set to nullptr
  }
  delete[] m_skware;
  m_skware = nullptr;
}

void magic_skware :: display_skware()
{
  const int MIN = 1;
  // this function just cycles through everything and prints it all formatted
  cout << endl;
  for (int i = 0; i < m_rows; i++)
  {
    if (i + MIN == m_rows)
      cout << " =========================" << endl;

    for (int j = 0; j < m_cols; j++)
    {
      if (m_skware[i][j] == -MIN) // if it has been removed
        cout << " |  ";
      else
      {
        if (j + MIN == m_cols)
        {
          if (i + MIN == m_rows)
            cout << " |";
          else
            cout << " || " << m_skware[i][m_cols];
        }
        else
        {
          if (i + MIN == m_rows)
            cout << " |" << m_skware[i][j];
          else
            cout << " | " << m_skware[i][j];
        }
      }
    }
    cout << endl;
  }
}

magic_skware :: magic_skware(const magic_skware &skware)
{
  const int MIN = 1;
  m_rows = skware.m_rows;
  m_cols = skware.m_cols;

  // this creates a new magic skware and copys the info from the source to it
  m_skware = new int *[m_rows];
  for (int p = 0; p < m_rows; p++)
    m_skware[p] = new int[m_cols];

  for (int i = 0; i < m_rows; i++)
  {
    for (int j = 0; j < m_cols; j++)
    {
      if (j + MIN == m_cols)
        m_skware[i][m_cols] = skware.m_skware[i][m_cols];
      else
        m_skware[i][j] = skware.m_skware[i][j];
    }
  }
}

void magic_skware ::remove_random()
{
  const int MIN = 1;
  const int MAX_MIS_ELMS = 5;
  int rand_row = 0;
  int rand_col = 0;
  int rand_max_row = m_rows - MIN; // to not include the sums
  int rand_max_col = m_cols - MIN;
  int counter = 0;
  do
  {
    rand_row = rand() % rand_max_row;
    rand_col = rand() % rand_max_col;
    if (m_skware[rand_row][rand_col] != -MIN) // this makes sure it doesnt remove it twice
    {
      m_skware[rand_row][rand_col] = -MIN; // set to -1
      counter += MIN; // make sure it removes only 5
    }
  } while(counter != MAX_MIS_ELMS); // make sure it removes only 5
}

void magic_skware ::solve()
{
  const int CAP = 8;
  const int MIN = 1;
  cout << "          SOLUTION!!";
  int sum = 0;
  for (int i = 0; i < m_rows; i++) //for the rows
  {
    for (int j = 0; j < m_cols; j++) //for the cols
    { //{
      if (m_skware[i][j] == -MIN) //finding empty space
      {
        for (int k = 1; k < CAP; k++) //brute force 1-7
        {
          sum = 0;  //initialize the sum for the cols
          m_skware[i][j] = k; //try out the number
          for (int h = 0; h < m_rows - MIN; h++) //find the sum of the col
          {
            if(m_skware[h][j] == -MIN) //break if can't calculate
              break;
            sum += m_skware[h][j]; //increment the sum
          }
          if (sum == m_skware[m_rows-MIN][j]) //keep the change if the sum is correct
            break;

          sum = 0;
          for (int m = 0; m < m_cols - MIN; m++) //find the sum of the row
          {
            if(m_skware[i][m] == -MIN) //break if can't calculate
              break;
            sum += m_skware[i][m]; //increment the sum
          }
          if(sum == m_skware[i][m_cols]) //keep the change if the sum is correct
            break;
        }
      }
    }
  }
}
