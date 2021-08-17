#include <bits/stdc++.h>

constexpr int N = int(200) + 1;
constexpr int K = int(200) + 1;
constexpr int N2 = 60 + 1;
constexpr int N5 = 26 + 1;
using namespace std;
using ll = long long;
using ull = unsigned long long;

int nums_2[N];
int nums_5[N];
int n5=0, n2=0;

int get_divs(int n, int a) {
    int count = 0;
    while (n > 0 && n % a == 0) {
        count++;
        n /= a;
    }
    return count;
}

bool dp[N][K][N2][N5] = {};

int print(int n, int k)  {
    for(int i2 = 0; i2 < n2; ++i2) {
        for(int i5 = 0; i5 < n5; ++i5) {
            cout << dp[n][k][i2][i5] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

int main(int argc, const char** argv) {
    int n, k;
    cin >> n >> k;
    for (size_t i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int n_2 = get_divs(a, 2);
        int n_5 = get_divs(a, 5);
        nums_2[i] = n_2;
        nums_5[i] = n_5;
        n2 = max(n2, n_2 + 2);
        n5 = max(n5, n_5 + 2);
    }

    dp[0][0][nums_2[0]][nums_5[0]] = 1;
    
    for (int i = 1; i < n; i++) {
        int n_2 = nums_2[i];
        int n_5 = nums_5[i];

        for(int i2 = 0; i2 < n2; ++i2) {
            for(int i5 = 0; i5 < n5; ++i5) {
                dp[i][0][i2][i5] = dp[i - 1][0][i2][i5];
            }
        }
        dp[i][0][n_2][n_5] = 1;
        for(int j = 1; j < min(i + 1, k); j++) {
            for(int i2 = 0; i2 < n2; ++i2) {
                for(int i5 = 0; i5 < n5; ++i5) {
                    if(dp[i-1][j][i2][i5] == 1) {
                        dp[i][j][i2][i5] = 1;
                    }
                    if (i2 >= n2 && i5 >= n5 && dp[i-1][j-1][i2 - n_2][i5 - n_5] == 1) {
                        dp[i][j][i2][i5] = 1;
                    }
                }
            }
        }
    }
    print(1, 0);
    int max_sum = 0;
    for(int i2 = 0; i2 < n2; ++i2) {
        for(int i5 = 0; i5 < n5; ++i5) {
            if(dp[n-1][k-1][i2][i5] == 1) {
                max_sum = max(max_sum, min(i2, i5));
            }
        }
    }
    cout << max_sum;
    return 0;
}