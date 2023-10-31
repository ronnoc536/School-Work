#ifndef QUEUE_H
#define QUEUE_H

#include "abstractqueue.h"

template<typename T>
class Derived_Queue : public AbstractQueue<T>
{
  public:
    Derived_Queue();
    Derived_Queue(int max);
    bool isEmpty() const;
    void enqueue(const T& x);
    void dequeue();
    void clear();
    const T& front() const throw (Oops);
    const T& back() const throw (Oops);
    virtual ~Derived_Queue();

  private:
    T * array;
    int m_size;
    int m_max;
    
    
};






#include "queue.hpp"
#endif