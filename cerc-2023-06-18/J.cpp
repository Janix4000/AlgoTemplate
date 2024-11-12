#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using ld = long double;

#define all(x) (x).begin(), (x).end()

using pi = pair<int, int>;
using vpi = vector<pi>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    if (n > m) {
        cout << "YES\n";
        return 0;
    }

    vi as(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
        as[i] = as[i] % m;
    }

    vvi dp(n + 1, vi(m, false));
    dp[0][as[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int k = 0; k < m; k++) {
            dp[i][k] = dp[i - 1][k] || dp[i - 1][(k - as[i] + m) % m];
        }
        dp[i][as[i]] = true;
    }

    cout << (dp[n - 1][0] ? "YES" : "NO") << endl;

    return 0;
}