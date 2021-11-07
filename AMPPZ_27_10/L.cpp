#include <bits/stdc++.h>

template <typename... Ts>
void __print(Ts &&...ts) {}
#ifdef DEBUG
#include "print.hpp"
#endif // DEBUG

using namespace std;

template <typename T>
using vec = vector<T>;

using vi = vec<int>;

#define all(x) (x).begin(), (x).end()

///////////////////////////////////////////////////////////////////////////////////////////////
#define MAX_SPICE 100
int INF = int(1e5) + 10;

struct Node
{
    vi dists;

    Node() : dists(MAX_SPICE, INF)
    {
    }

    vec<int> nbors;

    bool visited = false;
};

using Graph = vec<Node>;

struct bfs
{
    bfs(Graph &graph, vi &ss, int spice)
    {
        queue<array<int, 2>> q;
        for (int s : ss)
        {
            q.push({s, 0});
            graph[s].visited = true;
        }

        while (!q.empty())
        {
            auto [e, d] = q.front();
            q.pop();
            auto &E = graph[e];

            for (int nbor : E.nbors)
            {
                auto &V = graph[nbor];
                if (V.visited)
                {
                    continue;
                }
                V.visited = true;

                auto &curr_dist = V.dists[spice];

                if (d + 1 < curr_dist)
                {
                    curr_dist = d + 1;

                    q.push({nbor, d + 1});
                }
            }
        }

        for (auto &node : graph)
        {
            node.visited = false;
        }
    }
};

Graph &graph;
vi visited;
struct Conn
{
    int from, to;
    int flow;
};
vec<Conn> path;
int t;
bool found = false;
dfs(Graph &graph, int s, int t)
{
    fill(all(visited), false);
    visited[s] = true;
    found = rec_dfs(s, t);
}

bool rec_dfs(int v, int t)
{
    auto &V = graph[v];
    for (auto &E : V.nbors)
    {
        int nbor = E.dest;
        int flow = E.flow;
        if (visited[nbor] || flow <= 0)
        {
            continue;
        }
        visited[nbor] = true;
        if (nbor == t)
        {
            return true;
        }
        path.push_back({v, nbor, flow});
        if (rec_dfs(nbor, t))
        {
            return true;
        }
        path.pop_back();
    }
    return false;
}

struct dfs
{
    Graph &graph;
    vi visited;
    struct Conn
    {
        int from, to;
        int flow;
    };
    vec<Conn> path;
    int t;
    bool found = false;
    dfs(Graph &graph, int s, int t) : graph(graph), visited(graph.size(), 0), t(t)
    {
        visited[s] = true;
        found = rec_dfs(s);
    }

    bool rec_dfs(int v)
    {
        auto &V = graph[v];
        for (auto &E : V.nbors)
        {
            int nbor = E.dest;
            int flow = E.flow;
            if (visited[nbor] || flow <= 0)
            {
                continue;
            }
            visited[nbor] = true;
            if (nbor == t)
            {
                return true;
            }
            path.push_back({v, nbor, flow});
            if (rec_dfs(nbor))
            {
                return true;
            }
            path.pop_back();
        }
        return false;
    }
};

void propagate_distance(Graph &graph, int last_spice, int spice)
{
    for (auto &V : graph)
    {
        auto &last_dist = V.dists[last_spice];
        auto &curr_dist = V.dists[spice];
        if (last_dist < curr_dist)
        {
            curr_dist = last_dist;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////

void solution()
{
    int N, M, Q;
    cin >> N >> M >> Q;
    vi spices(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> spices[i];
        spices[i]--;
    }
    Graph graph(N);
    for (int i = 0; i < N; ++i)
    {
        graph[i].dists[spices[i]] = 0;
    }
    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].nbors.push_back(v);
        graph[v].nbors.push_back(u);
    }

    auto res = dfs(graph, 0, 1);

    vi vs(N);
    iota(all(vs), 0);
    sort(all(vs), [&](int a, int b)
         { return spices[a] < spices[b]; });

    int last_spice = 0;

    for (int i = 0; i < N; ++i)
    {
        int spice = spices[vs[i]];
        vi ss;
        for (; i < N; ++i)
        {
            int v = vs[i];
            int next_spice = spices[v];
            if (next_spice == spice)
            {
                ss.push_back(v);
            }
            else
            {
                --i;
                break;
            }
        }
        for (int k = last_spice + 1; k <= spice; ++k) // fill gap
        {
            propagate_distance(graph, last_spice, k);
        }
        last_spice = spice;
        bfs(graph, ss, spice);
    }

    for (int k = last_spice + 1; k < MAX_SPICE; ++k)
    {
        propagate_distance(graph, last_spice, k);
    }

    for (int i = 0; i < Q; ++i)
    {
        int p, a;
        cin >> p >> a;
        p--;
        a--;
        auto d = graph[p].dists[a];
        d = d == INF ? -1 : d;
        cout << d << '\n';
    }

    auto dfs_res = dfs(graph, 0, 1);
    if (dfs_res.found)
    {
        int flow = INF;
        for (auto &[from, to, f] : dfs_res.path)
        {
            flow = min(flow, f);
        }
        for (auto &[from, to, f] : dfs_res.path)
        {
            graph[from][to] -= flow;
            graph[to][flow] += flow;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;
    // cin >> qs;

    while (qs--)
    {
        solution();
    }
    return 0;
}