#include <bits/stdc++.h>

#include <vector>

template <typename... Ts>
void __print(Ts &&...ts) {}
#ifdef DEBUG
#include "print.hpp"
#endif  // DEBUG

using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) ((int)(x).size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

using vs = vector<string>;
using vvs = vector<vs>;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vpi = vector<pi>;

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

constexpr ll M = 1e9 + 7;

void solution() {
    ll l_in, r_in;
    // 2^4, ..... 2^5
    // 4 4 4 4 4 4 5 5 5 5
    // 2 2 2 3 3 3
    // g = log_f(l)(l), 
    cin >> l_in >> r_in;
    ll res = 0;
    int r = 0;
    ll h = l_in;
    while (h) {
        h /= 2;
        r++;
    }
    r = max(3, r);
    for (; r <= 60 && (1ll << (r - 1)) <= r_in; r++) {
        // r = 5
        ll l2 = max(1ll << (r - 1), l_in); // 2^4=16
        ll r2 = min(1ll << r, r_in + 1); // 2^5=32
        int kk = r - 1; // 4
        ll t = 1;
        int logt = 0;
        while (t * kk < l2) {
            t *= kk;
            logt++;
        }
        while (t < r2 && t > 0) {
            // 3 3 3 4 4 4 4 5 5 5 5 5
            ll max_r = (t * kk < 0) ? r2 : min(t * kk, r2);
            ll diff = (max_r - max(t, l2)) % M * logt % M;
            res = (res + diff) % M;
            if (diff < 0) {
                int a = 1;
            }
            logt++;
            t *= kk;
        }
    }
    cout << res % M << endl;
}

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