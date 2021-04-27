#ifndef ADJACENCY_LIST_GRAPH_HPP_
#define ADJACENCY_LIST_GRAPH_HPP_

#include <memory>

#include "graphs/graph.hpp"

class AdjacencyListGraph : public Graph
{
    struct graphConnection
    {
        int endVertexIndex;
        int cost;
    };

  public:
    AdjacencyListGraph(const int& size);
    AdjacencyListGraph(const AdjacencyListGraph& otherMatrix);
    void print() override;
    static std::unique_ptr<Graph> createGraph(std::istream& is);
};

#endif /* ADJACENCY_LIST_GRAPH_HPP_ */
