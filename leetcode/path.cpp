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
    set<int> primes_of(int n) {
        set<int> res;
        while (n % 2 == 0) {
            res.insert(2);
            n /= 2;
        }
        for (int p = 3; p * p <= n; p += 2) {
            while (n % p == 0) {
                res.insert(p);
                n /= p;
            }
        }
        if (n > 1) {
            res.insert(n);
        }
        return res;
    }

    struct fu {
        unordered_map<int, int> par;
        unordered_map<int, int> count;
        int find(int p) {
            if (auto it = par.find(p); it == par.end()) {
                par[p] = p;
                count[p] = 1;
                return p;
            } else {
                if (it->second != p) {
                    it->second = find(it->second);
                }
                return it->second;
            }
        }
        void unio(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) {
                return;
            }
            if (count[x] > count[y]) {
                par[y] = x;
            } else {
                par[x] = y;
                if (count[x] == count[y]) {
                    count[y]++;
                }
            }
        }
        bool has(int p) { return par.find(p) != par.end(); }
    };

   public:
    int largestComponentSize(vector<int>& nums) {
        fu unions;
        if (nums.size() == 1 && nums.front() == 1) {
            return 1;
        }
        vector<int> repr;
        repr.reserve(nums.size());
        for (int n : nums) {
            if (n == 1) {
                continue;
                repr.push_back(n);
            }
            auto primes = primes_of(n);
            int found_p = *primes.begin();
            repr.push_back(found_p);
            for (int p : primes) {
                unions.unio(found_p, p);
            }
        }
        unordered_map<int, int> counter;
        for (int r : repr) {
            int par = unions.find(r);
            counter[par]++;
        }
        return max_element(all(counter),
                           [](auto& a, auto& b) { return a.second < b.second; })
            ->second;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    vi nums = {99, 100, 69, 39, 14, 56, 91, 60};
    __print(solution.largestComponentSize(nums));
    return 0;
}