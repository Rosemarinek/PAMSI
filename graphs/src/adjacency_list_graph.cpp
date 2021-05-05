#include "graphs/adjacency_list_graph.hpp"
#include <iostream>

std::unique_ptr<Graph> AdjacencyListGraph::createGraph(std::istream& is)
{
    std::string line;
    std::getline(is, line);
    std::istringstream iss{line};

    int size, connection, firstIndex;
    graphConnection box;
    iss >> size >> connection;

    AdjacencyListGraph list(size);

    for(int i = 0; i < connection; i++)
    {
        std::getline(is, line);
        std::istringstream iss{line};
        iss >> firstIndex >> box.endVertexIndex >> box.cost;
        list._List[firstIndex].push_back(box);
    }

    return std::make_unique<AdjacencyListGraph>(list);
}

AdjacencyListGraph::AdjacencyListGraph(const int& size)
{
    std::vector<std::vector<graphConnection>> listGraph(size);
    _List = listGraph;
}

AdjacencyListGraph::AdjacencyListGraph(const AdjacencyListGraph& otherList)
{
    _List = otherList._List;
}

void AdjacencyListGraph::print()
{
    for(auto i = 0; i < _List.size(); i++)
    {
        std::cout << i << ": ";
        for(auto& it : _List[i])
        {
            std::cout << "(" << it.endVertexIndex << ", " << it.cost << "), ";
        }
        std::cout << "\n";
    }
}
