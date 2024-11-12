
#include <bits/stdc++.h>

template <typename... Ts>
void __print(Ts&&... ts) {}
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
using vvvi = vector<vvi>;
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
}

bool last = 0;

pi smallest_brute(int n) {
    for (int k = 1; k < 1000000; k++) {
        int h = __builtin_popcount(k);
        if (n <= h) {
            if (n == h) {
                n = 0;
            }
            return pi{k, n};
        }
        n -= h;
    }
    return pi{n, 0};
}

bool check(vi& res, int n) {
    int sum = 0;
    for (int a : res) {
        sum += __builtin_popcount(a);
    }
    return sum == n;
}

pi bit_pos_and_bits_taken(int n, int k = 0) {
    int curr = k;
    int r = 1;
    int p = 1;
    while (r * p + k * p * 2 < n) {
        curr = r * p + k * p * 2;
        p *= 2;
        r++;
    }
    return pi{r - 1, curr};
}

pi smallest_and_bits_taken(int n) {
    int res = 0;
    int bits_taken = 0;

    int bits_used = 0;
    for (int k = 0; bits_used < n; k++) {
        pi h = bit_pos_and_bits_taken(n - bits_used, k);
        bits_used += h.second;
        if (bits_used >= n) {
            break;
        }
        res += 1 << h.first;
        bits_taken++;
    }
    return pi{res, bits_taken};
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi res;
    int N = n;

    while (n > 0) {
        pi h = smallest_and_bits_taken(n);
        res.push_back(h.first);
        n -= h.second;
    }

    cout << res.size() << endl;
    for (int a : res) {
        cout << a << ' ';
    }
    // int bad = 0;
    // int N = 10000000;
    // constexpr int S = 16;
    // for (int i = 1; i <= N + 1; i++) {
    //     auto [l, h] = smallest_brute(i);
    //     int r = smallest_and_bits_taken(i).first;
    //     if (l != r) {
    //         cout << "i: " << bitset<S>(i) << " l: " << bitset<S>(l)
    //              << " r: " << bitset<S>(r) << " "
    //              << (bitset<S>(l) ^ bitset<S>(r)) << ' ' << h << ' ' << last
    //              << endl;
    //         bad++;
    //     }
    //     last = 0;
    // }
    // cout << "Bad: " << bad << "/" << N << endl;
}