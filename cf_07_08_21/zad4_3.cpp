#include <bits/stdc++.h>

constexpr int N = int(200) + 1;
constexpr int K = int(200) + 1;
constexpr int N5 = (26 + 1) * N;
using namespace std;
using ll = long long;
using ull = unsigned long long;

int nums_2[N];
int nums_5[N];

int get_divs(ll n, ll a) {
    int count = 0;
    while (n > 0 && n % a == 0) {
        count++;
        n /= a;
    }
    return count;
}

int main(int argc, const char** argv) {
    int n, k;
    cin >> n >> k;
    int n5 = 0;
    for (size_t i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        int n_2 = get_divs(a, 2);
        int n_5 = get_divs(a, 5);
        nums_2[i] = n_2;
        nums_5[i] = n_5;
        n5 += n_5;
    }
    using vec = vector<int>;
    vector<vec> dp(k, vec(n5 + 1, -1));
    dp[0][nums_5[0]] = nums_2[0];
    int prev_n5_max = nums_5[0];
    auto prev_dp = dp;
    for (int i = 1; i < n; i++)
    {
        int n_2 = nums_2[i], n_5 = nums_5[i];
        dp[0][n_5] = max(prev_dp[0][n_5], n_2);
        for(int j = 1; j < min(i + 1, k); ++j) {
            for(int i5 = 0; i5 <= prev_n5_max; ++i5) {
                if(prev_dp[j-1][i5] != -1) {
                    dp[j][i5 + n_5] = max(prev_dp[j][i5 + n_5], prev_dp[j-1][i5] + n_2); 
                }
            }
        }   
        prev_dp = dp;
        prev_n5_max += n_5;
    }
    
    int max_sum = 0;
    for (int i5 = 0; i5 <= prev_n5_max; i5++)
    {
        max_sum = max(max_sum, min(dp[k-1][i5], i5));
    }
    cout << max_sum;
    return 0;
}