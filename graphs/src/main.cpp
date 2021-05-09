#include "graphs/adjacency_list_graph.hpp"
#include "graphs/adjacency_matrix_graph.hpp"
#include <catch2/catch.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "Adjacency list:" << std::endl;

    std::ifstream inputFile;
    inputFile.open("../data/graph/graphV10D0.5.txt");
    auto graphL = AdjacencyListGraph::createGraph(inputFile);
    graphL->print();
    inputFile.close();

    std::cout << "\n";

    std::cout << "Adjacency matrix:" << std::endl;

    inputFile.open("../data/graph/graphV10D0.5.txt");
    auto graphM = AdjacencyMatrixGraph::createGraph(inputFile);
    graphM->print();
    inputFile.close();

    return 0;
}
