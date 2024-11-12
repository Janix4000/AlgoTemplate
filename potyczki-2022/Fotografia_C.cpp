#include <bits/stdc++.h>

#include <cassert>

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

using vpi = vector<pi>;

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

class Solution {};

using It = vi::iterator;

vpi get_swaps_one(vi& t) {
    vpi swaps;
    int n = (int)t.size();
    vi visited(n, 0);
    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;
        vi indexes;
        int j = i;
        int prev = -1;
        while (!visited[j]) {
            visited[j] = 1;
            indexes.push_back(j);
            j = t[j];
        }
        for (int k = 0; k < (indexes.size() - 1) / 2; ++k) {
            int r = indexes.size() - 2 - k;
            swaps.push_back({indexes[k], indexes[r]});
        }
    }
    return swaps;
}

vpi get_swaps_two(vi& t) {
    vpi swaps;
    int n = (int)t.size();
    for (int i = 0; i < n; i++) {
        if (i < t[i]) {
            swaps.push_back({i, t[i]});
        }
    }

    return swaps;
}

vi get_print_swaps(vector<pi>& swaps) {
    vi print_swaps(swaps.size() * 2);
    for (int k = 0; k < swaps.size(); ++k) {
        int i = swaps[k].first, j = swaps[k].second;
        print_swaps[k] = i;
        print_swaps[print_swaps.size() - 1 - k] = j;
    }
    return print_swaps;
}

bool is_swapable(vi& t) {
    int n = (int)t.size();
    for (int i = 0; i < n; i++) {
        if (t[t[i]] != i) {
            return false;
        }
    }
    return true;
}
void print_swaps(vpi& swaps) {
    auto print_swaps = get_print_swaps(swaps);
    cout << print_swaps.size() << endl;
    for (int i : print_swaps) {
        cout << i + 1 << ' ';
    }
    cout << endl;
}

void apply_swaps(vi& t, vpi& swaps) {
    for (pi i_j : swaps) {
        int i = i_j.first, j = i_j.second;
        swap(t[i], t[j]);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    {
        vi idc(n);
        iota(all(idc), 0);
        sort(all(idc), [&](int i, int j) { return t[i] < t[j]; });
        for (int i = 0; i < n; i++) {
            t[idc[i]] = i;
        }
    }

    if (is_sorted(all(t))) {
        cout << 0 << endl;
    } else if (is_swapable(t)) {
        cout << 1 << endl;
        auto swaps = get_swaps_two(t);
        print_swaps(swaps);

        apply_swaps(t, swaps);
    } else {
        cout << 2 << endl;
        auto swaps = get_swaps_one(t);
        print_swaps(swaps);

        apply_swaps(t, swaps);
        swaps = get_swaps_two(t);
        print_swaps(swaps);

        apply_swaps(t, swaps);
    }
}