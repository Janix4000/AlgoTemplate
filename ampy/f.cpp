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

using pi = pair<int, int>;
using pl = pair<ll, ll>;

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////



void solution() {
    int n, k;
    cin >> n >> k;
    priority_queue<pi> ds;
    map<int, int> ls;
    for (size_t i = 0; i < n; i++) {
        int d;
        cin >> d;
        ds.push({d * 5, 5});
    }
    for (int i = 0; i < k; i++) {
        int l; cin >> l;
        ls[l]++;
    }
    int rr =0;
    while(!ds.empty()) {
        auto [d, k] = ds.top(); ds.pop();
        auto it = ls.upper_bound(d-1);
        if(it == ls.end()) {
            if(k == 5) {
                ds.emplace(d / 5 * 3, 3);
                ds.emplace(d / 5 * 2, 2);
            } else {
                cout << "NIE\n";
                return;
            }
            continue;
        }
        if(--it->second == 0) {
            ls.erase(it);
        }
        rr++;
    }

    cout << rr << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;
    // cin >> qs;

    while (qs--) {
        solution();
    }
    return 0;
}