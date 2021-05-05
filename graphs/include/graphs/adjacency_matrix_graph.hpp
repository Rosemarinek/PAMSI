#ifndef ADJACENCY_MATRIX_GRAPH_HPP_
#define ADJACENCY_MATRIX_GRAPH_HPP_

#include <limits.h>
#include <memory>
#include <vector>

#include "graphs/graph.hpp"

class AdjacencyMatrixGraph : public Graph
{
    int** _Matrix;
    int _Vertex;


  public:
    static std::unique_ptr<Graph> createGraph(std::istream& is);
    AdjacencyMatrixGraph(const int& size);
    AdjacencyMatrixGraph(const AdjacencyMatrixGraph& otherMatrix);
    void print() override;
};

#endif /* ADJACENCY_MATRIX_GRAPH_HPP_ */
