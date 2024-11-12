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
    int n;
    cin >> n;

    vector<P> ps(n + 2);
    ps[0] = P{0, 0};
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        ps[i+1] = {i, p};
    }
    ps[n+1] = {n-1, 0};

    vector<P> stack = {ps[0], ps[1]};
    for (int i = 2; i < n+2; i++)
    {
        int k = stack.size();
        auto p0 = stack[k-2];
        auto p1 = stack[k-1];
        auto p2 = ps[i];
        while(cross(p1-p0, p2-p0) > 0) {
            stack.pop_back();
            k--;
            p0 = stack[k-2];
            p1 = stack[k-1];
        }
        stack.push_back(p2);
    }
    int rr = 0;
    for (int i = 0; i < stack.size()-1; i++)
    {
        rr += (stack[i].y + stack[i+1].y) * (stack[i+1].x - stack[i].x);
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