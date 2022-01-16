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

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
   public:
    int countP(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid.front().size();
        vvi dp(rows, vi(cols, 0));
        for (int y = rows - 2; y >= 0; --y) {
            for (int x = 1; x < cols - 1; ++x) {
                if (grid[y][x] && grid[y + 1][x] && grid[y + 1][x + 1] &&
                    grid[y + 1][x - 1]) {
                    dp[y][x] = 1 + min({dp[y + 1][x], dp[y + 1][x + 1],
                                        dp[y + 1][x - 1]});
                }
            }
        }
        int res = 0;
        for (auto& row : dp) {
            res += accumulate(all(row), 0);
        }
        return res;
    }
    int countPyramids(vector<vector<int>>& grid) {
        int res = countP(grid);
        reverse(all(grid));
        return res + countP(grid);
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vvi grid = {{0, 1, 1, 0}, {1, 1, 1, 1}};
    // vvi grid = {{1, 1, 1, 1, 0}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {0, 1, 0,
    // 0, 1}};

    Solution solution;
    __print(solution.countPyramids(grid));
    return 0;
}