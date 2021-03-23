#ifndef PRIORITY_QUEUE_HPP_
#define PRIORITY_QUEUE_HPP_

template <typename T>
class PriorityQueue
{
  public:
    typedef struct
    {
        int _priority;
        T _data;
    } prioData;

    List<PriorityQueue<T>::prioData > prioQueue;

    void enqueue(const T& newElement, int priority);
    T dequeue();
};


template <typename T>
void PriorityQueue<T>::enqueue(const T& newElement, int priority)
{


}

template <typename T>
T PriorityQueue<T>::dequeue()
{
  // TODO: implement
  return T();
}

#endif /* PRIORITY_QUEUE_HPP_ */
