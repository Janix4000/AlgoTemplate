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

class Solution {
   public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = sz(security);

        vi decr(n, 1);
        loop(i, 1, n) {
            if (security[i - 1] >= security[i]) {
                decr[i] += decr[i - 1];
            }
        }

        vi incr(n, 1);
        loopr(i, 0, n - 1) {
            if (security[i] <= security[i + 1]) {
                incr[i] += incr[i + 1];
            }
        }

        vi res;
        loop(i, time, n - time) {
            if (decr[i] > time && incr[i] > time) {
                res.push_back(i);
            }
        }
        return res;
    }
};
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    vi security = {1,2,3,4,5,6};
    int time = 2;
    __print(solution.goodDaysToRobBank(security, time));
    return 0;
}