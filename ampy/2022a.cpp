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


int get_c(vs &fns, vs& lns, int a, int b) {
    int n = fns.size();
    vs nicks(n);
    for (size_t i = 0; i < fns.size(); i++)
    {
        nicks[i] = fns[i].substr(0, a) + lns[i].substr(0, b);
    }
    map<string, int> cs;
    for(const string& s : nicks) {
        cs[s]++;
    }
    int rr = 0;
    for(auto& [s, k] : cs) {
        rr = max(rr, k);
    }
    if(rr == 0) return 0;
    return ceil(log10(rr));
}

void solution() {
   int n;
   cin >> n;
   vs fns(n), lns(n);
   for (size_t i = 0; i < n; i++)
   {
        cin >> fns[i] >> lns[i];
   }


   int brr = 20;
   int ba, bb, bc;
   for (int a = 0; a < 6; a++)
   {
    for (int b = 0; b < 6; b++)
    {
        if(a + b > 5) continue;
        int c = get_c(fns, lns, a, b);
        int rr = a + b + c;
        if(rr < brr) {
            brr = rr;
            ba = a;
            bb = b;
            bc = c;
        }
    }
   }
   cout << ba << ' ' << bb << ' ' << bc << endl;


   
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