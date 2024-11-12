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
    vi a(n);
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(all(a));
    ll res = 0;
    int r = n - 1, l = 0;
    int x = 0;
    while (l <= r) {
        if (l == r) {
            res += (a[l] - x) / 2 + (a[l] - x) % 2 + 1;
            if (a[l] == 1) res--;
            break;
        }
        if (a[l] + x < a[r]) {
            x += a[l];
            res += a[l];
            l++;
        } else if (a[l] + x == a[r]) {
            res += a[l] + 1;
            l++;
            x = 0;
            r--;
        } else {
            int d = a[r] - x;
            res += d + 1;
            a[l] -= d;
            x = 0;
            r--;
        }
    }

    cout << res << endl;
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