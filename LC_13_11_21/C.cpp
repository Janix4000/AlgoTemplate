#include <bits/stdc++.h>

template <typename... Ts>
void __print(Ts &&...ts) {}
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

#define all(x) x.begin(), x.end()

class Solution {
   public:
    int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills,
                      int strength) {
        int n = workers.size();
        int m = tasks.size();
        sort(all(workers));
        sort(all(tasks));
        int k = min(m, n);
        int lb = 1, ub = k + 1;
        while (ub - lb > 1) {
            int mid = lb + (ub - lb) / 2;
            int tasks_left = mid;
            int pills_left = pills;
            multiset<int> workers_left(all(workers));

            for (int i = mid - 1; i >= 0; --i) {
                int task = tasks[i];
                if (auto it = next(workers_left.end(), -1); *it >= task) {
                    workers_left.erase(it);
                    tasks_left--;
                } else if (auto it = workers_left.lower_bound(task - strength);
                           it != workers_left.end() && pills_left) {
                    workers_left.erase(it);
                    tasks_left--;
                    pills_left--;
                } else {
                    break;
                }
            }
            if (tasks_left) {
                ub = mid;
            } else {
                lb = mid;
            }
        }
        return lb;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;
    vi tasks = {5, 9, 8, 5, 9};
    vi workers = {1, 6, 4, 2, 6};

    int pills = 1;
    int strength = 5;
    Solution solution;
    __print(solution.maxTaskAssign(tasks, workers, pills, strength));
    return 0;
}