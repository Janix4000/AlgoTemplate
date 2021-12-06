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

using ull = unsigned long long;
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
ll P = 998244353;

template <size_t P = 998244353>
struct Mint {
    ll x;
    Mint() = default;
    Mint(ll a) { x = a % P; }
    Mint &operator+=(const Mint &rhs) {
        x = (x + rhs.x) % P;
        return *this;
    }
    Mint operator+(const Mint &rhs) {
        auto res = *this;
        return (res += rhs);
    }
    Mint &operator=(ll a) {
        x = a % P;
        return *this;
    }
    friend istream &operator>>(istream &in, Mint &x) {
        in >> x.x;
        x.x %= P;
        return in;
    }
    operator ll() { return x; }
    // bool operator==(ll a) { return x == a; }
    // bool operator<(ll a) { return x < a; }
    // bool operator>(ll a) { return x > a; }
    // bool operator<=(ll a) { return x <= a; }
    // bool operator>=(ll a) { return x >= a; }
};
Mint<> operator"" m(ull a) { return Mint(a); }

struct solution {
    solution() {
        ll n;
        cin >> n;
        vec<Mint<>> as(n);
        vec<Mint<>> dp(n + 1);
        vec<Mint<>> dp_blank(n + 1);
        Mint<> res = 0;
        loop(i, n) {
            Mint<> a;
            cin >> a;

            if (a == 0) {
                dp[0] += dp[0] + 1m;
            } else if (a == 1) {
                dp[1] += dp[1] + dp[0] + 1m;
                dp_blank[1] += dp_blank[1] + 1m;
            } else {
                dp[a] += dp[a] + dp[a - 1];
                dp_blank[a] += dp_blank[a] + dp[a - 2];
            }
            if (a < n) {
                dp[a.x + 1] += dp_blank[a.x + 1];
            }
            // ll add = 0;
        }
        loop(i, n + 1) { res += dp[i] + dp_blank[i]; }
        cout << res.x << '\n';
    }
};

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