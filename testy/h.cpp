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
using vs = vector<string>;

using pi = pair<int, int>;
using pl = pair<ll, ll>;

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

class Solution {};



void solution() {
    double l3, l4, l5;
    cin >> l3 >> l4 >> l5;

    double v3 = sqrt(2) / 12 * l3;


    // double H4 = sqrt(l4 * l4 / 2);
    double v4 = l4 * l4 * l4 * sqrt(2) / 2. / 3.;


    double h5 = l5 / 2 / tan(M_PI / 5);
    double L5 = l5 / 2 / sin(M_PI / 5);
    double H5 = sqrt(l5 * l5 - L5 * L5);

    double phi = M_PI / 5;

    // double v5 = 5 * l5 * h5 / 2 * H5 /3;
    double v5 = 5. / 12. * sqrt(1. - 1. / (4. * pow(sin(phi), 2))) / tan(phi) * l5 * l5 * l5;

    cout  << v3 + v4 + v5;
    
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