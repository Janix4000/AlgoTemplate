#include <bits/stdc++.h>

using namespace std;

template <typename T>
using vec = vector<T>;

using ll = long long;

using vi = vector<ll>;
using vvi = vec<vi>;
using vvvi = vec<vvi>;

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

void solution()
{
    const ll P = 998244353;
    int n, k;
    cin >> n >> k;
    vvvi dp(max(n, 2), vvi(max(k + 1, 5), vi(2, 0)));
    dp[0][1][0b00] = 1;
    dp[0][1][0b01] = 0;

    dp[0][2][0b00] = 0;
    dp[0][2][0b01] = 1;

    dp[1][1][0b00] = 1;
    dp[1][1][0b01] = 0;

    dp[1][2][0b00] = 3;
    dp[1][2][0b01] = 3;

    dp[1][3][0b00] = 0;
    dp[1][3][0b01] = 0;

    dp[1][4][0b00] = 0;
    dp[1][4][0b01] = 1;

    for (int i = 2; i < n; ++i)
    {
        dp[i][1][0b00] = 1;
        dp[i][1][0b01] = 0;

        dp[i][2][0b00] = (dp[i - 1][2][0b00] + dp[i - 1][2][0b01] + dp[i - 1][2][0b01] + dp[i - 1][2 - 1][0b00]) % P;
        dp[i][2][0b01] = (dp[i - 1][2][0b01] + dp[i - 1][2 - 1][0b00] + dp[i - 1][2 - 1][0b00]) % P;

        dp[i][3][0b00] = (dp[i - 1][3][0b00] + dp[i - 1][3][0b01] + dp[i - 1][3][0b01] + dp[i - 1][3 - 1][0b00]) % P;
        dp[i][3][0b01] = (dp[i - 1][3][0b01] + dp[i - 1][3 - 1][0b00] + dp[i - 1][3 - 1][0b00]) % P;

        for (int j = 4; j <= min(k, 2 * (i + 1)); ++j)
        {
            dp[i][j][0b00] = (dp[i - 1][j][0b00] + dp[i - 1][j][0b01] + dp[i - 1][j][0b01] + dp[i - 1][j - 1][0b00]) % P;
            dp[i][j][0b01] = (dp[i - 1][j][0b01] + dp[i - 1][j - 1][0b00] + dp[i - 1][j - 1][0b00] + dp[i - 1][j - 2][0b01]) % P;
        }
    }
    cout << dp[n - 1][k][0b00] + dp[n - 1][k][0b01] + dp[n - 1][k][0b01] + dp[n - 1][k][0b00];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;
    // cin >> qs;

    while (qs--)
    {
        solution();
    }
    return 0;
}