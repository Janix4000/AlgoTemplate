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

    cin >> l_in >> r_in;
    int log2l = 2;
    ll l = 4;
    ll res = 0;
    for (; l <= r_in; l *= 2, log2l++) {
        ll r = l * 2;
        if (r < l_in) continue;
        ll l2 = max(l, l_in);
        ll r2 = min(r, r_in + 1);

        int kk = log2l;
        ll t = 1;
        int logkt = 0;
        while (t * kk < l2 && t * kk > 0) {
            t *= kk;
            logkt++;
        }
        {
            ll diff = (t * kk < 0) ? r2 - l2 : t * kk - l2;
            diff %= M;
            res = (res + diff * logkt % M) % M;
        }
        if (t * kk > 0 && t * kk < r2) {
            ll diff = r2 - t * kk;
            diff %= M;
            res = (res + diff * (logkt + 1) % M) % M;
        }
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
    return 0;
}