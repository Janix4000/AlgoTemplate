#include <algorithm>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

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

constexpr ll MOD = ll(1e9) + 7;

///////////////////////////////////////////////////////////////////////////////////////////////
struct phi_sieve {
    vector<ll> primes;
    vector<char> is_composite;
    vector<ll> phi;

    phi_sieve(int n) : is_composite(n + 1, false), phi(n + 1) {
        phi[1] = 1;
        for (int k = 2; k < n; ++k) {
            if (!is_composite[k]) {
                primes.push_back(k);
                phi[k] = k - 1;  // k is primes
            }
            for (int i = 0; i < primes.size() && k * primes[i] <= n; ++i) {
                auto prime = primes[i];
                is_composite[k * prime] = true;
                if (k % prime == 0) {
                    phi[k * prime] = phi[k] * prime;  // prime divides k
                    break;
                } else {
                    phi[k * prime] =
                        phi[k] * phi[prime];  // prime does not divide k
                }
            }
        }
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////

class Solution {};

void solution() {
    int n;
    cin >> n;

    auto phi = phi_sieve(n);
    int res = 0;
    loop(c, 1, n + 1) {
        for (int d = 1; d * d <= n - c; ++d) {
            if (n % d != 0) continue;
            int nd = (n - c) / d;
            res = (res + (c * d / __gcd(c, d) * phi.phi[nd])) % MOD;
            res = (res + (c * nd / __gcd(c, nd) * phi.phi[d])) % MOD;
        }
    }
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