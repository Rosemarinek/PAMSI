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
    int sourceIndexLNeg;
    int sourceIndexMNeg;

    std::vector<std::string> graphFile = {
        "../data/graph/graphV10D0.25.txt",  "../data/graph/graphV10D0.5.txt",   "../data/graph/graphV10D0.75.txt",
        "../data/graph/graphV10D1.txt",     "../data/graph/graphV50D0.25.txt",  "../data/graph/graphV50D0.5.txt",
        "../data/graph/graphV50D0.75.txt",  "../data/graph/graphV50D1.txt",     "../data/graph/graphV100D0.25.txt",
        "../data/graph/graphV100D0.5.txt",  "../data/graph/graphV100D0.75.txt", "../data/graph/graphV100D1.txt",
        "../data/graph/graphV150D0.25.txt", "../data/graph/graphV150D0.5.txt",  "../data/graph/graphV150D0.75.txt",
        "../data/graph/graphV150D1.txt",    "../data/graph/graphV200D0.25.txt", "../data/graph/graphV200D0.5.txt",
        "../data/graph/graphV200D0.75.txt", "../data/graph/graphV200D1.txt"};

    std::vector<std::string> graphFileNegative = {
        "../data/graph/graphV10D0.25Negative.txt",  "../data/graph/graphV10D0.5Negative.txt",
        "../data/graph/graphV10D0.75Negative.txt",  "../data/graph/graphV10D1Negative.txt",
        "../data/graph/graphV50D0.25Negative.txt",  "../data/graph/graphV50D0.5Negative.txt",
        "../data/graph/graphV50D0.75Negative.txt",  "../data/graph/graphV50D1Negative.txt",
        "../data/graph/graphV100D0.25Negative.txt", "../data/graph/graphV100D0.5Negative.txt",
        "../data/graph/graphV100D0.75Negative.txt", "../data/graph/graphV100D1Negative.txt",
        "../data/graph/graphV150D0.25Negative.txt", "../data/graph/graphV150D0.5Negative.txt",
        "../data/graph/graphV150D0.75Negative.txt", "../data/graph/graphV150D1Negative.txt",
        "../data/graph/graphV200D0.25Negative.txt", "../data/graph/graphV200D0.5Negative.txt",
        "../data/graph/graphV200D0.75Negative.txt", "../data/graph/graphV200D1Negative.txt"};

    std::vector<std::string> VD = {"10 0.25 ",  "10 0.5 ",   "10 0.75 ",  "10 1 ",     "50 0.25 ",
                                   "50 0.5 ",   "50 0.75 ",  "50 1 ",     "100 0.25 ", "100 0.5 ",
                                   "100 0.75 ", "100 1 ",    "150 0.25 ", "150 0.5 ",  "150 0.75 ",
                                   "100 1 ",    "200 0.25 ", "200 0.5 ",  "200 0.75 ", "200 1 "};

    if(results.good())
    {
        results << "Vertices "
                << "Density "
                << "Dijkstra-List "
                << "Dijkstra-Matrix "
                << "BellmanFord-List "
                << "BellmanFord-Matrix "
                << "BellmanFord-List-Negative "
                << "BellmanFord-Matrix-Negative \n";
    }

    for(int i = 0; i < graphFile.size(); ++i)
    {
        inputFile.open(graphFile[i]);
        auto graphL = AdjacencyListGraph::createGraph(inputFile);
        inputFile >> sourceIndexL;
        inputFile.close();

        inputFile.open(graphFile[i]);
        auto graphM = AdjacencyMatrixGraph::createGraph(inputFile);
        inputFile >> sourceIndexM;
        inputFile.close();

        inputFile.open(graphFileNegative[i]);
        auto graphLNeg = AdjacencyListGraph::createGraph(inputFile);
        inputFile >> sourceIndexLNeg;
        inputFile.close();

        inputFile.open(graphFileNegative[i]);
        auto graphMNeg = AdjacencyMatrixGraph::createGraph(inputFile);
        inputFile >> sourceIndexMNeg;
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

                timerLBNeg.start();
                bellmanFord(*graphLNeg, sourceIndexL, result);
                timerLBNeg.stop();

                timerMBNeg.start();
                bellmanFord(*graphMNeg, sourceIndexM, result);
                timerMBNeg.stop();

                results << timerLD.msInterval() << " ";
                results << timerMD.msInterval() << " ";
                results << timerLB.msInterval() << " ";
                results << timerMB.msInterval() << " ";
                results << timerLBNeg.msInterval() << " ";
                results << timerMBNeg.msInterval() <<" \n";
            }
        }
    }
    results.close();

    return 0;
}
