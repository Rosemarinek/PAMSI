#ifndef ADJACENCY_MATRIX_GRAPH_HPP_
#define ADJACENCY_MATRIX_GRAPH_HPP_

#include <climits>
#include <memory>
#include <vector>

#include "graphs/graph.hpp"

class AdjacencyMatrixGraph : public Graph
{
    int** _Matrix;
    int _Vertex;

    std::vector<std::vector<int>> _Edge;

  public:
    static std::unique_ptr<Graph> createGraph(std::istream& is);
    explicit AdjacencyMatrixGraph(const int& size);
    AdjacencyMatrixGraph(const AdjacencyMatrixGraph& otherMatrix);
    void print() override;
    int size() override;
    int operator()(const unsigned int& index, const unsigned int& index2) override;
    std::vector<std::vector<int>> Edge() override;
    ~AdjacencyMatrixGraph() override;
};

#endif /* ADJACENCY_MATRIX_GRAPH_HPP_ */
