#ifndef MAP_HPP_
#define MAP_HPP_
#define SIZE 1000

template <typename KeyType, typename ValueType>
class Map
{
  public:
    int Hash(std::string str);
    int Hash(int intg);
    int Hash(char character);

    Map();
    Map(const Map& otherMap);
    void insert(const KeyType& key, const ValueType& value);
    ValueType& operator[](const KeyType& key);
    void remove(const KeyType& key);

  private:
    std::array<ValueType, SIZE> _Map;
    std::array<bool, SIZE> _MapBool;
};

template <typename KeyType, typename ValueType>
int Map<KeyType, ValueType>::Hash(std::string str)
{
    int result = 0;
    for(auto i = 0; i < str.length(); i++)
    {
        result += static_cast<int>(str[i]);
    }
    return result % 1000;
}

template <typename KeyType, typename ValueType>
int Map<KeyType, ValueType>::Hash(int intg)
{
    return intg % 1000;
}

template <typename KeyType, typename ValueType>
int Map<KeyType, ValueType>::Hash(char character)
{
    int result = 0;
    result += static_cast<int>(character);

    return result % 1000;
}



template <typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::insert(const KeyType& key, const ValueType& value)
{
    int index = Hash(key);
    if(!(_Map[index]))
    {
        _Map[index] = value;
        _MapBool[index] = true;
    }


}

template <typename KeyType, typename ValueType>
ValueType& Map<KeyType, ValueType>::operator[](const KeyType& key)
{
    int index = Hash(key);
    return _Map[index];
}

template <typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::remove(const KeyType& key)
{
    auto index = Hash(key);
    _Map[index] = 0;
    _MapBool[index] = false;
}

template <typename KeyType, typename ValueType>
Map<KeyType, ValueType>::Map()
{
    for(int i=0;i<SIZE;i++)
    {
        _Map[i]=0;
        _MapBool[i]=false;
    }
}

template <typename KeyType, typename ValueType>
Map<KeyType, ValueType>::Map(const Map& otherMap)
{
    for(int i=0;i<SIZE;i++)
    {
        _Map[i]=otherMap._Map[i];
        _MapBool[i]=otherMap._MapBool[i];
    }
}

#endif /* MAP_HPP_ */
