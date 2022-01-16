#include <bits/stdc++.h>

template <typename... Ts>
void __print(Ts&&... ts) {}
#ifdef DEBUG
#include "print.hpp"
#endif  // DEBUG

using namespace std;

template <class T>
using pq_max = priority_queue<T>;
template <class T>
using pq_min = priority_queue<T, vector<T>, greater<T>>;

#define FOR(i, a, b) for (int i = a; i < (b); ++i)
#define F0R(i, a) for (int i = 0; i < (a); ++i)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; --i)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; --i)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define all(x) x.begin(), x.end()

#define GET_FOR(_1, _2, _3, NAME, ...) NAME
#define loop(...) GET_FOR(__VA_ARGS__, FOR, F0R)(__VA_ARGS__)

#define GET_FORd(_1, _2, _3, NAME, ...) NAME
#define loopr(...) GET_FOR(__VA_ARGS__, FORd, F0Rd)(__VA_ARGS__)

#define sz(x) ((int)(x).size())

using ll = long long;
template <typename T>
using vec = vector<T>;
template <typename T, size_t N>
using arr = array<T, N>;

using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

using pi = pair<int, int>;
using pl = pair<ll, ll>;

template <typename R, typename... Args>
using fn = function<R(Args...)> ;

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

class Solution {};

using Node = vec<arr<int, 2>>;
using Graph = vec<Node>;

void solution() {
    int n;
    Graph g(n, vec<arr<int, 2>>());
    cin >> n;
    loop(i, n) {
        int v, e;
        cin >> v >> e;
        e--, v--;
        g[e].push_back({v, i});
        g[v].push_back({e, i});
    }
    for (auto& node : g) {
        if (node.size() > 2) {
            cout << -1 << '\n';
            return;
        }
    }

    int v = min_element(all(g),
                        [](auto& l, auto& r) { return l.size() < r.size(); }) -
            g.begin();
    vi as(n - 1);
    {
        vi vis(n, 0);
        int k = 0;
        function<void(int)> dfs = [&](int v) {
            vis[v] = true;
            for (auto [e, i] : g[v]) {
                if (vis[e]) continue;
                if (k++ % 2) {
                    as[i] = 2;
                } else {
                    as[i] = 5;
                }
                vis[e] = 1;
                dfs(e);
            }
        };
        dfs(v);
    }
    loop(i, n) { cout << as[i] << ' '; }

    cout << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;
    cin >> qs;

    while (qs--) {
        solution();
    }

    // Solution solution;
    return 0;
}