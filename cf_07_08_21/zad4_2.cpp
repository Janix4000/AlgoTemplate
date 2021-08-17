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

struct hash_pair {
    size_t operator()(const pair<int, int>& p) const {
        size_t seed = hash<int>{}(p.first);
        return hash<int>{}(p.second) + 0x9e3779b9 + (seed << 6) + (seed >> 2); 
    }
};

int main(int argc, const char** argv) {
    int n, k;
    cin >> n >> k;
    vector<unordered_set<pair<int, int>, hash_pair>> dp(k);
    vector<unordered_set<pair<int, int>, hash_pair>> last_dp(k);
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

    last_dp[0].insert({nums_2[0], nums_5[0]});
    dp[0].insert({nums_2[0], nums_5[0]});
    
    for (int i = 1; i < n; i++) {
        int n_2 = nums_2[i];
        int n_5 = nums_5[i];

        dp[0].emplace(n_2, n_5);
        for(int j = 1; j < min(i + 1, k); j++) {
            for (auto [i2, i5] : last_dp[j-1]) {
                dp[j].emplace(i2 + n_2, i5 + n_5);
            }
        }
        last_dp = dp;
    }
    // print(1, 0);
    int max_sum = 0;
    for (auto [i2, i5] : dp[k-1]) {
        max_sum = max(max_sum, min(i2, i5));
    }
    cout << max_sum;
    return 0;
}