#include <bits/stdc++.h>
#include "graph.hpp"

int dfs_rec(int v, Graph &graph)
{
    auto &node = graph[v];
    node.visited = true;
    for (int e : node)
    {
        auto &nbor = graph[e];
        if (nbor.visited)
            continue;
        nbor.visited = true;
        // pre

        int child_res = dfs_rec(e, graph);
        if (child_res)
        {
            return true;
        }

        //post
    }
    return false;
};

bool dfs(Graph &graph, int v = 0)
{
    for (auto &node : graph)
    {
        node.visited = false;
    }
    for (int v = 0; v < graph.size(); ++v)
    {
        if (!graph[v].visited)
        {
            dfs_rec(v, graph);
        }
    }
    return false;
}