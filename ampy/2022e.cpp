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

    // ll a = 15;
    // ll n = 10000;
    // ll rr = 0;
    // ll N = n - a;
    // for(ll i = 1, la; i <= N; i = la + 1) {
    //     la = N / (N / i);
    //     int l = ((i)+a-1)/a;
    //     int r = (la) / a;
    //     rr += N / i * (r - l + 1);
    // }

    // cout << rr << endl;

    // rr = 0;
    // for (ll i = 1; i <= N; i++)
    // {
    //     rr += N / (i * a);
    // }

    // cout << rr << endl;
    
    ll n;
    cin >> n;

    if (n == 2) {
        cout << 1 << endl;
        return;
    }

    ll r1 = 0, r2 = 0, r3=0, r4=0, r5; 

    for(ll a = 1; a * a * a <= n; ++a) {
        ll rr = 0;
        ll N = n - a;
        for(ll i = 1, la; i <= N; i = la + 1) {
            la = N / (N / i);
            int l = ((i)+a-1)/a;
            int r = (la) / a;
            rr += N / i * (r - l + 1);
        }
        r1 += rr;
    }
    for(ll b = 1; b * b * b <= n; ++b) {
        ll N = n;
        ll rr = 0;
        for(int i = 1, la; i < N; i = la + 1) {
            la = N / (N / i);
            int l = ((i-1)+b-1)/b;
            int r = (la-1) / b;
            rr += N / i * (r - l + 1);
        }
        r2 += rr - N;
    }
    for(ll a = 1; a * a * a <= n; ++a) {
        for(ll b = 1; b * b * b <= n; ++b) {
            r3 += (n - a) / (b * a);
        }
    }
    for(ll b = 1; b * b * b <= n; ++b) {
        for(ll c = 1; c * c * c <= n; ++c) {
            r4 += n / (b * c + 1);
        }
    }
    int h = 1;
    for(; h * h * h <= n; ++h) {}
    h--;
    r5 = h * h * h;

    cout << r1 + 2 * r2 - 2 * r3 - r4 + r5 << endl;
    
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