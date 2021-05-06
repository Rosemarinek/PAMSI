#include "graphs/shortest_path_algorithms.hpp"
#include <algorithm>
#include <iostream>

int getMin(ShortestPathResult& result, const bool visited[], int Vertex)
{
    int key = 0;
    int min = INT_MAX;

    for(int i = 0; i < Vertex; i++)
    {
        if(!visited[i] && result[i].cost < min)
        {
            min = result[i].cost;
            key = i;
        }
    }
    return key;
}

void reversePath(ShortestPathResult& result, int par[], const int& Vertex){
    for(int i =0 ;i < Vertex ;i++){
        int tmp = par[i] ;
        while(tmp!=-1)
        {
            result[i].path.push_back(tmp);
            tmp = par[tmp] ;
        }
        std::reverse(result[i].path.begin(), result[i].path.end());
        result[i].path.push_back(i);
    }
}

void dijkstra(Graph& graph, int sourceIndex, ShortestPathResult& result)
{
    // TODO: implement
    int par[graph.size()];
    bool visited[graph.size()];

    for(int i = 0; i < graph.size(); i++)
    {
        visited[i] = false;
    }

    for(int i = 0; i < graph.size(); i++)
    {
        result[i].cost = INT_MAX;
    }

    result[sourceIndex].cost = 0;
    par[sourceIndex]=-1;

    for(int i = 0; i < graph.size() - 1; i++)
    {
        int pIndex = getMin(result, visited, graph.size());
        visited[pIndex] = true;

        for(int cIndex = 0; cIndex < graph.size(); cIndex++)
        {
            if(!visited[cIndex] && (result[pIndex].cost + graph(pIndex, cIndex)) < result[cIndex].cost &&
               graph(pIndex, cIndex) != INT_MAX)
            {
                par[cIndex]=pIndex;
                result[cIndex].cost = result[pIndex].cost + graph(pIndex, cIndex);
            }
        }
    }
    reversePath(result,par,graph.size());
}

bool bellmanFord(Graph& graph, int sourceIndex, ShortestPathResult& result)
{
    // TODO: implement
    return true;
}
