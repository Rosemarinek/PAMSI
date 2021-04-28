#include "graphs/adjacency_matrix_graph.hpp"
#include <filesystem>
#include <iostream>

using namespace std::string_literals;

std::unique_ptr<Graph> AdjacencyMatrixGraph::createGraph(std::istream& is)
{
    if(is)
    {
        std::string line;
        std::getline(is, line);
        std::istringstream iss{line};

        int size, connection, row, column, cost;
        iss >> size >> connection;

        AdjacencyMatrixGraph matrix(size);

        for(int i = 0; i < connection; i++)
        {
            std::getline(is, line);
            std::istringstream iss{line};
            iss >> row >> column >> cost;
            matrix._Matrix[row][column] = cost;
        }
        //TODO: fix return
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
    _Matrix = matrixGraph;

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
    for(int row = 0; row < _Matrix.size(); row++)
    {
        for(int column = 0; column < _Matrix[row].size(); column++)
        {
            _Matrix[row][column] = otherMatrix._Matrix[row][column];
        }
    }
}

void AdjacencyMatrixGraph::print()
{

    for (auto i = 0; i < _Matrix.size(); i++)
    {
        for (int j = 0; j < _Matrix[i].size(); j++)
        {
            std::cout << _Matrix[i][j]<<" ";
        }
        std::cout<< "\n";
    }
}
AdjacencyMatrixGraph::AdjacencyMatrixGraph()
{

}
