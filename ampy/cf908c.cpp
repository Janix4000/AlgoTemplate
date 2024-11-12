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

int dfs(map<int, vi>& g, vi& vis, vi& vis_dfs, vi& cs, int v, int shift, int n,
        int count, int k) {
    if (vis_dfs[v]) return 1;
    if (vis[v]) return 0;
    if (++count > k) return 1;
    vis[v] = 1;
    vis_dfs[v] = 1;
    shift = (n + shift - cs[v]) % n;
    for (auto&& u : g[shift]) {
        if (dfs(g, vis, vis_dfs, cs, u, shift, n, count, k)) return 1;
    }
    vis_dfs[v] = 0;
    return 0;
}

void solution() {
    int n, k;
    cin >> n >> k;
    vi bs(n + 1);
    for (size_t i = 1; i <= n; i++) {
        cin >> bs[i];
    }

    // vi cs(n + 1, -1);
    // map<int, vi> g;
    // for (size_t i = 1; i <= n; i++) {
    //     if (bs[i] > n)
    //         continue;
    //     else {
    //         int r = n - i;
    //         cs[i] = r;
    //         g[r].push_back(i);
    //     }
    // }

    // vi visited(n + 1, 0);
    // vi visited_dfs(n + 1, 0);

    // for (size_t i = 1; i <= n; i++) {
    //     if (cs[i] > 0) continue;
    //     if (dfs(g, visited, visited_dfs, cs, i, 0, n, 0, k)) {
    //         cout << "YES" << endl;
    //         return;
    //     }
    // }
    int pos = n;
    for (size_t i = 0; i < min(k, n); i++) {
        if (bs[pos] > n) {
            cout << "NO" << endl;
            return;
        }
        pos = (pos + n - bs[pos]) % n;
    }

    cout << "YES" << endl;
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