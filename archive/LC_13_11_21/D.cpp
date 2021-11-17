#include <bits/stdc++.h>

template <typename... Ts>
void __print(Ts&&... ts) {}
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
#define trav(a, x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

#define IN(n) \
    int n;    \
    cin >> n;

#define all(x) x.begin(), x.end()

template <class T>
bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
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

class Solution {
   public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        sort(all(items));
        vector<int> sol;
        sol.reserve(queries.size());
        vector<int> bestItem(items.size());
        bestItem[0] = items[0][1];
        for (int i = 1; i < items.size(); i++) {
            bestItem[i] = max(items[i][1], bestItem[i - 1]);
        }
        for (int q : queries) {
            vector<int> qs = {q};
            auto it = upper_bound(all(items), qs,
                                  [](auto& a, auto& q) { return a[0] < q[0]; });

            if (it == items.begin()) {
                sol.push_back(-1);
            } else {
                --it;
                sol.push_back(bestItem[it - items.begin()]);
            }
        }
        return sol;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;
    // cin >> qs;

    Solution s;

    // [[1,2],[3,2],[2,4],[5,6],[3,5]]
    // [1,2,3,4,5,6]

    vvi items = {{193, 732}, {781, 962}, {864, 954}, {749, 627}, {136, 746},
                 {478, 548}, {640, 908}, {210, 799}, {567, 715}, {914, 388},
                 {487, 853}, {533, 554}, {247, 919}, {958, 150}, {193, 523},
                 {176, 656}, {395, 469}, {763, 821}, {542, 946}, {701, 676}};

    vi queries = {885, 1445, 1580, 1309, 205,  1788, 1214, 1404, 572, 1170,
                  989, 265,  153,  151,  1479, 1180, 875,  276,  1584};

    __print(s.maximumBeauty(items, queries));

    // while (qs--) {
    //     solution();
    // }
    return 0;
}