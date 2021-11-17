#include <bits/stdc++.h>

template <typename... Ts>
void __print(Ts &&...ts) {}
#ifdef DEBUG
#include "print.hpp"
#endif  // DEBUG

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

template <class T>
using pq_max = priority_queue<T>;
template <class T>
using pq_min = priority_queue<T, vector<T>, greater<T>>;

#define FOR(i, a, b) for (int i = a; i < (b); ++i)
#define F0R(i, a) for (int i = 0; i < (a); ++i)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; --i)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; --i)
#define trav(a, x) for (auto &a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

#define IN(n) \
    int n;    \
    cin >> n;

#define all(x) x.begin(), x.end()

template <class T>
bool ckmin(T &a, const T &b) {
    return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
    return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
T max(T a, T b, T c) {
    return max(max(a, b), c);
}
template <typename T, typename... Ts>
T max(T a, Ts... as) {
    return max(a, max(as...));
}
template <typename T>
T min(T a, T b, T c) {
    return min(min(a, b), c);
}
template <typename T, typename... Ts>
T min(T a, Ts... as) {
    return min(a, min(as...));
}
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

using ll = long long;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

template <typename T>
using vec = vector<T>;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define all(x) x.begin(), x.end()

struct Node : public vec<int> {
    int nodes_left = 0;
    ll value = 1;
    int time = 0;
};

class Solution {
   public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time) {
        queue<int> to_procide;
        vector<Node> nodes(n);
        for (auto relation : relations) {
            int v = relation[0] - 1, e = relation[1] - 1;
            nodes[v].push_back(e);
            nodes[e].nodes_left++;
        }
        for (int v = 0; v < nodes.size(); v++) {
            nodes[v].time = time[v];
            if (nodes[v].nodes_left == 0) {
                to_procide.push(v);
            }
        }
        while (!to_procide.empty()) {
            int v = to_procide.front();
            to_procide.pop();
            auto &node = nodes[v];
            for (int e : node) {
                auto &nbor = nodes[e];
                nbor.time = max(nbor.time, node.time + time[e]);
                nbor.nodes_left--;
                if (nbor.nodes_left == 0) {
                    to_procide.push({
                        e,
                    });
                }
            }
        }

        int res = 0;
        for (auto &node : nodes) {
            res = max(res, node.time);
        }
        return res;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    vi parents = {-1, 2, 0, 2, 0};
    __print(solution.countHighestScoreNodes(parents));

    return 0;
}