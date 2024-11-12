#include <bits/stdc++.h>

#include <vector>

template <typename... Ts>
void __print(Ts &&...ts) {}
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


int dfs(vvi& g, int v, vi& vis, vi& ds) {
    if(vis[v]) return 0;
    vis[v] = 1;
    ds[v] = 1;
    for(int e : g[v]) {
        ds[v] += dfs(g, e, vis, ds);
    }
    return ds[v];
}

void solution() {
    int n; cin >> n;
    vvi g(n, vi());
    for (size_t i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vi ds(n, 0);
    {
        vi vis(n, 0);
        dfs(g, 0, vis, ds);
    }

    vi vis(n, 0);
    priority_queue<pi, vpi, greater<pi>> pq;
    for (size_t v = 1; v < n; v++)
    {
        if(ds[v] == 1) {
            pq.emplace(1, v);
            vis[v] = 1;
        }
    }
    int max_d = 1;
    set<int> rr;
    while(!pq.empty()) {
        auto [d, v] = pq.top(); pq.pop();
        if(d == max_d || max_d == -1) {
            rr.insert(d);
        } 
        for(int e : g[v]) {
            if(vis[e]) continue;
            pq.emplace(ds[e], e);
            max_d = max(max_d, ds[e]);
            vis[e] = 1;
        }
    }
    
    cout << rr.size() << endl;
    for(int d : rr) {
        cout << d << ' ';
    }
    
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;
    cin >> qs;

    while (qs--) {
        solution();
    }
    return 0;
}