template<typename T>
Derived_Queue<T>::~Derived_Queue()
{	
  delete [] array;
}

template<typename T>
Derived_Queue<T>::Derived_Queue(int max)
{	
  m_max = max * 2;
  array = new T[m_max]; 
  m_size = 0;
}

template<typename T>
Derived_Queue<T>::Derived_Queue()
{
  array = NULL; 
  m_size = 0;
  m_max = 0;
}

template<typename T>
const T& Derived_Queue<T>::front() const throw (Oops)
{	
  T& first = array[0];
  return first;
}

template<typename T>
const T& Derived_Queue<T>::back() const throw (Oops)
{	
  T& last = array[m_max + 1]; 
  return last;
}
template<typename T>
bool Derived_Queue<T>::isEmpty() const
{	
  bool empty = false;
  if(m_size == 0) 
      empty = true;
  return empty;
}



template<typename T>
void Derived_Queue<T>::clear()
{	
    m_size = 0;
}

template<typename T>
void Derived_Queue<T>::dequeue()
{	
    if(m_size != 0)
    {
        for(int j = 0; j < m_size-1; j++)
        {
            array[j] = array[j+1];
        }
        m_size--;
    }
}


template<typename T>
void Derived_Queue<T>::enqueue(const T& x)
{	
  if(m_size == m_max)
  {
      m_max *= 2; 
      T * tmp = new T[m_max];
      for(int j = 0; j < m_size - 1; ++j)
      {
        tmp[j]= array[j];
      }
      tmp[m_size++] = x;
      delete [] array;
      array = tmp;
  }
    
    else
    {
        array[m_size++] = x;
    }
}




