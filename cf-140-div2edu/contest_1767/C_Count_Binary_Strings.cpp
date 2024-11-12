#include <bits/stdc++.h>

using namespace std;


using vi = vector<int>;
using vvi = vector<vi>;

constexpr int P = 998244353;



int32_t main() {
    int t;
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vvi bad(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int a;
            cin >> a;
            bad[j - i].push_back(a);
        }
    }

    
    
}
