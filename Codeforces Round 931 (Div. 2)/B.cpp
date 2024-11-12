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

class Solution {};

int dp[400] = {};

void solution() {
    int n;
    cin >> n;
    if (n >= 400) {
        int k = (n - 400) / 15 + 1;
        cout << k + dp[n - k * 15] << '\n';
    } else {
        cout << dp[n] << '\n';
    }
}

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// #define ordered_set                                            \
//     tree<int64_t, null_type, less_equal<int64_t>, rb_tree_tag, \
//          tree_order_statistics_node_update>
// ordered_set S;
// S.insert(a);
// cout << *(S.find_by_order(S.size() - a)) << '\n';
// S.erase(S.lower_bound(a - 1));

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;
    cin >> qs;

    // 1 3 6 10 15
    dp[0] = 0;
    for (size_t i = 1; i < 400; i++) {
        dp[i] = int(1e9);
    }

    for (int i = 1; i < 400; i++) {
        for (int k : {1, 3, 6, 10, 15}) {
            if (i - k >= 0) {
                dp[i] = min(dp[i], dp[i - k] + 1);
            }
        }
    }

    while (qs--) {
        solution();
    }

    // Solution solution;
    return 0;
}