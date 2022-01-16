#include <bits/stdc++.h>

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

class Solution {};

struct Edge {
    int to_row;
    int to_col;
    ll cost;
};
using Node = vec<Edge>;
using Graph = vec<vec<Node>>;
void solution() {
    int n, m, k;
    cin >> n >> m >> k;

    constexpr ll INF = 1ll << 60;

    vl xs(n);
    loop(row, n) { cin >> xs[row]; }

    vec<vec<vec<arr<ll, 3>>>> ladders(n, vec<vec<arr<ll, 3>>>(m));
    loop(i, k) {
        int a, b, c, d, h;
        cin >> a >> b >> c >> d >> h;
        ladders[c - 1][d - 1].push_back({a - 1, b - 1, h});
    }

    vvl dp(n, vl(m, INF));
    dp[0][0] = 0;

    loop(row, n) {
        loop(col, m) {
            for (auto [y, x, h] : ladders[row][col]) {
                dp[row][col] = min(dp[row][col], dp[y][x] - h);
            }
        }
        ll x = xs[row];
        ll best = dp[row][0];
        loop(col, 1, m) {
            best += x;
            dp[row][col] = min((ll)dp[row][col], best);
            best = min(best, (ll)dp[row][col]);
        }
        best = dp[row][m - 1];
        loopr(col, m - 1) {
            best += x;
            dp[row][col] = min((ll)dp[row][col], best);
            best = min(best, (ll)dp[row][col]);
        }
    }

    if (dp[n - 1][m - 1] == INF) {
        cout << "NO ESCAPE\n";
    } else {
        cout << dp[n - 1][m - 1] << '\n';
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

    // Solution solution;
    return 0;
}