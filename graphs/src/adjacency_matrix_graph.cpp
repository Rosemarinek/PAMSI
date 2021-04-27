#include "graphs/adjacency_matrix_graph.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std::string_literals;

std::unique_ptr<Graph> AdjacencyMatrixGraph::createGraph(std::istream& is)
{
    if(is)
    {
        std::string line;
        std::getline(is, line);
        std::istringstream iss{line};

        int size;
        int connection;
        int row;
        int column;
        int cost;
        int begin;

        iss >> size >> connection;

        AdjacencyMatrixGraph matrix(size);

        for(int i = 0; i < connection; i++)
        {
            std::getline(is, line);
            std::istringstream iss{line};
            iss >> row >> column >> cost;
            matrix._Matrix[row][column] = cost;

        }
        return std::make_unique<AdjacencyMatrixGraph>(matrix);
    }
    else
    {
        AdjacencyMatrixGraph matrix0(0);
        return std::make_unique<AdjacencyMatrixGraph>(matrix0);
    }
}

AdjacencyMatrixGraph::AdjacencyMatrixGraph(const int& size)
{
    std::vector<std::vector<int>> matrixGraph(size, std::vector<int>(size));
    _Matrix=matrixGraph;

    for(int row = 0; row < size; row++)
    {
        for(int column = 0; column < size; column++)
        {
           _Matrix[row][column] = INT_MAX;
        }
    }
}

AdjacencyMatrixGraph::AdjacencyMatrixGraph(const AdjacencyMatrixGraph& otherMatrix)
{
    for(size_t row = 0; row < _Matrix.size(); row++)
    {
        for(size_t column = 0; column < _Matrix.size(); column++)
        {
            _Matrix[row][column] = otherMatrix._Matrix[row][column];
        }
    }
}
