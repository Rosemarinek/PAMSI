//#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <stdlib.h>

TEST_CASE("List_STL/push_front")
{
    std::list<int> list;

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    auto it1 = list.begin();

    REQUIRE(*it1 == 3);
    REQUIRE(*(++it1) == 2);
    REQUIRE(*(++it1) == 1);
}

TEST_CASE("List_STL/pop_front")
{
    std::list<int> list;

    list.push_front(1);
    list.push_front(2);

    list.pop_front();
    auto it1 = list.begin();

    REQUIRE(*it1 == 1);
}

TEST_CASE("List_STL/push_back")
{
    std::list<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    auto it1 = list.end();

    REQUIRE(*(--it1) == 3);
    REQUIRE(*(--it1) == 2);
    REQUIRE(*(--it1) == 1);
}

TEST_CASE("List_STL/pop_back")
{
    std::list<int> list;

    list.push_back(1);
    list.push_back(2);

    list.pop_back();
    auto it1 = list.end();

    REQUIRE(*(--it1) == 1);
}

TEST_CASE("List_STL/insert")
{
    std::list<int> list;

    list.push_back(1);
    list.push_back(4);

    auto it = list.begin();

    list.insert(++it, 2);
    list.insert(it, 3);

    auto it1 = list.begin();

    REQUIRE(*(it1) == 1);
    REQUIRE(*(++it1) == 2);
    REQUIRE(*(++it1) == 3);
    REQUIRE(*(++it1) == 4);
}

 TEST_CASE("List_STL/remove")
{
    std::list<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.remove(2);
    auto it1 = list.end();

    REQUIRE(*(--it1) == 3);
    REQUIRE(*(--it1) == 1);
}


TEST_CASE("List_STL/iterator")
{
    std::list<int> list;

    list.push_back(1);
    list.push_back(3);
    list.push_back(2);

    list.sort();

    auto it1 = list.end();
    auto it2 = list.begin();

    REQUIRE(*(--it1) == 3);
    REQUIRE(*(--it1) == 2);
    REQUIRE(*(it2) == 1);
}


TEST_CASE("List_STL/constIterator")
{

    std::list<int> list;

    std::array<int, 3> refArray = {1, 2, 3};

    for(auto& element : refArray)
    {
        list.push_back(element);
    }

    int index = 0;
    for(auto it = list.cbegin(); it != list.cend(); ++it)
    {
        REQUIRE(*it == refArray[index++]);
    }
}


TEST_CASE("Stack_STL")
{
    std::stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    stack.pop();
    REQUIRE(stack.top() == 2);
    stack.pop();
    REQUIRE(stack.top() == 1);
}

TEST_CASE("Queue_STL")
{
    std::queue<int> queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);

    queue.pop();
    REQUIRE(queue.front() == 2);
    queue.pop();
    REQUIRE(queue.front() == 3);
}

TEST_CASE("Priority_Queue_STL")
{
    std::priority_queue<int> priorityQueue;

    priorityQueue.push(1);
    priorityQueue.push(4);
    priorityQueue.push(2);
    priorityQueue.push(3);

    priorityQueue.pop();
    REQUIRE(priorityQueue.top() == 3);
    priorityQueue.pop();
    REQUIRE(priorityQueue.top() == 2);
    priorityQueue.pop();
    REQUIRE(priorityQueue.top() == 1);
}

TEST_CASE("Map_STL")
{
    std::map<std::string, int> hashArray;
    std::map<std::string, int> refHashArray = {{"one", 1}, {"two", 2}, {"three", 3}};

    auto it = hashArray.begin();

    for(auto& keyValue : refHashArray)
    {
        hashArray.insert(it, std::pair<std::string, int> (keyValue.first, keyValue.second));
    }

    for(auto& keyValue : refHashArray)
    {
        REQUIRE(keyValue.second == hashArray[keyValue.first]);
    }
}
