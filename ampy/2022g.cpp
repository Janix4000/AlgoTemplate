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

int sgn(int n) {
    return n / abs(n);
}

void solution() {
    int n, v;
    cin >> n >> v;
    vl vs(n), ps(n);
    int il = -1, ir = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> ps[i] >> vs[i];
        if(ps[i] < 0) {
            il = i;
        } else {
            ir = i;
        }
    }
    double l = 1e-14, r = double(ps[ir] - ps[il]) / double(vs[ir] + vs[il]);
    while(r - l > 1e-14) {
        double m = l + (r - l) / 2;
        double minr = +1e9, maxl = -1e9;
        for (int i = 0; i < n; i++)
        {
            double x = ps[i] + m * vs[i] * sgn(-ps[i]);
            if(ps[i] > 0) {
                minr = min(minr, x);
            } else {
                maxl = max(maxl, x);
            }
        }
        if(minr < maxl) {
            r = m;
        } else {
            l = m;
        }
    }
    double t = l + (r - l) / 2;
    cout << t * v << endl; 
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;
    cin >> qs;
    cout << setprecision(12) << fixed;

    while (qs--) {
        solution();
    }
    return 0;
}