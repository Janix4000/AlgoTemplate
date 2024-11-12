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
    int q;
    cin >> q;
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }
    vi xs(q);
    for (size_t i = 0; i < q; i++) {
        cin >> xs[i];
    }
    vi add(31, 0);
    int max_h = 32;
    for (size_t i = 0; i < q; i++) {
        int h = xs[i];
        if (max_h <= h) continue;
        max_h = h;

        int d = 1 << (h - 1);
        add[h] = d;
    }

    for (size_t i = 0; i < n; i++) {
        int h = __builtin_ctz(a[i]);
        for (size_t j = 0; j <= h; j++) {
            a[i] += add[j];
        }
        cout << a[i] << ' ';
    }
    cout << endl;
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