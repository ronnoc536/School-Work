// Connor Marler
// CS1575 Section 101
// Due: November 1, 2021



template <class T>
LinkedList<T>::~LinkedList() 
{
  clear();
  delete m_head;
  m_head = nullptr;
}

template <class T>
const LinkedList<T>& LinkedList<T>::operator= (const LinkedList<T>& rhs) 
{
  LLNode<T>* lhsIt;
  LLNode<T>* rhsIt;
  LLNode<T>* temp;
  m_size = rhs.m_size;
  lhsIt = m_head;
  rhsIt = rhs.m_head->m_next;
  
  // iterate through the rhs list
  while(rhsIt != nullptr)
  {
    // create the copy
    // if we already have a node to reuse, reuse instead of creating a new one.
    if(lhsIt->m_next != nullptr) 
    {
      temp = lhsIt->m_next;
    }
    else
    {
      temp = new LLNode<T>();
      lhsIt->m_next = temp;
    }
    // place in our list
    temp->m_data = rhsIt->m_data;
    lhsIt = temp;
    rhsIt = rhsIt->m_next;
  }

  // clean out any unused nodes from lhs
  lhsIt = lhsIt->m_next;
  while(lhsIt != nullptr)
  {
    temp = lhsIt->m_next;
    delete lhsIt;
    lhsIt = temp;
  }
  

  return *this;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs)
{
  LLNode<T>* lhsIt;
  LLNode<T>* rhsIt;
  LLNode<T>* temp;
  m_head = new LLNode<T>();
  m_size = rhs.m_size;
  lhsIt = m_head;
  rhsIt = rhs.m_head;
  
  // iterate through the rhs list
  while(rhsIt->m_next != nullptr)
  {
    // grab next one to copy
    rhsIt = rhsIt->m_next;
    // create the copy
    temp = new LLNode<T>();
    lhsIt->m_next = temp;
    // place in our list
    temp->m_data = rhsIt->m_data;
    lhsIt = temp;
  }
}

template <class T>
int LinkedList<T>::size() const 
{
  return m_size;
}

template <class T>
bool LinkedList<T>::isEmpty() const
{
  return m_size == 0;
}

template <class T>
LLNode<T>* LinkedList<T>::getFirstPtr()
{
  return m_head->m_next;
}

template <class T>
LLNode<T>* LinkedList<T>::getAtPtr(int i)
{
  int count = 0;
  LLNode<T>* runner = m_head->m_next;
  while(count < i && runner != nullptr)
  {
    ++count;
    runner = runner->m_next;
  }

  return runner;
}

template <class T>
void LinkedList<T>::clear()
{
  LLNode<T>* current = m_head->m_next;
  LLNode<T>* next;
  while(current != nullptr)
  {
    next = current->m_next;
    delete current;
    current = next;
  }
  m_head->m_next = nullptr;
  m_size = 0;
}

template <class T>
void LinkedList<T>::insert_front(const T& x)
{
  LLNode<T>* temp = new LLNode<T>(x, m_head->m_next);
  m_head->m_next = temp;
  ++m_size;
}

template <class T>
void LinkedList<T>::insert_back(const T& x)
{
  LLNode<T>* temp = new LLNode<T>(x, nullptr);
  LLNode<T>* runner = m_head;
  while(runner->m_next != nullptr)
  {
    runner = runner->m_next;
  }
  runner->m_next = temp;
  ++m_size;
}

template <class T>
void LinkedList<T>::insert(const T& x, LLNode<T>* pos)
{
  LLNode<T>* temp = new LLNode<T>(x, pos);
  LLNode<T>* runner = m_head;
  while(runner != nullptr && runner->m_next != pos)
  {
    runner = runner->m_next;
  }
  if(runner != nullptr)
  {
    runner->m_next = temp;
    ++m_size;
  }
}

template <class T>
void LinkedList<T>::remove_front()
{
  if(m_size > 0)
  {
    LLNode<T>* old = m_head->m_next;
    m_head->m_next = old->m_next;
    delete old;
    --m_size;
  }
}

