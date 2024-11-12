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

void solution() {
    int n;
    cin >> n;
    map<int, int, greater<>> ns;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        ns[a]++;
    }

    ll neg_ps = 0;
    vi dp(n + 1, 0);

    for(auto [a, k] : ns) {
        ll r = 0;

        for(int t = a; t <= n; t += a) {
            auto it = ns.find(t);
            if(it != ns.end()) {
                r += it->second;
            }
        }
        int diff = 0;
        for(int t = a + a; t <= n; t += a) {
            diff += dp[t];
        }
        ll res = 1ll * r * (r - 1) / 2 - diff;
        neg_ps += res;
        dp[a] = res;
    }
    

    ll sol = 1ll * n * (n - 1) / 2 - neg_ps;

    cout << sol << endl;
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