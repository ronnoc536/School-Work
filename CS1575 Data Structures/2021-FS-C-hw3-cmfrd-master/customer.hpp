#include "customer.h"
#include <iostream>
using namespace std;

Customer::Customer(string name, int popplers)
{ 
  m_totalEaten = 0;
  m_popplers = popplers;
  m_name = name;
}
Customer::Customer()
{
  m_name = "(-NOBODY-)";
  m_totalEaten = 0;
  m_popplers = 0;
}

