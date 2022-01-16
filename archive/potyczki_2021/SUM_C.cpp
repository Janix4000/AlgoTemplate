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

#define GET_FOR(_1, _2, _3, NAME, ...) NAME
#define loop(...) GET_FOR(__VA_ARGS__, FOR, F0R)(__VA_ARGS__)

#define GET_FORd(_1, _2, _3, NAME, ...) NAME
#define loopr(...) GET_FOR(__VA_ARGS__, FORd, F0Rd)(__VA_ARGS__)

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

void solution() {
    int n;
    cin >> n;
    vl fishes(n);
    loop(i, n) { cin >> fishes[i]; }

    vi beg(n);
    beg[0] = 0;
    auto sorted = fishes;
    sort(all(sorted));
    ll min_mass;
    if (sorted.front() == sorted.back()) {
        min_mass = sorted.back() + 1;
    } else {
        loop(i, 1, n) {
            ll a = sorted[i];
            ll prev = sorted[i - 1];
            if (prev == a) {
                beg[i] = beg[i - 1];
            } else {
                beg[i] = i;
            }
        }
        vl sums(n + 1);
        sums[0] = 0;
        loop(i, n) { sums[i + 1] = sums[i] + sorted[i]; }

        min_mass = sorted.back();
        loopr(i, n - 1) {
            if (sorted[i] + sums[beg[i]] > min_mass) {
                min_mass = sorted[i];
            }
        }
    }
    for (int a : fishes) {
        cout << (a >= min_mass ? 'T' : 'N');
    }
    cout << '\n';
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