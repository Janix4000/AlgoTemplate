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
#define loop(i, b) for (int i = 0; i < (b); ++i)
#define loopr(i, b) for (int i = (b)-1; i >= 0; --i)
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

class Solution {
   public:
    using vi = vector<int>;
#define all(x) (x).begin(), (x).end()
    struct Node : vi {
        int left;
        int dist = 0;
        bool operator<(Node& rhs) const { return dist < rhs.dist; }
    };
    struct Graph : vector<Node> {};

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        Graph g;
        g.resize(n);
        for (auto& edge : edges) {
            int e = edge[0];
            int v = edge[1];

            g[e].push_back(v);
            g[v].push_back(e);
        }
        for (auto& node : g) {
            node.left = node.size() - 1;
        }
        queue<int> q;
        vi visited(n, false);
        for (int v = 0; v < n; ++v) {
            if (!g[v].left) {
                q.push(v);
                visited[v] = true;
            }
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            auto& node = g[v];
            for (int e : node) {
                if (visited[e]) {
                    continue;
                }
                auto& nbor = g[e];
                nbor.left--;
                nbor.dist = node.dist + 1;
                if (!nbor.left) {
                    visited[e] = true;
                    q.push(e);
                }
            }
        }
        int dist = max_element(all(g))->dist;
        vi res;
        for (int v = 0; v < n; ++v) {
            auto& node = g[v];
            res.push_back(node.dist);
            if (node.dist == dist) {
                // res.push_back(v);
            }
        }
        return res;
    }
#undef all
};
void solution() {
    int n;
    cin >> n;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int qs = 1;
    // // cin >> qs;

    // while (qs--) {
    //     solution();
    // }

    Solution solution;
    int n = 7;
    vvi edges = {{0, 1}, {1, 2}, {1, 3}, {2, 4}, {3, 5}, {4, 6}};
    __print(solution.findMinHeightTrees(n, edges));
    return 0;
}