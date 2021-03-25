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
        using pointer = const std::shared_ptr<T>; // ZMIANA
        using reference = const T&;
        using iterator_category = std::random_access_iterator_tag;
        std::shared_ptr<Node> _currNode;
        Iterator(std::shared_ptr<Node> node = nullptr); // ZMIANA

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

    std::shared_ptr<Node> _head;
    std::shared_ptr<Node> _tail;

    List();
    ~List();

    void pushBack(const T& newElement);
    void pushFront(const T& newElement);
    void insert(const T& newElement, int index);
    void remove(const T& element);
    Iterator begin();
    Iterator end();
    ConstIterator cbegin() const;
    ConstIterator cend() const;
    T& operator[](int index);
    int lastIndex(std::shared_ptr<Node> list);
};

/*konstruktor dla wezla*/
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
    while(_head->_next != nullptr)
    {
        tmp = _head;
        _head = _head->_next;
        tmp->_next = nullptr;
        tmp->_previous = nullptr;
    }

    _head = nullptr;
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

    return Iterator(_currNode->_next);
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator--()
{
    return Iterator(_currNode->_previous);
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
List<T>::ConstIterator::ConstIterator(typename std::shared_ptr<List<T>::Node> node)
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
    // tworzenie nowego elementu
    std::shared_ptr<Node> newElem;
    newElem = static_cast<std::shared_ptr<List<T>::Node>>(new List<T>::Node);
    newElem->_data = newElement;

    // TODO: wyrzucanie wyjatkow

    if(_head == nullptr) // jesli lista jest pusta
    {
        _tail = newElem;
        _head = newElem;
    }
    else // jesli na liscie sa jakies elementy
    {

        newElem->_previous = _tail; // niech previous wskazuje na to na co tail
        _tail->_next = newElem;     // to na co wskazuje tail, niech wskazuje na newELem

        _tail = newElem; // niech tail wskazuje na newElem
    }
}

template <typename T>
void List<T>::pushFront(const T& newElement)
{
    // tworzenie nowego elementu
    std::shared_ptr<Node> newElem;
    newElem = static_cast<std::shared_ptr<List<T>::Node>>(new List<T>::Node);
    newElem->_data = newElement;

    if(_head == nullptr) // jesli lista jest pusta
    {
        _tail = newElem;
        _head = newElem;
    }
    else // jesli na liscie sa jakies elementy
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

    int number = lastIndex(_head);

    if(_head == nullptr) // jesli lista jest pusta
    {
        _tail = newElem;
        _head = newElem;
    }
    else // jesli ma elementy
    {
        auto tmp = _head;

        for(int i = 0; i < index && i < number; i++)
        {
            tmp = tmp->_next;
        }

        if(tmp->_previous == nullptr)
        {
            pushFront(newElement);
        }
        else if(index == number + 1)
        {
            pushBack(newElement);
        }
        else if(index > number + 1)
        {
            // TODO: wyrzucanie wyjatku
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
void List<T>::remove(const T& element)
{
    if(_head == nullptr) // jesli lista jest pusta
    {
        // TODO: Wyrzucanie wyjatku
        std::cerr << "There are no items to remove \n";
    }

    else
    {
        auto tmp = _head;
        while(tmp->_data != element)
        {
            tmp = tmp->_next;
        }

        if(tmp->_previous == nullptr && tmp->_next == nullptr) // jesli chcemy usunac  jedyny element
        {
            _head = nullptr;
            _tail = nullptr;
        }
        else if(tmp->_previous == nullptr) // jesli chcemy usunac pierwszy element
        {
            _head = tmp->_next;
            tmp->_next->_previous = nullptr;
        }
        else if(tmp->_next == nullptr) // jesli chcemy usunac ostatni element
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
int List<T>::lastIndex(std::shared_ptr<Node> list) // funkcja zwraca nr indeksu ostatniego elementu na liscie
{

    int l_index = 0;

    while(list->_next != nullptr)
    {
        list = list->_next;
        l_index += 1;
    }

    return l_index;
}

#endif /* LIST_HPP_ */
