#include <bits/stdc++.h>

template <typename... Ts>
void __print(Ts &&...ts) {}
#ifdef DEBUG
#include "print.hpp"
#endif  // DEBUG

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

// typedef pair<int, int> pi;
// typedef pair<ll, ll> pl;
// typedef pair<ld, ld> pd;

// template <typename T>
// using vec = vector<T>;
// template <typename T>
// using arr = array<T>;
// typedef vector<int> vi;
// typedef vector<vi> vvi;
// typedef vector<ll> vl;
// typedef vector<vl> vvl;

template <class T>
using pq_max = priority_queue<T>;
template <class T>
using pq_min = priority_queue<T, vector<T>, greater<T>>;

#define FOR(i, a, b) for (int i = a; i < (b); ++i)
#define F0R(i, a) for (int i = 0; i < (a); ++i)
// #define loop(i, b) for (int i = 0; i < (b); ++i)
// #define loopr(i, b) for (int i = (b)-1; i >= 0; --i)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; --i)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; --i)
#define trav(a, x) for (auto &a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

#define IN(n) \
    int n;    \
    cin >> n;

// #define sz(x) (int)(x).size()
// #define mp make_pair
// #define pb push_back
// #define fir first
// #define sec second
// #define lb lower_bound
// #define ub upper_bound
// #define ins insert
// #define beg begin

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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

class Solution {};

void solution() {
    int n;
    cin >> n;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;
    // cin >> qs;

    while (qs--) {
        solution();
    }

    // Solution solution;
    return 0;
}