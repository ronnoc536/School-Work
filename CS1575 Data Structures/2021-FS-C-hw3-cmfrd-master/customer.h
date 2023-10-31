#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>

class Customer
{
    public:
      int m_popplers;
      int m_totalEaten;
      Customer();
      Customer(string name, int popplers);
      string m_name;
        
};

#include "customer.hpp"
#endif