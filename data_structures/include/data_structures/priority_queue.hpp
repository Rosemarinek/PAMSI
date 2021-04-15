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
            return (this->_priority != otherPriorityData._priority &&
                    this->_prioData != otherPriorityData._prioData); //??
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

template <typename T>
void PriorityQueue<T>::enqueue(const T& newElement, int priority)
{
    int index = 0;
    PriorityData element{newElement, priority};

    try
    {
        if(_PrioQueue.isEmpty())
        {
            _PrioQueue.pushFront(element);
        }
        else
        {

            while(element < _PrioQueue[index] && index < _PrioQueue.lastIndex())
            {
                index += 1;
            }

            if(element < _PrioQueue[index])
            {
                _PrioQueue.insert(element, index + 1);
            }
            else
            {
                _PrioQueue.insert(element, index);
            }
        }
    }
    catch(const char* err)
    {
        std::cerr << err;
    }
}

template <typename T>
T PriorityQueue<T>::dequeue()
{
    PriorityData rem = _PrioQueue[0];
    _PrioQueue.removeOne(_PrioQueue[0]);

    return T(rem._prioData);
}

#endif /* PRIORITY_QUEUE_HPP_ */