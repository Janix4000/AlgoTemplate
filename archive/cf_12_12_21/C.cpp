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
    int n, k;
    cin >> n >> k;
    vi tab(n);
    loop(i, n) { cin >> tab[i]; }
    sort(all(tab));
    int left = count_if(all(tab), [](int a) { return a < 0; });
    int zeros = count(all(tab), 0);
    int right = n - left - zeros;

    vi uniq = tab;
    uniq.erase(unique(all(uniq)), uniq.end());
    vi cnt(uniq.size(), 0);
    {
        int idx = 0;
        for (int a : tab) {
            if (uniq[idx] != a) {
                idx++;
            }
            cnt[idx]++;
        }
    }
    int t = k;
    ll res = 0;
    int idx = 0;
    for (; idx < uniq.size() && uniq[idx] < 0; ++idx) {
        while (cnt[idx] > 0) {
            if (t == k) {
                res += 2 * abs(uniq[idx]);
            }
            int diff = min(t, cnt[idx]);
            cnt[idx] -= diff;
            t -= diff;
            if (t == 0) {
                t = k;
            }
        }
    }
    idx = uniq.size() - 1;
    t = k;
    for (; idx >= 0 && uniq[idx] > 0; --idx) {
        while (cnt[idx] > 0) {
            if (t == k) {
                res += 2 * abs(uniq[idx]);
            }
            int diff = min(t, cnt[idx]);
            cnt[idx] -= diff;
            t -= diff;
            if (t == 0) {
                t = k;
            }
        }
    }
    if (abs(uniq.front()) > abs(uniq.back())) {
        res -= abs(uniq.front());
    } else {
        res -= abs(uniq.back());
    }
    cout << res << '\n';
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