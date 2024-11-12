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
    int n, q;
    cin >> n >> q;

    as = vl(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> as[i + 1];
    }
    
    ps = vi(n + 1, 0);

    for (int i = 0; i < n -1 ; i++)
    {
        cin >> ps[i + 2];
    }
    dph = vi(n + 1, -1);
    dph[1] = 0;
    for (int i = 0; i < n; i++)
    {
        depth(i + 1);
    }

    vpi qs(q);
    
    
    for (int i = 0; i < q; i++)
    {
        int x, y;

        cin >> x >> y;
        qs.push_back({x, y, i});
    }

    sort(all(qs), [](Q& a, Q& b){return dph[a[0]] < dph[b[0]];});

    vi sols(q);

    for(auto [x, y, i] : qs) {
        sols[i] = sol(x, y);
    }

    for(int s : sols) {
        cout << s << endl;
    }
    
    return 0;
}