#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, b) FOR(i, 0, b)
#define all(x) (x).begin(), (x).end()

template <typename T>
using vec = vector<T>;

using ll = long long;
constexpr ll INF = 1000000000LL;

using vi = vec<ll>;
using vvi = vec<vi>;
using vvvi = vec<vvi>;

using Graph = vvi;

struct dfs
{
    Graph &graph;
    vi visited;
    vi C0, C1;
    vi type;
    int left, right;
    vi path;
    enum
    {
        A,
        B,
        PATH
    };
    dfs(Graph &graph) : graph(graph), visited(graph.size(), false), type(graph.size(), A)
    {
        int n = (int)graph.size();
        visited[0] = true;
        left = n;
        right = 0;
        rec(0);
        F0R(i, n)
        {
            if (type[i] == A)
            {
                C0.push_back(i + 1);
            }
            else if (type[i] == B)
            {
                C1.push_back(i + 1);
            }
        }
    }

    bool rec(int v)
    {
        path.push_back(v + 1);
        type[v] = PATH;
        left--;
        if (left == right)
        {
            return true;
        }
        auto &edges = graph[v];
        for (int e : edges)
        {
            if (visited[e])
            {
                continue;
            }
            visited[e] = true;
            if (rec(e))
            {
                return true;
            }
        }
        type[v] = B;
        path.pop_back();
        right++;
        if (left == right)
        {
            return true;
        }
        return false;
    }
};

void solution()
{
    int N, E;
    cin >> N >> E;
    Graph graph(N);
    F0R(i, E)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    auto res = dfs(graph);
    cout << res.path.size() << ' ' << res.C0.size() << endl;
    for (int v : res.path)
    {
        cout << v << ' ';
    }
    cout << endl;
    for (int v : res.C0)
    {
        cout << v << ' ';
    }
    cout << endl;
    for (int v : res.C1)
    {
        cout << v << ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int qs = 1;
    // cin >> qs;
    while (qs--)
    {
        solution();
    }
}