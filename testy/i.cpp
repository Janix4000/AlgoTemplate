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
    int d, sum;
    cin >> d >> sum;
    int minmin = 0, maxmax = 0;
    vi mins(d, 0);
    vi maxs(d, 0);
    for (int i = 0; i < d; i++)
    {
        int a, b;
        cin >> a  >> b;
        mins[i] = a;
        maxs[i] = b;
        minmin+= a;
        maxmax += b;
    }

    if(minmin <= sum && sum <= maxmax) {
        cout << "YES\n";
        for (int i = 0; i < d; i++)
        {
            int from_min = sum - minmin;
            int from_max = maxmax - sum;

            int k = mins[i] + min(maxs[i] - mins[i], from_min);
            cout << k << ' ';
            minmin -= mins[i];
            maxmax -= maxs[i];
            sum -= k;
        }
        

    } else {
        cout <<"NO\n";
    }

    

    
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