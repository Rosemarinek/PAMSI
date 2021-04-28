#ifndef ADJACENCY_LIST_GRAPH_HPP_
#define ADJACENCY_LIST_GRAPH_HPP_

#include <memory>
#include <vector>
#include "graphs/graph.hpp"

class AdjacencyListGraph : public Graph
{
    struct graphConnection
    {
        int endVertexIndex;
        int cost;
    };

    std::vector<std::vector<graphConnection>> _List;
  public:
    AdjacencyListGraph(const int& size);
    AdjacencyListGraph(const AdjacencyListGraph& otherList);
    void print() override;
    static std::unique_ptr<Graph> createGraph(std::istream& is);
};

#endif /* ADJACENCY_LIST_GRAPH_HPP_ */
