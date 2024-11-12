#include <bits/stdc++.h>

using namespace std;

int P(int k) {
    int res = 0;


    for (int p = 2; p * p <= k; ++p) {
        int n = 0;
        while (k % p == 0) {
            k /= p;
            n++;
        }
        int cand = p - 1;
        while (n > 0)
        {
            cand++;
            n -= cand / p;
        }
        if(cand >= p) {
            res = max(res, cand);
        }
        
    }

    res = max(res, k);

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int k;
        cin >> k;

        int res = P(k);


        if (res >= k) {
            cout << -1 << endl;
        } else {
            cout << res << endl;
        }
    }
}