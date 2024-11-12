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
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;

using pi = pair<int, int>;
using pl = pair<ll, ll>;

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

class Solution {};

void solution() {
    int n;
    cin >> n;
}

enum Direction { INCREASED, DECREASED };
enum Decision { KEEP, CHANGE };

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    const int inf = n;

    vvvi dp(2, vvi(2, vi(n, inf)));

    dp[INCREASED][KEEP][0] = 0;
    dp[DECREASED][KEEP][0] = 0;
    dp[INCREASED][CHANGE][0] = 1;
    dp[DECREASED][CHANGE][0] = 1;

    for (int i = 1; i < n; i++) {
        if (t[i] > t[i - 1]) {
            dp[INCREASED][KEEP][i] =
                min(dp[DECREASED][KEEP][i - 1], dp[DECREASED][CHANGE][i - 1]);
        } else {
            dp[INCREASED][KEEP][i] = dp[DECREASED][CHANGE][i - 1];
        }

        if (t[i] < t[i - 1]) {
            dp[DECREASED][KEEP][i] =
                min(dp[INCREASED][KEEP][i - 1], dp[INCREASED][CHANGE][i - 1]);
        } else {
            dp[DECREASED][KEEP][i] = dp[INCREASED][CHANGE][i - 1];
        }

        dp[INCREASED][CHANGE][i] =
            min(dp[DECREASED][KEEP][i - 1], dp[DECREASED][CHANGE][i - 1]) + 1;

        dp[DECREASED][CHANGE][i] =
            min(dp[INCREASED][KEEP][i - 1], dp[INCREASED][CHANGE][i - 1]) + 1;
    }

    cout << min(min(dp[INCREASED][KEEP].back(), dp[DECREASED][KEEP].back()),
                min(dp[INCREASED][CHANGE].back(), dp[DECREASED][CHANGE].back()))
         << endl;
}