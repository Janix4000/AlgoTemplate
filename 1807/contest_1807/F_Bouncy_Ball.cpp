#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
#define all(x) (x).begin(), (x).end()
using pi = pair<int, int>;

template <typename T>
int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

enum Dir { DR, DL, UR, UL };

enum Wals { UP, LEFT, DOWN, RIGHT };

vi visited_wall_at_dir[4][4];

bool will_hit(int y_from, int x_from, int y_to, int x_to, pi dir) {
    auto [dy, dx] = dir;

    int diff_y = y_to - y_from;
    int diff_x = x_to - x_from;

    if (diff_x == 0 & diff_y == 0) {
        return true;
    }

    if (sgn(diff_x) != dx || sgn(diff_y) != dy) {
        return false;
    }

    if (abs(diff_x) != abs(diff_y)) {
        return false;
    }

    return true;
}

/// pos, dir
pair<pi, pi> next_hit(int y, int x, int rows, int cols, pi dir) {
    auto [dy, dx] = dir;

    int diff_y, diff_x;

    if (dx > 0) {
        diff_x = (cols - x) - 1;
    } else {
        diff_x = x;
    }

    if (dy > 0) {
        diff_y = (rows - y) - 1;
    } else {
        diff_y = y;
    }

    int diff = min(abs(diff_x), abs(diff_y));

    x += dx * diff;
    y += dy * diff;

    if (x == 0 || x == cols - 1) {
        dx = dx * -1;
    }
    if (y == 0 || y == rows - 1) {
        dy = dy * -1;
    }

    return {{y, x}, {dy, dx}};
}

int get_idx(pi dir) {
    if (dir == pi{-1, -1}) {
        return 0;
    }
    if (dir == pi{+1, -1}) {
        return 1;
    }
    if (dir == pi{-1, +1}) {
        return 2;
    }
    if (dir == pi{+1, +1}) {
        return 3;
    }
    return -1;
}


int main() {
    int t;
    cin >> t;

    while (t--) {
        int rows, cols;

        cin >> rows >> cols;

        int y, x, y_dest, x_dest;

        cin >> y >> x >> y_dest >> x_dest;
        y--, x--, y_dest--, x_dest--;

        string dir_s;

        cin >> dir_s;

        pi dir;
        if (dir_s == "DR") {
            dir = {1, 1};
        } else if (dir_s == "DL") {
            dir = {1, -1};
        } else if (dir_s == "UR") {
            dir = {-1, 1};
        } else if (dir_s == "UL") {
            dir = {-1, -1};
        }

        for (int i = 0; i < 4; i++) {
            visited_wall_at_dir[UP][i] = vi(cols, 0);
        }
        for (int i = 0; i < 4; i++) {
            visited_wall_at_dir[DOWN][i] = vi(cols, 0);
        }
        for (int i = 0; i < 4; i++) {
            visited_wall_at_dir[LEFT][i] = vi(rows, 0);
        }
        for (int i = 0; i < 4; i++) {
            visited_wall_at_dir[RIGHT][i] = vi(rows, 0);
        }

        int sol = 0;

        while (true) {
            if (will_hit(y, x, y_dest, x_dest, dir)) {
                break;
            }
            auto [next_pos, next_dir] = next_hit(y, x, rows, cols, dir);

            y = next_pos.first;
            x = next_pos.second;
            dir = next_dir;

            int idx = get_idx(dir);

            if (y == 0) {
                if (visited_wall_at_dir[UP][idx][x]) {
                    sol = -1;
                    break;
                }
                visited_wall_at_dir[UP][idx][x] = 1;
            }
            if (x == 0) {
                if (visited_wall_at_dir[LEFT][idx][y]) {
                    sol = -1;
                    break;
                }
                visited_wall_at_dir[LEFT][idx][y] = 1;
            }
            if (y == rows - 1) {
                if (visited_wall_at_dir[DOWN][idx][x]) {
                    sol = -1;
                    break;
                }
                visited_wall_at_dir[DOWN][idx][x] = 1;
            }
            if (x == cols - 1) {
                if (visited_wall_at_dir[RIGHT][idx][y]) {
                    sol = -1;
                    break;
                }
                visited_wall_at_dir[RIGHT][idx][y] = 1;
            }

            sol++;
        }

        cout << sol << endl;
    }

    return 0;
}