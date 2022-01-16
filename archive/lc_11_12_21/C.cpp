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

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

struct dfs {
    vvi& graph;
    vi visited;
    int sol = 0;
    dfs(vvi& graph, int v) : graph(graph) {
        int n = sz(graph);
        visited = vi(n, 0);
        visited[v] = true;
        sol = dfs_rec(v);
    }

    int dfs_rec(int v) {
        int sol = 1;
        for (int e : graph[v]) {
            if (visited[e]) {
                continue;
            }
            visited[e] = true;
            sol += dfs_rec(e);
        }
        return sol;
    }
};

class Solution {
   public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = sz(bombs);
        vvi graph(n);
        loop(i, n) {
            auto& bomb = bombs[i];
            auto& node = graph[i];
            loop(j, n) {
                if (j == i) {
                    continue;
                }
                auto& nbor = bombs[j];
                if (pow(nbor[0] - bomb[0], 2) + pow(nbor[1] - bomb[1], 2) <=
                    pow(bomb[2], 2)) {
                    node.push_back(j);
                }
            }
        }
        int best = 0;
        loop(v, n) { best = max(best, dfs(graph, v).sol); }
        return best;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    vvi bombs = {{1, 2, 3}, {2, 3, 1}, {3, 4, 2}, {4, 5, 3}, {5, 6, 4}};
    __print(solution.maximumDetonation(bombs));
    return 0;
}