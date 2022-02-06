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

void solution() {
    int n, l, k;
    cin >> n >> l >> k;
    vi dists(n + 1);
    loop(i, n) { cin >> dists[i]; }
    dists[n] = l;
    vi costs(n + 1);
    loop(i, n) { cin >> costs[i + 1]; }
    constexpr int INF = 1 << 30;
    vvi dp(n + 1, vi(k + 1, INF));
    vvi prev(n + 1, vi(k + 1, 0));
    dp[0][0] = 0;
    prev[0][0] = 0;
    loop(col, 1, n + 1) {
        dp[col][0] =
            dp[col - 1][0] + (dists[col] - dists[col - 1]) * costs[col];
        prev[col][0] = col - 1;
    }

    for (int col = 1; col < n; ++col) {
    }

    loopr(col, 1, n) {}
    loop(col, n) {}

    loop(col, 1, n) {
        loop(row, 1, min(col + 1, k + 1)) {
            int keep =
                dp[col - 1][row] + (dists[col] - dists[prev[col - 1][row]]) *
                                       costs[prev[col - 1][row]];
            int remove =
                dp[col - 1][row - 1] +
                (dists[col] - dists[prev[col - 1][row - 1]]) * costs[col];
            if (keep < remove) {
                dp[col][row] = keep;
                prev[col][row] = prev[col - 1][row];
            } else {
                dp[col][row] = remove;
                prev[col][row] = col;
            }
        }
    }
    cout << dp[n][k];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;
    // cin >> qs;

    while (qs--) {
        solution();
    }

    // Solution solution;
    cout.flush();
    return 0;
}