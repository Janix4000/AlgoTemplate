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

struct P {
    int x, y;
    P operator-(const P& p) const {
        return {x - p.x, y - p.y};
    }
};

int cross(P a, P b) {
    return a.x * b.y - a.y * b.x;

}

void solution() {
    string s;
    cin >> s;
    int n = s.size();
    int rr = 0;
    for (int i = 0; i < n - 3; i++)
    {
        if(s.substr(i, 4) != "ania") continue;
        int c = 1;
        int j = i + 3;
        for (; j < n - 3; j += 3)
        {
            if(s.substr(j, 4) != "ania") break;
            c++;
        }
        rr += max(1, c - 1);
        i = j - 1; // i++;
    }
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