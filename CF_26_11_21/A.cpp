#include <bits/stdc++.h>

template <typename... Ts>
void __print(Ts &&...ts) {}
#ifdef DEBUG
#include "print.hpp"
#endif  // DEBUG

using namespace std;

template <class T>
using pq_max = priority_queue<T>;
template <class T>
using pq_min = priority_queue<T, vector<T>, greater<T>>;

#define FOR(i, a, b) for (int i = a; i < (b); ++i)
#define F0R(i, a) for (int i = 0; i < (a); ++i)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; --i)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; --i)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define all(x) x.begin(), x.end()
#define loop(i, b) for (int i = 0; i < (b); ++i)
#define loopr(i, b) for (int i = (b)-1; i >= 0; --i)
#define sz(x) ((int)(x).size())

using ll = long long;
template <typename T>
using vec = vector<T>;
template <typename T, size_t N>
using arr = array<T, N>;

using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

using pi = pair<int, int>;
using pl = pair<ll, ll>;

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

class Solution {};

void solution() {
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    vi chs(n);
    loop(i, n) { cin >> chs[i]; }
    chs.erase(remove_if(all(chs), [l](int a) { return a < l; }), chs.end());
    chs.erase(remove_if(all(chs), [r](int a) { return a > r; }), chs.end());
    sort(all(chs));
    reverse(all(chs));
    int res = 0;
    while (!chs.empty()) {
        k -= chs.back();
        if (k < 0) {
            break;
        }
        chs.pop_back();
        res++;
    }
    cout << res << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;
    cin >> qs;

    while (qs--) {
        solution();
    }

    // Solution solution;
    return 0;
}