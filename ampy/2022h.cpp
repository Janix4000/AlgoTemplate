#include <bits/stdc++.h>

#include <vector>

template <typename... Ts>
void __print(Ts&&... ts) {}
#ifdef DEBUG
#include "print.hpp"
#endif  // DEBUG

using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) ((int)(x).size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

using vs = vector<string>;
using vvs = vector<vs>;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vpi = vector<pi>;

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

struct Edge {
    int u, c;
};
using Node = vector<Edge>;
using Graph = vector<Node>;

void solution() {
    int m, n;
    Graph g(n);
    map<pi, int> edges;
    for (int i = 0; i < m; i++) {
        int v, u, c;
        cin >> v >> u >> c;
        v--;
        u--;
        g[v].emplace_back(u, c);
        g[u].emplace_back(v, c);
        edges[{v, u}] = c;
        edges[{u, v}] = c;
    }
    using El = array<int, 3>;  // dist, to, from
    int prev_best;
    vvi dag(n);

    {
        vi bd(n, -1);
        priority_queue<El, vector<El>, greater<>> pq;
        pq.emplace(0, 0, -1);
        vi vis(n, 0);
        while (!pq.empty()) {
            auto [d, v, u] = pq.top();
            pq.pop();
            if (bd[v] == -1 || bd[v] == d) {
                dag[v].push_back(u);
            }
            if (bd[v] != -1) continue;
            bd[v] = d;
            for (auto& edge : g[v]) {
                if (bd[edge.u] != -1) continue;
                pq.emplace(d + edge.c, edge.u, v);
            }
        }
        prev_best = bd[n - 1];
    }

    // 4 5

    set<pi> keep;
    int start = n - 1, end = 0;
    while (prev_best > 0) {
        vi bd(n, 0);
        vvi new_dag(n);
        vi vis(n, 0);

        queue<El> q;
        q.emplace(0, start, -1);
        while (!q.empty()) {
            auto [d, v, u] = q.front();
            q.pop();
            if (bd[v] < d) {
                new_dag[v].clear();
                bd[v] = d;
            }
            if (bd[v] == d) {
                new_dag[v].push_back(u);
            }
            vis[v]++;
            if (vis[v] < dag[v].size()) continue;
            for (auto& edge : g[v]) {
                q.emplace(max(d, edge.c), edge.u, v);
            }
        }

        prev_best = bd[end];
        swap(dag, new_dag);
        swap(start, end);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;
    cin >> qs;
    cout << setprecision(12) << fixed;

    while (qs--) {
        solution();
    }
    return 0;
}