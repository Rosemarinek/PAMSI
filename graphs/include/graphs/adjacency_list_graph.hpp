#ifndef ADJACENCY_LIST_GRAPH_HPP_
#define ADJACENCY_LIST_GRAPH_HPP_

#include "graphs/graph.hpp"
#include <climits>
#include <memory>
#include <vector>

class AdjacencyListGraph : public Graph
{
    struct graphConnection
    {
        int endVertexIndex;
        int cost;
    };

    std::vector<std::vector<graphConnection>> _List;
    std::vector<std::vector<int>> _Edge;

  public:
    explicit AdjacencyListGraph(const int& size);
    AdjacencyListGraph(const AdjacencyListGraph& otherList);
    static std::unique_ptr<Graph> createGraph(std::istream& is);
    void print() override;
    int size() override;
    int operator()(const unsigned int& index, const unsigned int& index2) override;
    std::vector<std::vector<int>> Edge() override;
    ~AdjacencyListGraph() override = default;
};

#endif /* ADJACENCY_LIST_GRAPH_HPP_ */
