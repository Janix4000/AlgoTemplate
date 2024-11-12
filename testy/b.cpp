#include <bits/stdc++.h>

template <typename... Ts>
void __print(Ts &&...ts) {}
#ifdef DEBUG
#include "print.hpp"
#endif  // DEBUG

using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) ((int)(x).size())

using ll = long long;
template <typename T>
using vec = vector<T>;


using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

class Solution {};

void solution() {
    int n;
    cin >> n;
    vl as(n, 0);
    for(int i = 0; i < n; ++i ) {
        cin >> as[i];
    }
    
    int m;
    cin >> m;
    vl bs(m, 0);
    for(int i = 0; i < m; ++i ) {
        cin >> bs[i];
    }

    int ia = 0, ib = 0;
    int res = 0;


    while(ia < n && ib < m) {
        if(as[ia] == bs[ib]) {
            ia++;
            ib++;
            res++;
        } else {
            if(as[ia] > bs[ib]) {
                swap(as, bs);
                swap(ia, ib);
                swap(n, m);
            }
            if(ia + 1 < n){
                as[ia + 1] += as[ia];
            }
            ia++;
        }
    }
    if(ia < n || ib < m) {
        res = -1;
    }

    cout << res << endl;

    
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;
    // cin >> qs;

    while (qs--) {
        solution();
    }

    return 0;
}