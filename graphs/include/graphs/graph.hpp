#ifndef GRAPH_HPP_
#define GRAPH_HPP_
#include <filesystem>
#include <fstream>

class Graph
{
  public:
    virtual void print() = 0;
    virtual int size() = 0;
    virtual int operator()(const unsigned int& index, const unsigned int& index2) = 0;

    virtual ~Graph() = default;
};

#endif /* GRAPH_HPP_ */
