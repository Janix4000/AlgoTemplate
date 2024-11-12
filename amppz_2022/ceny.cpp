#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

// C++
#include <algorithm>
#include <array>
#include <bitset>
#include <complex>
#include <deque>
#include <forward_list>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;

using vi = vector<int>;
using vvi = vector<vi>;

struct Edge {
    int from, to, cap, flow;
};

constexpr int INF = int(1e9);

vvi graph, costs, caps;

vi par, dist;

void dij(int from) {
    int n = graph.size();
    par.assign(n, -1);
    dist.assign(n, INF);

    dist[from] = 0;
    vis[from] = true;

    vi vis(n, false);

    priority_queue<int, vi, greater<int>> q;

    q.push(from);

    while (!q.empty()) {
        int v = q.top();
        q.pop();
        vis[v] = true;
        for (int e : graph[v]) {
            if (vis[e]) continue;
        }
    }
}

int32_t main() {
    int n;

    graph = vi(n);
}