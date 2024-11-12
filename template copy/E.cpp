#include <bits/stdc++.h>

#include <vector>

template <typename... Ts>
void __print(Ts &&...ts) {}
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

class Solution {

};

struct Node {
    vi ns;
    map<int, int> m;
    int color;

};


void solution() {
    int n;
    cin >> n;

    ll res = 0;
    vec<map<int, int>> m(n + 1);
    vi colors(n);
    vvi graph(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> colors[i];
    }
    for (size_t i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vi parents(n, -2);
    {
        queue<pi> qs; 
        qs.emplace(0, -1);
        while(!qs.empty()) {
            auto [v, v_from] = qs.front(); qs.pop();
            parents[v] = v_from;
            for(auto e : graph[v]) {
                if(parents[e] != -2) continue;
                qs.emplace(e, v); 
            }
        }
    }

    vi left(n, 0);
    left[0] = graph[0].size();
    for (size_t i = 1; i < n; i++)
    {
        left[i] = graph[i].size() - 1;
    }

    queue<pi> qs;
    for (size_t v = 0; v < n; v++)
    {
        if(left[v] == 0) {
            qs.emplace(v, n);
        }
    }
    while (!qs.empty())
    {
        auto [v, v_from] = qs.front(); qs.pop();

        int v_color = colors[v];

        if(m[v].size() < m[v_from].size()) {
            swap(m[v], m[v_from]);   
        }
        for(auto [color, count] : m[v_from]) {
            if(color != v_color && m[v].count(color)){

                res += m[v][color] * 1ll * count;
            }
            m[v][color] += count;
        }

        if(--left[v] > 0) {
            continue;
        }
        res += m[v][v_color];
        m[v][v_color] = 1;

        if(parents[v] == -1) continue;
        qs.emplace(parents[v], v);
    }
    
    cout << res << endl;
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