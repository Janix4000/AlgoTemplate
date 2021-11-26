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
    int n, s;
    cin >> n >> s;
    vi sc(n);
    loop(i, n) { cin >> sc[i]; }
    int sum = s;
    int l = 0, r = 0;
    int beg = 0, end = 0;
    for (; r < n; ++r) {
        sum += sc[r];
        if (sum < 0) {
            if (r - l > end - beg) {
                beg = l;
                end = r;
            }
            while (sum < 0 && l < n) {
                sum -= sc[l];
                l++;
            }
        }
    }
    if (r - l > end - beg && sum >= 0) {
        beg = l;
        end = r;
    }
    if (beg == end) {
        cout << "-1\n";
    } else {
        cout << beg + 1 << ' ' << end << '\n';
    }
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