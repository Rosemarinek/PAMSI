#ifndef QUEUE_HPP_
#define QUEUE_HPP_
#include "list.hpp"

template <typename T>
class Queue
{
  public:
    List <T> _Queue;
    void enqueue(const T& newElement);
    T dequeue();
};

template <typename T>
void Queue<T>::enqueue(const T& newElement)
{
   _Queue.pushBack(newElement);
}

template <typename T>
T Queue<T>::dequeue()
{
    T rem =  _Queue[0];
    _Queue.remove( _Queue[0]);
    return T(rem);

}

#endif /* QUEUE_HPP_ */
