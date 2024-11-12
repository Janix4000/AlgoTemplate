#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;

    cin >> n >> k;
    k--;

    ll m = (1ll << (n)) - 1;
    int res = n;
    while (true) {
        if (k == m / 2) {
            break;
        } else {
            m /= 2;
            if (k > m) {
                k -= (m + 1);
            }
            res--;
        }
    }

    cout << res << endl;

    return 0;
}