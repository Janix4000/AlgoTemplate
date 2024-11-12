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

void add_stars(string& s, int k) {
    for (int i = 0; i < k; i++)
    {
        s += '.';
    }
    
}

string get_res(vs& ss) {
    string sol;
    int w = ss[4].size();
    int h = ss[1].size();
    int r = ss[0].size();
    int t = ss[5].size();
    sol.reserve( w*h + 5);
    sol += ss[0]; add_stars(sol, w - r); sol += '\n';
    for (int i = 1; i < t - 1; i++)
    {
        sol += ss[5][i];
        add_stars(sol, r - 2);
        sol += ss[1][i];
        add_stars(sol, w - r);
        sol += '\n';
    }
    sol += ss[4];
    sol += '\n';
    for (size_t i = 1; i < h - t; i++)
    {
        add_stars(sol, r - 1);
        sol += ss[1][i + t - 1];
        add_stars(sol, w - r - 1);
        sol += ss[3][i];
        sol += '\n';
    }
    add_stars(sol, r - 1 );
    sol += ss[2];
    sol += '\n';
    return sol;
}

void solution() {
    string res;
    vs ss(6);
    // vs ss = {
    //     "JJFS",
    //     "SSXXQOFGJUZ",
    //     "ZGPPC",
    //     "PTC",
    //     "IXEJNDOP",
    //     "JYNYFDSGI"
    // };

    for (int i = 0; i < 6; i++)
    {
        cin >> ss[i];
    }
    sort(all(ss));

    do
    {
        if(ss[0].size() + ss[2].size() - 1 != ss[4].size()) {
            continue;
        }
        if(ss[5].size() + ss[3].size() - 1 != ss[1].size()) {
            continue;
        }
        int r = ss[0].size();
        int t = ss[5].size();
        if(
            ss[0].back() != ss[1].front() ||
            ss[1].back() != ss[2].front() ||
            ss[2].back() != ss[3].back() ||
            ss[3].front() != ss[4].back() ||
            ss[4].front() != ss[5].back() ||
            ss[5].front() != ss[0].front() ||
            ss[1][t-1] != ss[4][r-1] 
            
        ) {
            continue;
        }
        auto new_res = get_res(ss);
        if(res.empty() || new_res < res) {
            res = new_res;
        }
    } while (next_permutation(all(ss)));

    if(res.empty()) {
        cout << "Impossible\n";
        return;
    }

    cout << res;

    
    
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