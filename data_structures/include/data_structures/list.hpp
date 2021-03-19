#ifndef LIST_HPP_
#define LIST_HPP_
#include <memory>
//#include <stdexcept>

template <typename T>
class List
{
  public:
    class Node
    {
      public:
        T _data;
        std::shared_ptr<Node> _next;
        std::shared_ptr<Node> _previous;

         Node();
    };


    class Iterator
    {
      public:
        using difference_type = long;
        using value_type = T;
        using pointer = const T*;
        using reference = const T&;
        using iterator_category = std::random_access_iterator_tag;

        Iterator(Node* node = nullptr);

        Iterator operator++();
        Iterator operator--();
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
        bool operator>(const Iterator& other) const;
        bool operator<(const Iterator& other) const;
        difference_type operator-(const Iterator& other) const;
        Iterator operator+(difference_type diff) const;
        Iterator operator-(difference_type diff) const;
        Iterator operator[](std::size_t i);
        T& operator*();
    };

    class ConstIterator
    {
    public:
      using difference_type = long;
      using value_type = T;
      using pointer = const T*;
      using reference = const T&;
      using iterator_category = std::random_access_iterator_tag;

      ConstIterator(Node* node = nullptr);

      ConstIterator operator++();
      ConstIterator operator--();
      bool operator==(const ConstIterator& other) const;
      bool operator!=(const ConstIterator& other) const;
      bool operator>(const ConstIterator& other) const;
      bool operator<(const ConstIterator& other) const;
      difference_type operator-(const ConstIterator& other) const;
      ConstIterator operator+(difference_type diff) const;
      ConstIterator operator-(difference_type diff) const;
      ConstIterator operator[](std::size_t i);
      const T& operator*();
    };

    /*???*/
    std::shared_ptr<Node> _head;
    std::shared_ptr<Node> _tail;
    explicit List();

    void pushBack(const T& newElement);
    void pushFront(const T& newElement);
    void insert(const T& newElement, int index);
    void remove(const T& element);
    Iterator begin();
    Iterator end();
    ConstIterator cbegin() const;
    ConstIterator cend() const;
    T& operator[](int index);
};

/*konstruktor dla wezla*/
template <typename T>
List<T>::Node::Node()
{
    this-> _next = nullptr;
    this-> _previous= nullptr;
}

/*konstruktor dla listy*/
template <typename T>
List<T>::List()
{
    this-> _head = nullptr;
    this -> _tail = nullptr;
}



