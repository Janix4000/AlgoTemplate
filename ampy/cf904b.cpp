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

int sum(ll x) {
    int rs = 0;
    while(x) {
        rs += x % 10;
        x /= 10;
    }
    return rs;
}

void solution() {
    int n;
    cin >> n;
    string s;
    s.reserve(n);
    cin >> s;
    reverse(all(s));
    int j = 0;
    ll t = 0;

    for (size_t i = 0; i < n; i++)
    {
        if(s[i]=='0') {
            t += i - j;
            cout << t << ' ';
            j++;
        }
    }
    for (size_t i = j; i < n; i++)
    {
        cout << "-1 ";
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