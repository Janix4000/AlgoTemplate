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
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;

using pi = pair<int, int>;
using pl = pair<ll, ll>;

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

class Solution {};

using It = vi::iterator;

int sol_2(It beg, It end) {
    int n = end - beg;
    vi min_left(end - beg);
    min_left[0] = *beg;
    for (int i = 1; i < n; i++) {
        min_left[i] = min(min_left[i - 1], *(beg + i));
    }

    vi max_right(end - beg);
    max_right[n - 1] = *(end - 1);
    for (int i = n - 1 - 1; i >= 0; i--) {
        max_right[i] = max(max_right[i + 1], *(beg + i));
    }

    for (int i = 0; i < n - 1; i++) {
        if (min_left[i] >= max_right[i + 1]) {
            return i;
        }
    }
    return -1;
}

int sol_3(It beg, It end) {
    int n = end - beg;
    vi min_left(end - beg);
    min_left[0] = *beg;
    for (int i = 1; i < n; i++) {
        min_left[i] = min(min_left[i - 1], *(beg + i));
    }
    for (int i = 1; i < n; i++) {
        if (min_left[i - 1] >= *(beg + i)) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vi t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    if (k >= 4) {
        set<int> sol;

        for (int i = 0; i < n - 1; i++) {
            if (t[i] >= t[i + 1]) {
                sol.insert(i);
                sol.insert(i + 1);
                if (i > 0) {
                    sol.insert(i - 1);
                }
                break;
            }
        }

        if (sol.empty()) {
            cout << "NIE" << endl;
        } else {
            for (int i = 0; sol.size() < k - 1; i++) {
                sol.insert(i);
            }
            cout << "TAK" << endl;
            for (int i : sol) {
                cout << i + 1 << ' ';
            }
            cout << endl;
        }
    } else if (k == 3) {
        auto max_it = max_element(t.begin(), t.end());
        auto max_i = max_it - t.begin();
        if (max_i != n - 1) {
            cout << "TAK" << endl;
            if (max_i == 0) {
                cout << max_i + 1 << ' ' << max_i + 2 << endl;
            } else {
                cout << max_i << ' ' << max_i + 1 << endl;
            }
        } else {
            int k = sol_3(t.begin(), t.end() - 1);
            if (k == -1) {
                cout << "NIE" << endl;
            } else {
                cout << "TAK" << endl;
                cout << k << ' ' << k + 1 << endl;
            }
        }
    } else if (k == 2) {
        int k = sol_2(t.begin(), t.end());
        if (k == -1) {
            cout << "NIE" << endl;
        } else {
            cout << "TAK" << endl;
            cout << k + 1 << endl;
        }
    }
}