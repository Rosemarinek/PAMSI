#include "graphs/adjacency_list_graph.hpp"
#include "graphs/adjacency_matrix_graph.hpp"
#include "timer.hpp"
#include <catch2/catch.hpp>
#include <graphs/shortest_path_algorithms.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
    Timer timerLD, timerLB, timerMD, timerMB, timerLBNeg, timerMBNeg;

    std::ifstream inputFile;
    std::ofstream results;
    ShortestPathResult result;
    results.open("../results/result.csv");
    int sourceIndexL;
    int sourceIndexM;

    std::vector<std::string> graphFile = {
        "../data/graph/graphV10D0.25.txt",  "../data/graph/graphV10D0.5.txt",   "../data/graph/graphV10D0.75.txt",
        "../data/graph/graphV10D0.1.txt",   "../data/graph/graphV50D0.25.txt",  "../data/graph/graphV50D0.5.txt",
        "../data/graph/graphV50D0.75.txt",  "../data/graph/graphV50D0.1.txt",   "../data/graph/graphV100D0.25.txt",
        "../data/graph/graphV100D0.5.txt",  "../data/graph/graphV100D0.75.txt", "../data/graph/graphV100D0.1.txt",
        "../data/graph/graphV150D0.25.txt", "../data/graph/graphV150D0.5.txt",  "../data/graph/graphV150D0.75.txt",
        "../data/graph/graphV150D0.1.txt",  "../data/graph/graphV200D0.25.txt", "../data/graph/graphV200D0.5.txt",
        "../data/graph/graphV200D0.75.txt", "../data/graph/graphV200D0.1.txt"};

    std::vector<std::string> VD = {"10 0.25 ",  "10 0.5 ",   "10 0.75 ",  "10 1 ",     "50 0.25 ",
                                   "50 0.5 ",   "50 0.75 ",  "50 1 ",     "100 0.25 ", "100 0.5 ",
                                   "100 0.75 ", "100 1 ",    "150 0.25 ", "150 0.5 ",  "150 0.75 ",
                                   "100 1 ",    "200 0.25 ", "200 0.5 ",  "200 0.75 ", "200 0.1 "};

    if(results.good())
    {
        results << "Vertices "
                << "Density "
                << "Dijkstra-List "
                << "Dijkstra-Matrix "
                << "BellmanFord-List "
                << "BellmanFord-Matrix \n";
    }

    for(int i = 0; i < 3; ++i)
    {
        inputFile.open(graphFile[i]);
        auto graphL = AdjacencyListGraph::createGraph(inputFile);
        inputFile >> sourceIndexL;
        inputFile.close();

        inputFile.open(graphFile[i]);
        auto graphM = AdjacencyMatrixGraph::createGraph(inputFile);
        inputFile >> sourceIndexM;
        inputFile.close();

        if(results.good())
        {
            for(int j = 0; j < 50; ++j)
            {
                results << VD[i];

                timerLD.start();
                dijkstra(*graphL, sourceIndexL, result);
                timerLD.stop();

                timerMD.start();
                dijkstra(*graphM, sourceIndexM, result);
                timerMD.stop();

                timerLB.start();
                bellmanFord(*graphL, sourceIndexL, result);
                timerLB.stop();

                timerMB.start();
                bellmanFord(*graphM, sourceIndexM, result);
                timerMB.stop();

                results << timerLD.sInterval() << " ";
                results << timerMD.sInterval() << " ";
                results << timerLB.sInterval() << " ";
                results << timerMB.sInterval() << " \n";
            }
        }
    }
    results.close();

    return 0;
}
