#ifndef LIST_HPP_
#define LIST_HPP_
#include <memory>
#include <stdexcept>

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
        std::shared_ptr<Node> _currNode;

      public:
        using difference_type = long;
        using value_type = T;
        using pointer = const std::shared_ptr<T>;
        using reference = const T&;
        using iterator_category = std::random_access_iterator_tag;

        Iterator(std::shared_ptr<Node> node = nullptr);

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
        std::shared_ptr<Node> _currNode;

      public:
        using difference_type = long;
        using value_type = T;
        using pointer = const std::shared_ptr<T>;
        using reference = const T&;
        using iterator_category = std::random_access_iterator_tag;

        ConstIterator(std::shared_ptr<Node> node = nullptr);

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

  private:
    std::shared_ptr<Node> _head;
    std::shared_ptr<Node> _tail;

  public:
    List();
    ~List();

    void pushBack(const T& newElement);
    void pushFront(const T& newElement);
    void insert(const T& newElement, int index);
    void removeOne(const T& element);
    void remove(const T& element);
    Iterator begin();
    Iterator end();
    ConstIterator cbegin() const;
    ConstIterator cend() const;
    T& operator[](int index);
    int lastIndex();
    bool isEmpty();
};

template <typename T>
List<T>::Node::Node()
{
    this->_next = nullptr;
    this->_previous = nullptr;
}


template <typename T>
List<T>::List()
{
    this->_head = nullptr;
    this->_tail = nullptr;
}


template <typename T>
List<T>::~List()
{
    std::shared_ptr<List<T>::Node> tmp;
    while(_head != nullptr)
    {
        tmp = _head;
        _head = _head->_next;
        tmp->_next = nullptr;
        tmp->_previous = nullptr;
    }

    _tail = nullptr;
}

