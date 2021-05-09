#ifndef GRAPH_HPP_
#define GRAPH_HPP_
#include <filesystem>
#include <fstream>
#include <vector>

class Graph
{
  public:
    virtual void print() = 0;
    virtual int size() = 0;
    virtual int operator()(const unsigned int& index, const unsigned int& index2) = 0;
    virtual std::vector<std::vector<int>> Edge() = 0;
    virtual ~Graph() = default;
};

#endif /* GRAPH_HPP_ */
