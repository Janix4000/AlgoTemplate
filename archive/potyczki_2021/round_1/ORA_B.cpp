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

// (flags & UART_FLAG_RXNE) || (flags & UART_FLAG_ORE)
// flags & (UART_FLAG_RXNE | UART_FLAG_ORE)

class Solution {};

// (int) 1.4
// int(1.4)
// static_cast<int>(1.4) <=> (int) [float]
// dynamic_cast<int>(1.4) (Foo*) [Goo*] (Foo : Goo)
// reinterpret_cast<int>(1.4) * (int*) &[float]
// const_cast<int>(1.4)

#define N 10
// #define N (5 * int(1e5) + 2)
int tab[N];
int remap[N];

int result(int n, int k) {
    memset(remap, 0xFF, sizeof(int) * n);
    loop(i, n) {
        int a;
        cin >> a;
        tab[i] = a - 1;
    }
    int idx = 0;
    loop(i, n) {
        int a = tab[i];
        if (remap[a] == -1) {
            remap[a] = idx++;
        }
        if (idx == k) {
            break;
        }
    }
    if (idx < k) {
        return -1;
    }
    idx = 0;
    int res = 0;
    loop(i, n) {
        int a = tab[i];
        a = remap[a];
        if (a == idx) {
            res += i - a;
            ++idx;
        }
        // if(idx == k) {
        //     break;
        // }
    }
    return res;
}

void solution() {
    int n, k;
    cin >> n >> k;
    cout << result(n, k);
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