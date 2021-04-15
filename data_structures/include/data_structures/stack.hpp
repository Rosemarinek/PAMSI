#ifndef STACK_HPP_
#define STACK_HPP_
#include "list.hpp"

template <typename T>
class Stack
{
  public:
    List<T> _Stack;
    void push(const T& newElement);
    T pop();
};

template <typename T>
void Stack<T>::push(const T& newElement)
{
    _Stack.pushFront(newElement);
}

template <typename T>
T Stack<T>::pop()
{
    T rem = _Stack[0];
    _Stack.removeOne(_Stack[0]);

    return T(rem);
}

#endif /* STACK_HPP_ */
