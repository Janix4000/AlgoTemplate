#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, b) FOR(i, 0, b)
#define all(x) (x).begin(), (x).end
using ll = long long;

template <typename T>
using vec = vector<T>;
using vi = vec<ll>;
using pii = pair<int, int>;

struct solution {
    string grid[10];
    int n, m, q;
    int x_shift = 0, y_shift = 0;
    solution() {
        cin >> n >> m >> q;
        F0R(i, n) { cin >> grid[i]; }

        string path;
        cin >> path;

        bool sol = false;

        map<char, pii> mvs = {
            {'N', {0, -1}},
            {'S', {0, 1}},
            {'W', {-1, 0}},
            {'E', {1, 0}},
        };

        for (char c : path) {
            auto mv = mvs[c];
            int x_mv = mv.first, y_mv = mv.second;
            while (canGo(x_mv, y_mv)) {
                x_shift += x_mv;
                y_shift += y_mv;
                if (y_shift < -n || y_shift > n || x_shift < -m ||
                    x_shift > m) {
                    sol = true;
                    break;
                }
            }
        }

        if (sol) {
            cout << "TAK\n";
        } else {
            cout << "NIE\n";
        }
    }

    bool canGo(int x_mv, int y_mv) {
        for (int y = max(0, y_shift + y_mv); y < min(n, n + y_shift + y_mv);
             ++y) {
            for (int x = max(0, x_shift + x_mv); x < min(n, n + x_shift + x_mv);
                 ++x) {
                if (grid[y][x] == 'A' &&
                    grid[y - y_shift - y_mv][x - x_shift - x_mv] == 'B') {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;  //
    cin >> qs;

    while (qs--) {
        solution();
    }
}