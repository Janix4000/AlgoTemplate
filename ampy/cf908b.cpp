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
    vi as(n);
    for (size_t i = 0; i < n; i++) {
        cin >> as[i];
    }

    map<int, int> cnt;
    for (size_t i = 0; i < n; i++) {
        cnt[as[i]]++;
    }

    int ones = 0;
    for (auto [a, b] : cnt) {
        ones += b == 1;
    }

    if (cnt.size() <= 1 || cnt.size() - ones <= 1) {
        cout << -1 << endl;
        return;
    }

    set<int> used;

    vi bs(n);
    int first = -1;
    for (size_t i = 0; i < n; i++) {
        auto it = used.find(as[i]);
        if (it == used.end()) {
            bs[i] = 1;
            used.insert(as[i]);
        } else {
            if (first == -1 || first == as[i]) {
                first = as[i];
                bs[i] = 2;
            } else {
                bs[i] = 3;
            }
        }
    }
    for (auto &&b : bs) {
        cout << b << " ";
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