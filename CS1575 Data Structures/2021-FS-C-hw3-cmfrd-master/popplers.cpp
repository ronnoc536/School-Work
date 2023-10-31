#include<iostream>
#include "abstractqueue.h"
#include "queue.h"
#include "customer.h"
#include "randomengine.h"

using namespace std;


int main()
{
  int N = 0;
  int popplers_wanted = 0; 
  int NumMostEaten = 0;
  int NumLeastEaten = 100;
  int total_Eaten = 0;
  int roll = 0;
  int numBoxes = 0;
  int Eaten = 0;
  string Name = "";
  string Name_Most_Eaten  = "";
  string Name_Least_Eaten = "";
  Derived_Queue<Customer> Customer_List(10);
  randomEngine DiceRoll;
    


  cin >> N;

  for(int i = 0; i < N; i++)
  {
    cin >> Name;
    cin >> popplers_wanted;
    Customer New_Customer(Name, popplers_wanted);
    Customer_List.enqueue(New_Customer);
  }

  while (Customer_List.isEmpty() == false)
  {
    Customer CurrentCustomer = Customer_List.front(); // This Gets the Next Customer
    Customer_List.dequeue(); // This Removes The Element
    numBoxes = (CurrentCustomer.m_popplers / 5); // Gets the number of boxes they are buying

    if(CurrentCustomer.m_popplers % 5 != 0) 
    {
      numBoxes ++ ;
    }

    CurrentCustomer.m_totalEaten += numBoxes * 5;
    Eaten = numBoxes * 5;
    CurrentCustomer.m_popplers = 0;

    for(int k = 0; k < Eaten; k++) // finds out how many more they want
    {
        roll = DiceRoll.rollD(6);
        if(roll == 6) 
        {
          CurrentCustomer.m_popplers ++ ;
        }
    }

    cout << CurrentCustomer.m_name << " eats " << Eaten << " popplers. ";
      
    if(CurrentCustomer.m_popplers > 0) 
    {
      cout << CurrentCustomer.m_name << " wants " << CurrentCustomer.m_popplers << " more popplers!" << endl;
      Customer_List.enqueue(CurrentCustomer);
    }
    else 
        {
          total_Eaten += CurrentCustomer.m_totalEaten;
          cout << CurrentCustomer.m_name << " is satisfied after eating " << CurrentCustomer.m_totalEaten << " popplers." << endl;
        }
      
    
    if(CurrentCustomer.m_totalEaten < NumLeastEaten)
    {
      NumLeastEaten = CurrentCustomer.m_totalEaten;
      Name_Least_Eaten = CurrentCustomer.m_name;
    }

    if(CurrentCustomer.m_totalEaten > NumMostEaten )
    { 
      NumMostEaten  = CurrentCustomer.m_totalEaten;
      Name_Most_Eaten = CurrentCustomer.m_name;
    }    
    
  }
    cout << endl;
    cout << "A total of " << total_Eaten << " popplers were eaten." << endl;
    cout << Name_Most_Eaten << " ate the most popplers: " << NumMostEaten  << endl;
    cout << Name_Least_Eaten << " ate the fewer popplers: " << NumLeastEaten << endl;
    return 0;
}