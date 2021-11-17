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

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

template <typename T>
using vec = vector<T>;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T>
using pq_max = priority_queue<T>;
template <class T>
using pq_min = priority_queue<T, vector<T>, greater<T>>;

#define FOR(i, a, b) for (int i = a; i < (b); ++i)
#define F0R(i, a) for (int i = 0; i < (a); ++i)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; --i)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; --i)
#define trav(a, x) for (auto &a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

#define IN(n) \
    int n;    \
    cin >> n;

#define all(x) x.begin(), x.end()

template <class T>
bool ckmin(T &a, const T &b) {
    return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
    return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
T max(T a, T b, T c) {
    return max(max(a, b), c);
}
template <typename T, typename... Ts>
T max(T a, Ts... as) {
    return max(a, max(as...));
}
template <typename T>
T min(T a, T b, T c) {
    return min(min(a, b), c);
}
template <typename T, typename... Ts>
T min(T a, Ts... as) {
    return min(a, min(as...));
}
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

void solution() {
    IN(n);
    string s;
    cin >> s;
    reverse(all(s));
    int ones = count(all(s), '1');
    int ones_good = count(s.begin(), s.begin() + ones, '1');
    int zeros_free = ones - ones_good;
    vi res;
    FOR(i, 0, ones) {
        char c = s[i];
        if (c == '0') {
            res.push_back(n - i);
        }
    }
    FOR(i, ones, n) {
        if (!zeros_free) {
            break;
        }
        char c = s[i];
        if (c == '1') {
            res.push_back(n - i);
            zeros_free--;
        }
    }

    if (!res.empty()) {
        cout << "1\n";
        sort(all(res));
        cout << res.size() << ' ';
        for (int i : res) {
            cout << i << ' ';
        }

    } else {
        cout << '0';
    }
    cout << '\n';
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