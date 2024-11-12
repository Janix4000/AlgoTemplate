#include <bits/stdc++.h>

#include <vector>

template <typename... Ts>
void __print(Ts&&... ts) {}
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

void solution() {
    int m;
    cin >> m;

    map<ll, ll> rest;
    map<ll, ll> min_taken;
    map<ll, ll> cnt;

    ll L = 0, R = 0;

    for (size_t i = 0; i < m; i++) {
        int n;
        ll l, r;
        cin >> n >> l >> r;
        L += l;
        R += r;
        vl nums;
        for (size_t j = 0; j < n; j++) {
            ll a;
            cin >> a;
            nums.push_back(a);
        }

        vl cs;
        ll N = 0;

        for (auto a : nums) {
            ll c;
            cin >> c;
            cs.push_back(c);
            cnt[a] += c;
            N += c;
        }

        for (size_t j = 0; j < n; j++) {
            rest[nums[j]] += min(N - cs[j], r);
            min_taken[nums[j]] += max(l - N + cs[j], 0ll);
        }
    }

    ll best = R + 1;

    if (cnt.count(L) == 0) {
        best = 0;
    }
    if (cnt.count(R) == 0) {
        best = 0;
    }

    for (auto [a, c] : cnt) {
        ll mt = min_taken[a];
        ll re = rest[a];

        if (l <= re && re <= R) ll n = c;
        ll cur = L + l + r - n;
        best = min(best, cur);
    }

    cout << best << endl;
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