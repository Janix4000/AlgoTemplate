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
using pi = pair<int, int>;
using pl = pair<ll, ll>;

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

class Solution {};

void solution() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        if(n == ((i * (i + 1)) / 2 )) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";

    
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