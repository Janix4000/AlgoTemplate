#include <bits/stdc++.h>

template <typename... Ts>
void __print(Ts &&...ts) {}
#ifdef DEBUG
#include "print.hpp"
#endif  // DEBUG

using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) ((int)(x).size())

using ll = long long;
template <typename T>
using vec = vector<T>;


using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;

using pi = pair<int, int>;
using pl = pair<ll, ll>;

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

bool is_good(ll v) {
    if(v == 0) return false;
    while(v > 0) {
        if(v%10 != 4 && v%10 != 7) return false;
        v /= 10;
    }
    return true;
}


using Node = vector<int>;
using Graph = vector<Node>;

int dfs(int v, Graph& g, vi& visited) {
    if(visited[v]) return 0;
    visited[v] = true;
    int sol = 1;
    for(int e : g[v]) {
        if(visited[e]) continue;
        sol += dfs(e, g, visited);
    }
    return sol;
}

void solution() {
    int n;
    cin >> n;

    Graph g(n);
    for (int i = 0; i < n -1; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--;
        v--;
        if(is_good(w)) continue;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vi visited(n, 0);

    int sol = 0;
    for (int v = 0; v < n; v++)
    {
        int k = dfs(v, g, visited);
        sol += k * ((n - k) * (n - k - 1));
    }
    
    cout << sol;
    
    
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;
    // cin >> qs;

    while (qs--) {
        solution();
    }

    return 0;
}