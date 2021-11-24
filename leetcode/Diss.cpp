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
#define all(x) (x).begin(), (x).end()

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int a : nums) {
            nums[a-1] = (nums[a-1] > 0 ? -nums[a-1] : nums[a-1]);
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] > 0) {
                nums[i] = i + 1;
            } else {
                nums[i] = -1;
            }
        }
        auto it = remove(nums.begin(), nums.end(), -1);
        nums.erase(it, nums.end());
        return nums;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    vi nums = {4,3,2,7,8,2,3,1};
    __print(solution.findDisappearedNumbers(nums));
    return 0;
}