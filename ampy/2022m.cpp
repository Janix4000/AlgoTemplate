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
   int n, k; cin >> n >> k;
   vi ks(k), ds(k);
   for (size_t i = 0; i < k; i++)
   {
        cin >> ks[i] >> ds[i];
        ks[i]--; ds[i]--;
   }
   int s; cin >> s;
   vi ws(n, 0);
    for (size_t i = 0; i < s; i++)
    {
        int a;
        cin >> a;   
        ws[a-1] = 1;
    }
    string rr; 
    for (int i = k - 1; i >= 0; i--)
    {
        if(ws[ks[i]]) {
            rr += 'N';
            continue;
        }
        if(!ws[ds[i]]) {
            rr += 'N';
            continue;
        }
        rr += 'T';
        ws[ds[i]] = 0;
    }

    if(any_of(all(ws), [](int i){return bool(i); })) {
        cout << "NIE" << endl;
        return;
    }

    cout << "TAK" << endl;
    reverse(all(rr));
    cout << rr << endl;
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