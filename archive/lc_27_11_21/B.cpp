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
    int minimumBuckets(string street) {
        int n = street.size();
        street.insert(n, "H");
        street.insert(0, "H");
        int buckets = 0;
        vi good(n + 2, false);
        good[0] = true;
        good[n + 1] = true;
        for (int i = 1; i <= n + 1; ++i) {
            char c = street[i];
            if (c == '.') {
                if (!good[i - 1]) {
                    buckets++;
                    good[i - 1] = true;
                    good[i + 1] = true;
                }
                good[i] = true;
            } else {
                if (!good[i - 1]) {
                    buckets = -1;
                    break;
                }
                if (!good[i] && street[i + 1] == 'H' && street[i - 1] == '.') {
                    buckets++;
                    good[i] = true;
                }
            }
        }
        return buckets;
    }
};
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    string street = ".HHH.";
    __print(solution.minimumBuckets(street));
    return 0;
}