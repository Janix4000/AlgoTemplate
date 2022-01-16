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

class Solution {};

void solution() {
    int n;
    cin >> n;
    vi as(n);
    vi bs(n);
    loop(i, n) { cin >> as[i]; }
    loop(i, n) { cin >> bs[i]; }
    vi sas(n);
    iota(all(sas), 0);
    sort(all(sas), [&as](int a, int b) { return as[a] < as[b]; });

    vi rsas(n);
    loop(i, n) { rsas[sas[i]] = i; }

    vi sbs(n);
    iota(all(sbs), 0);
    sort(all(sbs), [&bs](int a, int b) { return bs[a] < bs[b]; });

    vi rsbs(n);
    loop(i, n) { rsbs[sbs[i]] = i; }

    vi min_b_sas(n);
    min_b_sas[n - 1] = rsbs[sas[n - 1]];
    loopr(i, n - 1) { min_b_sas[i] = min(min_b_sas[i + 1], rsbs[sas[i]]); }

    vi min_a_sbs(n);
    min_a_sbs[n - 1] = rsas[sbs[n - 1]];
    loopr(i, n - 1) { min_a_sbs[i] = min(min_a_sbs[i + 1], rsas[sbs[i]]); }

    string winners(n, '0');

    int min_ia = -1;
    int min_ib = -1;
    int new_min_ia = n - 1;
    int new_min_ib = n - 1;
    while (new_min_ia != min_ia || new_min_ib != min_ib) {
        // A]
        min_ia = new_min_ia;
        min_ib = new_min_ib;

        new_min_ia = min_a_sbs[min_ib];
        new_min_ib = min_b_sas[min_ia];
    }

    loop(i, min_ia, n) { winners[sas[i]] = '1'; }
    loop(i, min_ib, n) { winners[sbs[i]] = '1'; }
    cout << winners << '\n';
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