template <typename T>
List<T>::Iterator::Iterator(typename List<T>::Node* node)
{
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator++()
{
  // TODO: implement
  return Iterator();
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator--()
{
  // TODO: implement
  return Iterator();
}

template <typename T>
bool List<T>::Iterator::operator==(const Iterator& other) const
{
  // TODO: implement
  return true;
}

template <typename T>
bool List<T>::Iterator::operator!=(const Iterator& other) const
{
  // TODO: implement
  return true;
}

template <typename T>
bool List<T>::Iterator::operator>(const Iterator& other) const
{
  // TODO: implement
  return true;
}

template <typename T>
bool List<T>::Iterator::operator<(const Iterator& other) const
{
  // TODO: implement
  return true;
}

template <typename T>
typename List<T>::Iterator::difference_type List<T>::Iterator::operator-(const Iterator& other) const
{
  // TODO: implement
  return 0;
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator+(difference_type diff) const
{
  // TODO: implement
  return Iterator();
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator-(difference_type diff) const
{
  // TODO: implement
  return Iterator();
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator[](std::size_t i)
{
  // TODO: implement
  return Iterator();
}

template <typename T>
T& List<T>::Iterator::operator*()
{
    // TODO: implement
    static T element;
    return element;
}





template <typename T>
List<T>::ConstIterator::ConstIterator(typename List<T>::Node* node)
{
}

template <typename T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator++()
{
  // TODO: implement
  return ConstIterator();
}

template <typename T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator--()
{
  // TODO: implement
  return ConstIterator();
}

template <typename T>
bool List<T>::ConstIterator::operator==(const ConstIterator& other) const
{
  // TODO: implement
  return true;
}

template <typename T>
bool List<T>::ConstIterator::operator!=(const ConstIterator& other) const
{
  // TODO: implement
  return true;
}

template <typename T>
bool List<T>::ConstIterator::operator>(const ConstIterator& other) const
{
  // TODO: implement
  return true;
}

template <typename T>
bool List<T>::ConstIterator::operator<(const ConstIterator& other) const
{
  // TODO: implement
  return true;
}

template <typename T>
typename List<T>::ConstIterator::difference_type List<T>::ConstIterator::operator-(const ConstIterator& other) const
{
  // TODO: implement
  return 0;
}

template <typename T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator+(difference_type diff) const
{
  // TODO: implement
  return Iterator();
}

template <typename T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator-(difference_type diff) const
{
  // TODO: implement
  return ConstIterator();
}

template <typename T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator[](std::size_t i)
{
  // TODO: implement
  return Iterator();
}

template <typename T>
const T& List<T>::ConstIterator::operator*()
{
    // TODO: implement
    static T element;
    return element;
}



template <typename T>
void List<T>::pushBack(const T& newElement)
{
    //tworzenie nowego elementu
    std::shared_ptr<Node> newElem;
    newElem = static_cast<std::shared_ptr<List<T>::Node>>(new List<T>::Node);
    newElem -> _data = newElement;

    // TODO: wyrzucanie wyjatkow
//    if(newElem== nullptr)
//    {
//        throw std::invalid_argument( "Memory allocation problem" ); //???
//    }

    if (_head == nullptr) //jesli lista jest pusta
    {
        _tail == newElem;
        _head == newElem;
    }
    else //jesli na liscie sa jakies elementy
    {
       _tail->_next = newElem;  //to na co wskazuje tail, niech wskazuje na newELem
       newElem -> _previous = _tail; // niech previous wskazuje na to na co tail
       _tail = newElem; //niech tail wskazuje na newElem

    }
}
template <typename T>
void List<T>::pushFront(const T& newElement)
{
    //tworzenie nowego elementu
    std::shared_ptr<Node> newElem;
    newElem = static_cast<std::shared_ptr<List<T>::Node>>(new List<T>::Node);
    newElem -> _data = newElement;

    if (_head == nullptr) //jesli lista jest pusta
    {
        _tail == newElem;
        _head == newElem;
    }
    else //jesli na liscie sa jakies elementy
    {
        _head->_previous = newElem;
        newElem -> _previous = nullptr;
        _head = newElem;

    }
}
template <typename T>
void List<T>::insert(const T& newElement, int index)
{
    std::shared_ptr<Node> newElem;
    newElem = static_cast<std::shared_ptr<List<T>::Node>>(new List<T>::Node);
    newElem -> _data = newElement;

    if (_head == nullptr) //jesli lista jest pusta
    {
        _tail == newElem;
        _head == newElem;
    }
    else //jesli ma elementy
    {
        auto tmp = _head;
        for(int i=1;i+1 <index; ++i)
        {
            tmp=tmp->_next;
        }
        newElem->_next = tmp->_next;
        newElem ->_previous = tmp;
        tmp ->_next = newElem;
        tmp ->_next ->_previous =newElem;
    }


}

template <typename T>
void List<T>::remove(const T& element)
{
    if (_head == nullptr) //jesli lista jest pusta
    {
        //TODO: informacja o bledzie
    }

    auto tmp = _head;
    while(tmp->_data !=element)
    {
       tmp = tmp ->_next;
    }

    tmp->_next->_previous = tmp->_previous;
    tmp->_previous = tmp-> _next;


}

template <typename T>
typename List<T>::Iterator List<T>::begin()
{
    // TODO: implement
    return Iterator();
}

template <typename T>
typename List<T>::Iterator List<T>::end()
{
    // TODO: implement
    return Iterator();
}

template <typename T>
typename List<T>::ConstIterator List<T>::cbegin() const
{

    // TODO: implement
    return ConstIterator();
}

template <typename T>
typename List<T>::ConstIterator List<T>::cend() const
{
    return ConstIterator();
    // TODO: implement
}

template <typename T>
T& List<T>::operator[](int index)
{
    // TODO: implement
    static T element;
    return element;
}

#endif /* LIST_HPP_ */
