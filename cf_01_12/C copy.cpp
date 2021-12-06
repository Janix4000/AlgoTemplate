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

struct solution {
    bool helper(vec<ll>& diffs, ll k, ll h) {
        ll res = 0;
        for (ll diff : diffs) {
            res += min(diff, k);
        }
        return res >= h;
    }
    solution() {
        ll n, h;
        cin >> n >> h;
        // 100^500
        vi as(n);
        loop(i, n) { cin >> as[i]; }
        vec<ll> diffs(n);
        diffs.back() = ll(1e18);
        loop(i, n - 1) { diffs[i] = as[i + 1] - as[i]; }

        sort(all(diffs));
        ll l = 1, r = ll(1e18);

        while (l < r) {
            ll mid = l + (r - l) / 2;
            if (helper(diffs, mid, h)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        cout << l << '\n';
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;
    cin >> qs;

    while (qs--) {
        solution();
    }

    return 0;
}