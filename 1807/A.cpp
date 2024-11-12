#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
#define all(x) (x).begin(), (x).end()


struct hash_pair final {
    template<class TFirst, class TSecond>
    size_t operator()(const std::pair<TFirst, TSecond>& p) const noexcept {
        uintmax_t hash = std::hash<TFirst>{}(p.first);
        hash <<= sizeof(uintmax_t) * 4;
        hash ^= std::hash<TSecond>{}(p.second);
        return std::hash<uintmax_t>{}(hash);
    }
};

// using pi = pair<int, int>;
using pi = pair<int, int>;

using Q = array<int, 3>;
using vpi = vector<Q>;

vi ps;
vl as;
vi dph;

unordered_map<pi, ll, hash_pair> dp;

int depth(int x) {
    if(dph[x] != 1) return dph[x];
    dph[x] = depth(ps[x]) + 1;
    return dph[x];
}


ll sol(int x, int y) {
    if(x == 0) return 0;

    if(x > y) swap(x, y);
    if(dp.count({x, y}) == 0) {
        dp[{x, y}] = sol(ps[x], ps[y]) +  as[x] * as[y];
    }

    return dp[{x, y}];
}

int main() {
    int t;
    cin >> t;


    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;

        if(a + b == c) {
            cout << "+\n";
        } else {
            cout << "-\n";
        }
    }
    
    return 0;
}