template <class T>
void LinkedList<T>::remove_back()
{
  if(m_size > 0)
  {
    LLNode<T>* parent = m_head;
    LLNode<T>* child = m_head->m_next;
    while(child->m_next != nullptr)
    {
      parent = child;
      child = child->m_next;
    }

    parent->m_next = nullptr;
    delete child;
    --m_size;
  }
  
}

template <class T>
void LinkedList<T>::remove(LLNode<T>* pos)
{

  LLNode<T>* parent = m_head;
  LLNode<T>* child = m_head->m_next;  
  while(child != pos && child != nullptr)
  {
    parent = child;
    child = child->m_next;
  }

  if(pos == child && child != nullptr) 
  {
    parent->m_next = child->m_next;
    delete child;
    --m_size;
  }
}


template <class T>
bool LinkedList<T>::operator== (const LinkedList<T>& rhs) const
{
  bool diff = m_size != rhs.m_size;
  LLNode<T>* lhsRunner = m_head->m_next;
  LLNode<T>* rhsRunner = rhs.m_head->m_next;
  while(!diff && rhsRunner != nullptr && lhsRunner != nullptr)
  {
    if(rhsRunner->m_data != lhsRunner->m_data)
    {
      diff = true;
    }
    else
    {
      rhsRunner = rhsRunner->m_next;
      lhsRunner = lhsRunner->m_next;
    }
  }
  diff = diff || !(rhsRunner == nullptr && lhsRunner == nullptr);
  return !diff;
}


template <class T>
LLNode<T>* LinkedList<T>::find(const T& x)
{
  LLNode<T>* runner = m_head->m_next;
  while(runner != nullptr && runner->m_data != x)
  {
    runner = runner->m_next;
  }
  return runner;
}


template <class T>
void LinkedList<T>::reverse()
{
  if(m_size > 1) 
  {
    LLNode<T>* parent = m_head;
    LLNode<T>* child = parent->m_next;
    // iterate through list
    while(child != nullptr)
    {
      // get next position so we don't lose our iteration
      LLNode<T>* temp = child->m_next;
      // set child to parent so it looks the otherway
      child->m_next = parent;
      // update pointers going forward
      parent = child;
      child = temp;
    }
    // clean up the very first node's parent
    m_head->m_next->m_next = nullptr;
    // set head to correct one now we finished
    m_head->m_next = parent;
  }
}


template <class T>
void LinkedList<T>::append(const LinkedList<T>& l2)
{
  LLNode<T>* runner = m_head;
  LLNode<T>* l2Runner = l2.m_head->m_next;

  m_size += l2.m_size;
  while(runner->m_next != nullptr)
  {
    runner = runner->m_next;
  }
  while(l2Runner != nullptr)
  {
    LLNode<T>* temp = new LLNode<T>(l2Runner->m_data, nullptr);
    runner->m_next = temp;
    runner = temp;
    l2Runner = l2Runner->m_next;
  }
}

template <class T>
void LinkedList<T>::slice(const LinkedList<T>& l2, LLNode<T>* start, LLNode<T>* stop)
{
  LLNode<T>* runner = m_head;
  LLNode<T>* l2Runner = l2.m_head;
  LLNode<T>* temp;
  int count = 0;
  while(l2Runner != start && l2Runner != nullptr)
  {
    l2Runner = l2Runner->m_next;
  }

  if(l2Runner == nullptr)
  {
    // start node wasn't in the list
    return;
  }

  while(l2Runner != stop && l2Runner != nullptr)
  {
    if(runner->m_next != nullptr)
    {
      temp = runner->m_next;
    }
    else 
    {
      temp = new LLNode<T>();
      runner->m_next = temp;
    }

    temp->m_data = l2Runner->m_data;
    runner = temp;
    l2Runner = l2Runner->m_next;
    ++count;
  }

  // cleanup any unused nodes
  runner = runner->m_next;
  while(runner != nullptr)
  {
    temp = runner->m_next;
    delete runner;
    runner = temp;
  }

  m_size = count;
}

template <class T>
std::ostream& operator<< (std::ostream& out, const LinkedList<T>& list)
{
  LLNode<T>* runner = list.m_head->m_next;
  out << "[ ";
  while(runner != nullptr)
  {
    out << runner->m_data << ", ";
    runner = runner->m_next;
  }  
  out << "]";
  return out;
}