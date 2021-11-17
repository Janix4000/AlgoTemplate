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
#define trav(a, x) for (auto &a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

#define IN(n) \
    int n;    \
    cin >> n;

template <class T>
bool ckmin(T &a, const T &b) {
    return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
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

#define all(x) x.begin(), x.end()

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
   public:
    int minimumOperations(vector<int> &nums, int start, int goal) {
        const int INF = int(1e3) + 10;
        int dp[1001];
        fill(dp, dp + 1001, INF);
        dp[start] = 0;
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int e = q.front();
            q.pop();
            for (int el : nums) {
                array<int, 3> qs = {e + el, e - el, e ^ el};
                for (int k : qs) {
                    if (k < 0 || k > 1000) {
                        continue;
                    }
                    if (dp[e] + 1 < dp[k]) {
                        dp[k] = dp[e] + 1;
                        q.push(k);
                    }
                }
            }
        }

        int best = INF;

        if (goal < 0 || goal > 1000) {
            for (int el : nums) {
                array<int, 3> qs = {goal + el, goal - el, goal ^ el};
                for (int k : qs) {
                    if (k < 0 || k > 1000) {
                        continue;
                    }
                    best = min(best, dp[k] + 1);
                }
            }
        } else {
            best = dp[goal];
        }
        if (best == INF) {
            best = -1;
        }
        return best;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    vi nums = {3, 5, 7};
    int start = 0;
    int goal = -4;
    __print(solution.minimumOperations(nums, start, goal));

    return 0;
}