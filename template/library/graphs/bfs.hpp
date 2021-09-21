#include <bits/stdc++.h>
#include "graph.hpp"

void bfs(Graph &graph, int start)
{
    for (auto &node : graph)
    {
        node.visited = false;
    }
    queue<int> q;

    q.push(start);
    graph[start].visited = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        auto &node = graph[v];

        //process

        for (int e : node)
        {
            auto &nbor = graph[e];
            if (nbor.visited)
                continue;
            q.push(e);
            nbor.visited = true;
        }
    }
}