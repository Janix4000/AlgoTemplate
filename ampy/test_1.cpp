#include <bits/stdc++.h>

#include <algorithm>

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
mt19937 rng(3);
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
///////////////////////////////////////////////////////////////////////////////////////////////

void solution() {
    int n = int(2e5);
    // int n; cin >> n;
    vl ns(n);
    iota(all(ns), 1);
    shuffle(all(ns), rng);

    vl as(n + 1);
    partial_sum(all(ns), as.begin());


    ll res = 0;
    for (size_t i = 0; i < n; i++) {
        int j = i + 1;
        ll jump = n;
        while (j <= n) {
            ll diff = as[j] - as[i];
            ll len = j - i;
            if (3 * len >= 2 * n + 1) {
                break;
            }
            ll target = 1ll * len * len;
            if (diff == target) {
                res++;
                j++;
            } else if (diff > target && jump-- > 0) {
                const ll s = int(sqrt(diff));
                j = i + s + 1;
            } else {
                j++;
            }
        }
    }
    cout << res << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;
    // cin >> qs;
    // cout << setprecision(12) << fixed;

    while (qs--) {
        solution();
    }
    return 0;
}