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



void solution() {
    int n, p;
    cin >> n >> p;

    vi isp(n, 0);
    for (size_t i = 0; i < p; i++)
    {
        int k;
        cin >> k;
        isp[k-1] = 1;
    }
    vector<map<int, int>> g_maxs(n);
    vi sums(n, 0);
    vpi edges(n - 1);
    vi cs(n - 1);

    for (size_t i = 0; i < n - 1; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        sums[u] += c;
        sums[v] += c;
        g_maxs[u][c]++;
        g_maxs[v][c]++;
        edges[i] = {u, v};
        cs[i] = c;
    }

    int k;
    cin >> k;
    vi rs(k);
    for (size_t i = 0; i < k; i++)
    {
        cin >> rs[i];
        rs[i]--;
    }
    sort(all(rs), [&cs](int a, int b){return cs[a] > cs[b]; });
    

    bool rr = true;

    for (int v = 0; v < n; v++)
    {
        if(isp[v]) continue;
        int max_c = g_maxs[v].rbegin()->first;
        if(sums[v] - max_c < max_c || sums[v] % 2 != 0) {
            rr = false;
            break;
        }
    }

    for(int e : rs) {
        auto [u, v] = edges[e];
        int c = cs[e];
        for(int h : {u, v}) {
            if(--g_maxs[h][c] == 0) {
                g_maxs[h].erase(c);
            }
            sums[h] -= c;

            if(isp[h]) continue;
            int max_c = g_maxs[h].rbegin()->first;
            if(sums[h] - max_c < max_c || sums[h] % 2 != 0) {
                rr = false;
                break;
            }
        }
        if(!rr) break;
    }

    if(!rr) {
        cout << "NIE" << endl;
        return;
    }

    cout << "TAK" << endl;

    for (auto &&e : rs)
    {
        cout << e + 1 << ' ';
    }
    cout << endl;
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