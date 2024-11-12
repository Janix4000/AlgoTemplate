#include <bits/stdc++.h>

#include <vector>

template <typename... Ts>
void __print(Ts &&...ts) {}
#ifdef DEBUG
#include "print.hpp"
#endif  // DEBUG

using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) ((int)(x).size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

using vs = vector<string>;
using vvs = vector<vs>;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vpi = vector<pi>;

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

void solution() {
    int n, m;
    cin >> n >> m;
    vpi ss(n);
    vpi ends(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> ss[i].first >> ss[i].second;
    }

    sort(all(ss));
    for (size_t i = 0; i < n; i++)
    {
        ends[i].first = ss[i].second;
        ends[i].second = i;
    }
    
    sort(all(ends));

    set<int> ps;
    for(auto [a, b] : ss) {
        ps.insert(a);
        ps.insert(b);
    }

    int n_in = 0;

    int k = 0, r = 0;
    int left = 0, right = 0;
    int res = 0;
    for (int i : ps)
    {
        while(k < n && ends[k].first < i) {
            n_in--;
            if(1 == ss[ends[k].second].first) {
                left--;
            }
            if(ends[k].first == m) {
                right--;
            }
            k++;
        }

        while(r < n && ss[r].first <= i) {
            n_in++;
            if(1 == ss[r].first) {
                left++;
            }
            if(ss[r].second == m) {
                right++;
            }
            r++;
        }

        res = max(
            res, 
            max(n_in - left, n_in - right)
        );
    }

    cout << res << endl;
    

    
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;
    cin >> qs;

    while (qs--) {
        solution();
    }
    return 0;
}