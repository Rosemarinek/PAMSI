#include "graphs/adjacency_matrix_graph.hpp"
#include <filesystem>
#include <iostream>

using namespace std::string_literals;

std::unique_ptr<Graph> AdjacencyMatrixGraph::createGraph(std::istream& is)
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
        std::vector<int> edge{row, column, cost};
        matrix._Edge.push_back(edge);

        matrix._Matrix[row][column] = cost;
    }

    return std::make_unique<AdjacencyMatrixGraph>(matrix);
}

AdjacencyMatrixGraph::AdjacencyMatrixGraph(const int& size)
{

    _Vertex = size;
    _Matrix = new int*[size];
    for(int row = 0; row < size; row++)
    {
        _Matrix[row] = new int[size];
    }

    for(int row = 0; row < size; row++)
    {
        for(int column = 0; column < size; column++)
        {
            _Matrix[row][column] = INT_MAX;
        }
    }
}

AdjacencyMatrixGraph::AdjacencyMatrixGraph(const AdjacencyMatrixGraph& otherMatrix)
    : AdjacencyMatrixGraph(otherMatrix._Vertex)
{

    for(int row = 0; row < otherMatrix._Vertex; row++)
    {
        for(int column = 0; column < otherMatrix._Vertex; column++)
        {
            _Matrix[row][column] = otherMatrix._Matrix[row][column];
        }
    }
    _Edge = otherMatrix._Edge;
}

void AdjacencyMatrixGraph::print()
{

    for(auto i = 0; i < _Vertex; i++)
    {
        for(int j = 0; j < _Vertex; j++)
        {
            std::cout << _Matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int AdjacencyMatrixGraph::size()
{
    return _Vertex;
}

int AdjacencyMatrixGraph::operator()(const unsigned int& index, const unsigned int& index2)
{

    return _Matrix[index][index2];
}

AdjacencyMatrixGraph::~AdjacencyMatrixGraph()
{
    for(int i = 0; i < _Vertex; ++i)
    {
        delete[] _Matrix[i];
    }
    delete[] _Matrix;
}

std::vector<std::vector<int>> AdjacencyMatrixGraph::Edge()
{
    return std::vector<std::vector<int>>(_Edge);
}
