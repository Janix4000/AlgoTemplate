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

// using ll = long long;
// template <typename T>
// using vec = vector<T>;
// template <typename T, size_t N>
// using arr = array<T, N>;

// using vi = vector<int>;
// using vvi = vector<vi>;
// using vl = vector<ll>;
// using vvl = vector<vl>;

// using pi = pair<int, int>;
// using pl = pair<ll, ll>;

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

using ll = int;

ll _dp[5];
ll _row[5];

ll INF = 200 * 1000 + 10;

class Solution {
   public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        int cols = dungeon.front().size();
        int* dp = _dp;
        int* row = _row;

        memset(dp, INF, cols * sizeof *dp);
        dp[cols - 1] = 1;
        for (int y = rows - 1; y >= 0; --y) {
            memset(row, INF, cols * sizeof *row);
            for (int x = cols - 1; x >= 1; --x) {
                ll cand = dp[x] > dungeon[y][x] ? dp[x] - dungeon[y][x] : 1;
                row[x] = min(row[x], cand);
                dp[x - 1] = min(dp[x - 1], cand);
            }
            row[0] = min(row[0], max(dp[0] - dungeon[y][0], 1));
            swap(row, dp);
        }
        return dp[0];
    }
};

void solution() {
    int n;
    cin >> n;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;
    // cin >> qs;

    // while (qs--) {
    //     solution();
    // }

    Solution solution;
    //[[-3],[-7]]
    vector<vector<int>> dungeon = {{-3}, {-7}};
    solution.calculateMinimumHP(dungeon);
    return 0;
}