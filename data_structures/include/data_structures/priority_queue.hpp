#ifndef PRIORITY_QUEUE_HPP_
#define PRIORITY_QUEUE_HPP_
#include "list.hpp"

template <typename T>
class PriorityQueue
{
  public:
    struct PriorityData
    {
        T _prioData;
        int _priority;

        bool operator!=(const PriorityData& otherPriorityData) const
        {
            return (this->_priority != otherPriorityData._priority && this->_prioData != otherPriorityData._priority);
        }

        bool operator<(const PriorityData& otherPriorityData) const
        {
            return (this->_priority < otherPriorityData._priority);
        }
    };

    List<PriorityData> _PrioQueue;

    void enqueue(const T& newElement, int priority);
    T dequeue();
};

#endif /* PRIORITY_QUEUE_HPP_ */

template <typename T>
void PriorityQueue<T>::enqueue(const T& newElement, int priority)
{
    int index = 0;
    PriorityData element{newElement, priority};

    if(_PrioQueue._head == nullptr)
    {
       _PrioQueue.pushFront(element);
    }

    else
    {
        auto tmp = _PrioQueue[index];
        if(_PrioQueue._head->_next==nullptr && element <tmp)
        {
            _PrioQueue.pushBack(element);
        }
        else
        {
            while(element < tmp)
            {
                index += 1;
                tmp = _PrioQueue[index];
            }
            _PrioQueue.insert(element, index);
        }

    }
}

template <typename T>
T PriorityQueue<T>::dequeue()
{

    PriorityData rem = _PrioQueue[0];
    _PrioQueue.remove(_PrioQueue[0]);
    return T(rem._prioData);
}
