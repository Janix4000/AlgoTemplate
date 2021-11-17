#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, b) FOR(i, 0, b)
#define all(x) (x).begin(), (x).end()

template <typename T>
using vec = vector<T>;

using ll = long long;
constexpr ll INF = 1000000000LL;

using vi = vec<ll>;
using vvi = vec<vi>;
using vvvi = vec<vvi>;

void solution() {
    ll n, q;
    cin >> n >> q;
    ll N = n * n;
    vi dp(N + 1, INF);
    F0R(i, n) { cin >> dp[i + 1]; }

    vi qs(q);
    F0R(i, q) { cin >> qs[i]; }

    FOR(i, n + 1, N + 1) {
        FOR(j, 1, n + 1) { dp[i] = min(dp[i], dp[i - j] + dp[j]); }
    }
    for (int q : qs) {
        ll best = INF;
        if (q <= N) {
            best = dp[q];
        } else {
            FOR(i, 1, n + 1) {
                ll a = dp[i];
                int times = (q - N + i - 1) / i;
                int qq = q - times * i;
                best = min(best, times * a + dp[qq]);
            }
        }

        cout << best << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int qs = 1;
    // cin >> qs;
    while (qs--) {
        solution();
    }
}