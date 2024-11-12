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
    string s;
    cin >> s;

    for (int k = 1; k <= n; ++k) {
        int as = 0;
        int bs = 0;
        int ha = 0;
        int hb = 0;
        for (auto &&c : s) {
            if (c == 'A') {
                as++;
                if (as == k) {
                    ha++;
                    as = 0;
                    bs = 0;
                }
            }
            if (c == 'B') {
                bs++;
                if (bs == k) {
                    hb++;
                    as = 0;
                    bs = 0;
                }
            }
        }
        if (as == 0 && bs == 0) {
            if (s.back() == 'A' && ha > hb) {
                cout << "A" << endl;
                return;
            }
            if (s.back() == 'B' && hb > ha) {
                cout << "B" << endl;
                return;
            }
        }
    }
    cout << "?" << endl;
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