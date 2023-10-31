#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP


//Connor Marler CMFRD
//CS1575 101
// I am so so sorry for how many issues there are I postponed starting for too long
// and did my best to get as much completed as possible


#include<iostream>
using namespace std;

template <typename T>
void ArrayList<T> :: grow()
{
  int new_size = m_max * 2;
  T* tmp = new T[new_size];
  for(int k=0; k < m_max; k++)
  {
    tmp[k] = m_data[k];
  }
  m_max = new_size;
  return;
}

template <typename T>
void ArrayList<T> :: shrink()
{
  m_max = m_max / 2;
  T* tmp = new T[m_max];
  for(int k=0; k < m_max; k++)
  {
    tmp[k] = m_data[k];
  }
  tmp.m_max = m_max;
  tmp.m_size = m_max;
  delete[] tmp;
  return;
}

template <typename T>
ArrayList<T> :: ArrayList(int s, const T& x)
{ 
  m_size = s;
  m_max = s;
  m_data = new T[m_max];
  for(int i = 0; i < s; i++)
    m_data[i] = x;
}

template <typename T>
ArrayList<T>::~ArrayList()
{
  delete[] m_data;
}


template <typename T>
ArrayList<T>& ArrayList<T> :: operator=(const ArrayList<T>& rhs)
{
  if(this != &rhs)
  {
    delete[] m_data;
    m_size = rhs.m_size;
    m_max = rhs.m_max;
    m_data = new T[m_max];
    for(int k=0; k < m_size; k++)
      m_data[k] = rhs.m_data[k];
  }
  return *this;
}


template <typename T>
ArrayList<T> :: ArrayList(const ArrayList<T>& cpy)
{
  m_data = NULL;
  *this = cpy;
}

template<typename T>
int ArrayList<T> :: size() const
{
  return m_size;
}

template<typename T>
const T& ArrayList<T> :: first() const
{
  if(!m_data[0]) // FIXME: oof I know this doesnt work but I have no clue how to make it Work
    cout<<"!-- ERROR : PANIC in ARRAYLIST.[]  (There is not a first element)"<< endl;
  else
    return m_data[0];
  return m_errobj;
}              

template<typename T>
T& ArrayList<T> :: operator[](int i)
{
  if(i>m_size)
      cout<<"!-- ERROR : PANIC in ARRAYLIST.[]  (index out of bounds)"<< endl;
    else
      return m_data[i];
  return m_errobj;
}

template<typename T>
const T& ArrayList<T> :: operator[](int i) const
{ if(i>m_size)
    cout<<"!-- ERROR : PANIC in ARRAYLIST.[]  (index out of bounds)"<< endl;
  else
    return m_data[i];
  return m_errobj;
}

template<typename T>
int ArrayList<T> :: search(const T& x) const
{
  bool test = false;
  int i = 0;
  int position = -1;
  while(!test && i < m_size)
  {
    if(m_data[i] == x)
    {
      position = i;
      test = true;
    }
    i++;
  }
  return position;
}

template<typename T>
void ArrayList<T> :: clear() 
{            
 delete[] m_data;
 m_max = 4;
 m_size = 0;
 m_data = new T[m_max];
 return;
}

template<typename T>
void ArrayList<T> :: insert_back(const T& x)
{
  if(m_size <= m_max)
    m_data[m_size] = x;
  else
  {
    grow();
    m_data[m_size] = x;
  }
  m_size++;
}

template<typename T>
void ArrayList<T> :: insert(const T& x, int i)
{
  if(m_max == m_size)
  {
    m_max *= 2;
    delete[] m_data;
    m_data = new T[m_max];
  }
  for(int k = m_size; k > i; k--)
  {
    m_data[k] = m_data[k-1];
  }
  m_data[i] = x;
  m_size++;
  return;
}

template<typename T>
void ArrayList<T> :: remove(int i)
{
  for(int k = i; k < m_size -1; k++)
    m_data[k] = m_data[k + 1];
  m_size--;

  if(m_size < (m_max / 4))
  {
    m_max = m_max / 2;
    T* tmp = new T[m_max];
    for(int k=i; k < m_max; k++)
    {
      tmp[k] = m_data[k];
    }
    delete[] tmp;     
  } 
}

template<typename T>
void ArrayList<T> :: swap(int i, int k)
{
  if((i <= m_size) && (k <= m_size))
  {
    T* tmp = new T[m_max];

    tmp[0] = m_data[i];

    m_data[i] = m_data[k];
    m_data[k] = tmp[0];

    delete[] tmp;
  }
  else
    cout<<"!-- ERROR : PANIC in ARRAYLIST.[]  (index out of bounds)"<< endl;
  
}

template<typename T>
void ArrayList<T> :: purge()
{
  int new_size = m_size;
  for(int i = 0; i < m_size; i++)
  {
    for(int j = i+1; j < new_size; j++)
    {
      if(m_data[i] == m_data[j])
      {
        remove(j);
        new_size--;
        j --;
      }
    }
  }
}

template<typename T>
void ArrayList<T> :: reverse()
{
  int j = (m_size-1);
  T* tmp = new T[m_max];
  for(int k = 0; k < (m_size); k++)
  {
    tmp[k] = m_data[j];
    j--;
  }
  for(int i = 0; i < m_size; i++)
    m_data[i] = tmp[i];
  delete[] tmp;
}

#endif