template <typename T>
List<T>::Iterator::Iterator(typename std::shared_ptr<List<T>::Node> node)
{
    _currNode = node;
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator++()
{
    _currNode = _currNode->_next;
    return Iterator{_currNode};
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator--()
{
    _currNode = _currNode->_previous;
    return Iterator{_currNode};
}

template <typename T>
bool List<T>::Iterator::operator==(const Iterator& other) const
{

    return _currNode == other._currNode;
}

template <typename T>
bool List<T>::Iterator::operator!=(const Iterator& other) const
{
    auto it = Iterator(_currNode);
    return !(it == other);
}

template <typename T>
bool List<T>::Iterator::operator>(const Iterator& other) const
{
    auto tmp = _currNode;
    while(tmp != nullptr)
    {
        if(tmp == other._currNode)
        {
            return false;
        }
        tmp = tmp->_next;
    }
    return true;
}

template <typename T>
bool List<T>::Iterator::operator<(const Iterator& other) const
{
    auto it = Iterator(_currNode);
    return !(it > other);
}

template <typename T>
typename List<T>::Iterator::difference_type List<T>::Iterator::operator-(const Iterator& other) const
{
    auto it1 = Iterator(_currNode);
    auto it2 = Iterator(other);
    int counter = 0;

    while(it1 != it2)
    {
        if(it1 < it2)
        {
            ++it1;
            ++counter;
        }
        else
        {
            ++it2;
            ++counter;
        }
    }
    return counter;
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator+(difference_type diff) const
{
    auto tmp = Iterator(_currNode);

    for(int i = 0; i < diff; i++)
    {
        ++tmp;
    }
    return Iterator{tmp};
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator-(difference_type diff) const
{
    auto tmp = Iterator(_currNode);

    for(int i = 0; i < diff; i++)
    {
        --tmp;
    }
    return Iterator{tmp};
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator[](std::size_t i)
{
    auto it = Iterator(_currNode);

    it = it + i;

    return Iterator{it};
}

template <typename T>
T& List<T>::Iterator::operator*()
{
    return _currNode->_data;
}

template <typename T>
List<T>::ConstIterator::ConstIterator(typename std::shared_ptr<List<T>::Node> node)
{
    _currNode = node;
}

template <typename T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator++()
{
    _currNode = _currNode->_next;
    return ConstIterator{_currNode};
}

template <typename T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator--()
{
    _currNode = _currNode->_previous;
    return ConstIterator{_currNode};
}

template <typename T>
bool List<T>::ConstIterator::operator==(const ConstIterator& other) const
{
    return _currNode == other._currNode;
}

template <typename T>
bool List<T>::ConstIterator::operator!=(const ConstIterator& other) const
{
    auto it = ConstIterator(_currNode);
    return !(it == other);
}

template <typename T>
bool List<T>::ConstIterator::operator>(const ConstIterator& other) const
{
    auto tmp = _currNode;
    while(tmp != nullptr)
    {
        if(tmp == other._currNode)
        {
            return false;
        }
        tmp = tmp->_next;
    }
    return true;
}

template <typename T>
bool List<T>::ConstIterator::operator<(const ConstIterator& other) const
{
    auto it = ConstIterator(_currNode);
    return !(it > other);
}

template <typename T>
typename List<T>::ConstIterator::difference_type List<T>::ConstIterator::operator-(const ConstIterator& other) const
{
    auto it1 = ConstIterator(_currNode);
    auto it2 = ConstIterator(other);
    int counter = 0;

    while(it1 != it2)
    {
        if(it1 < it2)
        {
            ++it1;
            ++counter;
        }
        else
        {
            ++it2;
            ++counter;
        }
    }
    return counter;
}

template <typename T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator+(difference_type diff) const
{
    auto tmp = ConstIterator(_currNode);

    for(int i = 0; i < diff; i++)
    {
        ++tmp;
    }
    return ConstIterator{tmp};
}

template <typename T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator-(difference_type diff) const
{
    auto tmp = ConstIterator(_currNode);

    for(int i = 0; i < diff; i++)
    {
        --tmp;
    }
    return ConstIterator{tmp};
}

template <typename T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator[](std::size_t i)
{
    auto it = ConstIterator(_currNode);

    it = it + i;

    return ConstIterator{it};
}

template <typename T>
const T& List<T>::ConstIterator::operator*()
{
    return _currNode->_data;
}

template <typename T>
void List<T>::pushBack(const T& newElement)
{
    std::shared_ptr<Node> newElem;
    newElem = static_cast<std::shared_ptr<List<T>::Node>>(new List<T>::Node);
    newElem->_data = newElement;

    if(isEmpty())
    {
        _tail = newElem;
        _head = newElem;
    }
    else
    {
        newElem->_previous = _tail;
        _tail->_next = newElem;
        _tail = newElem;
    }
}

template <typename T>
void List<T>::pushFront(const T& newElement)
{
    std::shared_ptr<Node> newElem;
    newElem = static_cast<std::shared_ptr<List<T>::Node>>(new List<T>::Node);
    newElem->_data = newElement;

    if(isEmpty())
    {
        _tail = newElem;
        _head = newElem;
    }
    else
    {
        _head->_previous = newElem;
        newElem->_next = _head;
        _head = newElem;
    }
}
template <typename T>
void List<T>::insert(const T& newElement, int index)
{
    std::shared_ptr<Node> newElem;
    newElem = static_cast<std::shared_ptr<List<T>::Node>>(new List<T>::Node);
    newElem->_data = newElement;

    int number = lastIndex();
    if(isEmpty())
    {
        _tail = newElem;
        _head = newElem;
    }
    else
    {
        auto tmp = _head;

        for(int i = 0; i < index && i < number; i++)
        {
            tmp = tmp->_next;
        }

        if(index == 0)
        {
            pushFront(newElement);
        }
        else if(index == number + 1)
        {
            pushBack(newElement);
        }
        else if(index > number + 1)
        {
            throw std::invalid_argument("Out of range");
        }
        else
        {
            newElem->_previous = tmp->_previous;
            newElem->_next = tmp;
            tmp->_previous->_next = newElem;
            tmp->_previous = newElem;
        }
    }
}

template <typename T>
void List<T>::removeOne(const T& element)
{
    if(isEmpty())
    {
        throw std::logic_error("There is no element to remove");
    }

    else
    {
        auto tmp = _head;
        while(tmp->_data != element)
        {
            tmp = tmp->_next;
        }

        if(tmp->_previous == nullptr && tmp->_next == nullptr)
        {
            _head = nullptr;
            _tail = nullptr;
        }
        else if(tmp->_previous == nullptr)
        {
            _head = tmp->_next;
            tmp->_next->_previous = nullptr;
        }
        else if(tmp->_next == nullptr)
        {
            tmp->_previous->_next = nullptr;
            _tail = tmp->_previous;
        }
        else
        {
            tmp->_next->_previous = tmp->_previous;
            tmp->_previous->_next = tmp->_next;
        }
    }
}

template <typename T>
void List<T>::remove(const T& element)
{
    auto tmp = _head;
    while(tmp->_next != nullptr)
    {
        if(tmp->_data == element)
        {
            removeOne(element);
        }
        tmp = tmp->_next;
    }
}

template <typename T>
typename List<T>::Iterator List<T>::begin()
{
    return List::Iterator{_head};
}

template <typename T>
typename List<T>::Iterator List<T>::end()
{
    return List::Iterator{nullptr};
}

template <typename T>
typename List<T>::ConstIterator List<T>::cbegin() const
{
    return List::ConstIterator(_head);
}

template <typename T>
typename List<T>::ConstIterator List<T>::cend() const
{
    return List::ConstIterator(nullptr);
}

template <typename T>
T& List<T>::operator[](int index)
{
    auto tmp = _head;
    static T element;

    for(int i = 0; i < index; i++)
    {
        tmp = tmp->_next;
    }

    element = tmp->_data;

    return element;
}

template <typename T>
bool List<T>::isEmpty()
{

    if(_head == nullptr)
        return true;
    else
        return false;
}

template <typename T>
int List<T>::lastIndex()
{
    auto tmp = _head;
    int l_index = 0;

    while(tmp->_next != nullptr)
    {
        tmp = tmp->_next;
        l_index += 1;
    }

    return l_index;
}

#endif /* LIST_HPP_ */
