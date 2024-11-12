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

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////



void solution() {
    int n, m; cin >> n >> m;
    vs rows(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> rows[i];
    }
    vs path(n, string(m, 'B'));
    path[n-1][m-1] = 'E';
    for (int y = n - 1; y >= 0; y--)
    {
        for (int x = m - 1; x >= 0; x--)
        {
            if(x == m-1 && y == n-1) continue;
            if(rows[y][x] == '#') continue;
            if(x != m-1 && path[y][x+1] != 'B') {
                path[y][x] = 'P';
            }
            if(y != n-1 && path[y+1][x] != 'B') {
                path[y][x] = 'D';
            }
        }
    }
    if(path[0][0] == 'B') {
        cout << "NIE" << endl;
        return;
    }
    vvi flipped(2, vi(max(n, m), 0));
    int dir = path[0][0] == 'D' ? 0 : 1;
    int y = 0, x = 0;
    string sol;
    while(true) {
        int a_dir = 1 - dir;
        int a_k = a_dir == 0 ? y : x;
        int k = dir == 0 ? y : x;
        if(rows[y][x] == 'O' && flipped[a_dir][a_k]) {
            flipped[dir][k] = 1;
        } else if(rows[y][x] == '@' && !flipped[a_dir][a_k]) {
            flipped[dir][k] = 1;
        }
        if(path[y][x] == 'E') break;
        sol += path[y][x];
        dir = path[y][x] == 'D' ? 0 : 1;
        if(path[y][x] == 'P') {
            x++;
        } else {
            y++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << (flipped[0][i] ? "T" : "N");
    }
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        cout << (flipped[1][i] ? "T" : "N");
    }
    cout << endl;
    cout << sol;
    cout << endl;
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