#include "graphs/shortest_path_algorithms.hpp"
#include <algorithm>

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

void reversePath(ShortestPathResult& result, const int prev[], const int& Vertex)
{
    for(int i = 0; i < Vertex; i++)
    {
        int tmp = prev[i];
        while(tmp != -1)
        {
            result[i].path.push_back(tmp);
            tmp = prev[tmp];
        }
        std::reverse(result[i].path.begin(), result[i].path.end());
        result[i].path.push_back(i);
    }
}

void dijkstra(Graph& graph, int sourceIndex, ShortestPathResult& result)
{
    int prev[graph.size()];
    bool visited[graph.size()];

    for(int i = 0; i < graph.size(); i++)
    {
        visited[i] = false;
        result[i].cost = INT_MAX;
        prev[i] = -1;
    }

    result[sourceIndex].cost = 0;

    for(int i = 0; i < graph.size() - 1; i++)
    {
        int pIndex = getMin(result, visited, graph.size());
        visited[pIndex] = true;

        for(int cIndex = 0; cIndex < graph.size(); cIndex++)
        {
            if(!visited[cIndex] && (result[pIndex].cost + graph(pIndex, cIndex)) < result[cIndex].cost &&
               graph(pIndex, cIndex) != INT_MAX)
            {
                prev[cIndex] = pIndex;
                result[cIndex].cost = result[pIndex].cost + graph(pIndex, cIndex);
            }
        }
    }
    reversePath(result, prev, graph.size());
}

bool bellmanFord(Graph& graph, int sourceIndex, ShortestPathResult& result)
{
    auto edge = graph.Edge();
    int prev[graph.size()];

    for(int i = 0; i < graph.size(); i++)
    {
        result[i].cost = INT_MAX;
        prev[i] = -1;
    }
    result[sourceIndex].cost = 0;

    for(int i = 0; i < graph.size() - 1; i++)
    {
        for(auto& j : edge)
        {
            auto pIndex = j[0];
            auto cIndex = j[1];
            auto cost = j[2];

            if(result[pIndex].cost != INT_MAX && result[pIndex].cost + cost < result[cIndex].cost)
            {
                result[cIndex].cost = result[pIndex].cost + cost;
                prev[cIndex] = pIndex;
            }
        }
    }

    for(auto& j : edge)
    {
        auto pIndex = j[0];
        auto cIndex = j[1];
        auto cost = j[2];

        if(result[pIndex].cost != INT_MAX && result[pIndex].cost + cost < result[cIndex].cost)
        {
            return false;
        }
    }
    reversePath(result, prev, graph.size());
    return true;
}