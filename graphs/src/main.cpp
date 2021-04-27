#include "graphs/adjacency_matrix_graph.hpp"
#include <catch2/catch.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "Tu wykonujemy testy efektywności algorytmów" << std::endl;

    std::ifstream inputFile;
    inputFile.open("../data/graph/graphV10D0.5.txt");
    auto graph = AdjacencyMatrixGraph::createGraph(inputFile);



    return 0;
}
