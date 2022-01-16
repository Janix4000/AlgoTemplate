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
using vpi = vec<pi>;

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
   public:
    int minCost(vector<int>& startPos, vector<int>& homePos,
                vector<int>& rowCosts, vector<int>& colCosts) {
        int rows = rowCosts.size();
        int cols = colCosts.size();
        int y_start = startPos[0];
        int x_start = startPos[1];
        int y_home = homePos[0];
        int x_home = homePos[1];
        if (y_start > y_home) {
            reverse(all(rowCosts));
            y_start = rows - y_start - 1;
            y_home = rows - y_home - 1;
        }
        if (x_start > x_home) {
            reverse(all(colCosts));
            x_start = cols - x_start - 1;
            x_home = cols - x_home - 1;
        }
        int res = 0;
        res += accumulate(rowCosts.begin() + y_start + 1,
                          rowCosts.begin() + y_home + 1, 0);
        res += accumulate(colCosts.begin() + x_start + 1,
                          colCosts.begin() + x_home + 1, 0);
        return res;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    vi startPos = {1, 0};
    vi homePos = {2, 3};
    vi rowCosts = {5, 4, 3};
    vi colCosts = {8, 2, 6, 7};
    __print(solution.minCost(startPos, homePos, rowCosts, colCosts));
    return 0;
}