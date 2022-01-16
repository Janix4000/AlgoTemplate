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
    int n, maxs, mins;
    cin >> n >> maxs >> mins;
    if (maxs + mins > n - 2 || abs(maxs - mins) > 1) {
        cout << "-1\n";
        return;
    }
    if (maxs == 0 && mins == 0) {
        loop(i, n) { cout << i + 1 << ' '; }
        cout << '\n';
        return;
    }

    int pos[] = {1, n};
    vi res;
    int dir = mins >= maxs ? 1 : 0;
    cout << pos[dir] << ' ';
    res.push_back(pos[dir]);
    pos[dir] += -dir * 2 + 1;
    dir = !dir;
    while (maxs || mins) {
        cout << pos[dir] << ' ';
        res.push_back(pos[dir]);
        if (pos[0] == pos[1]) {
            break;
        }
        pos[dir] += -dir * 2 + 1;
        if (dir == 0 && mins) {
            mins--;
            dir = !dir;
        } else if (dir == 1 && maxs) {
            maxs--;
            dir = !dir;
        }
    }
    dir = !dir;
    while (true) {
        cout << pos[dir] << ' ';
        res.push_back(pos[dir]);
        if (pos[0] == pos[1]) {
            break;
        }
        pos[dir] += -dir * 2 + 1;
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

    // Solution solution;
    return 0;
}