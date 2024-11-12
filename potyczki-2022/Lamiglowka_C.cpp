#include <bits/stdc++.h>

#include <cassert>

template <typename... Ts>
void __print(Ts&&... ts) {}
#ifdef DEBUG
#include "print.hpp"
#endif  // DEBUG

using namespace std;

template <class T>
using pq_max = priority_queue<T>;
template <class T>
using pq_min = priority_queue<T, vector<T>, greater<T>>;

#define FOR(i, a, b) for (int i = a; i < (b); ++i)
#define F0R(i, a) for (int i = 0; i < (a); ++i)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; --i)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; --i)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define all(x) x.begin(), x.end()

#define GET_FOR(_1, _2, _3, NAME, ...) NAME
#define loop(...) GET_FOR(__VA_ARGS__, FOR, F0R)(__VA_ARGS__)

#define GET_FORd(_1, _2, _3, NAME, ...) NAME
#define loopr(...) GET_FOR(__VA_ARGS__, FORd, F0Rd)(__VA_ARGS__)

#define sz(x) ((int)(x).size())

using ll = long long;
template <typename T>
using vec = vector<T>;
template <typename T, size_t N>
using arr = array<T, N>;

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;

using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vpi = vector<pi>;

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

constexpr int N = 4;
constexpr int CYCLE = N * 100;

constexpr int L = 0;
constexpr int R = 2;
constexpr int M = 1;
constexpr int U = 0;
constexpr int D = 2;

pi get_new_pos(char move, pi pos) {
    switch (move) {
        case 'L':
            return {pos.first, L};
        case 'P':
            return {pos.first, R};
        case 'G':
            return {U, pos.second};
        case 'D':
            return {D, pos.second};
    }
    return {M, M};
}

int get_new_rotation(char move, int rot, pi old_pos) {
    int diff = 0;

    switch (move) {
        case 'L':
            if (old_pos.second == L) {
                diff = 0;
            } else if (old_pos.first == U) {
                diff = -1;
            } else if (old_pos.first == D) {
                diff = +1;
            }
            break;
        case 'G':
            if (old_pos.first == U) {
                diff = 0;
            } else if (old_pos.second == L) {
                diff = +1;
            } else if (old_pos.second == R) {
                diff = -1;
            }

            break;
        case 'P':
            if (old_pos.second == R) {
                diff = 0;
            } else if (old_pos.first == U) {
                diff = +1;
            } else if (old_pos.first == D) {
                diff = -1;
            }
            break;
        case 'D':
            if (old_pos.first == D) {
                diff = 0;
            } else if (old_pos.second == L) {
                diff = -1;
            } else if (old_pos.second == R) {
                diff = +1;
            }
            break;
    }
    return (rot + CYCLE + diff) % CYCLE;
}

void move_right(vec<string>& rows) {
    int height = rows.size();
    int width = rows[0].size();
    for (int i = height - 1; i >= 0; i--) {
        int free = width - 1;
        for (int j = width - 1; j >= 0; j--) {
            if (rows[i][j] != '.') {
                swap(rows[i][j], rows[i][free]);
                free--;
            }
        }
    }
}

void move_left(vec<string>& rows) {
    for (auto& row : rows) {
        reverse(all(row));
    }
    move_right(rows);
    for (auto& row : rows) {
        reverse(all(row));
    }
}

void move_down(vec<string>& rows) {
    int height = rows.size();
    int width = rows[0].size();
    for (int j = width - 1; j >= 0; j--) {
        int free = height - 1;
        for (int i = height - 1; i >= 0; i--) {
            if (rows[i][j] != '.') {
                swap(rows[i][j], rows[free][j]);
                free--;
            }
        }
    }
}

void move_up(vec<string>& rows) {
    reverse(all(rows));
    move_down(rows);
    reverse(all(rows));
}

void print_rows(vec<string>& rows) {
    for (auto& row : rows) {
        cout << row << endl;
    }
    cout << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int width, height;

    cin >> height >> width;

    vec<string> rows(height);
    for (int i = 0; i < height; i++) {
        cin >> rows[i];
    }

    int positions[CYCLE / N][3]
                 [3];  // = {{{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
                       //   {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
                       //   {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}}};

    for (auto& a : positions) {
        for (auto& b : a) {
            for (auto& c : b) {
                c = -1;
            }
        }
    }

    int n;
    cin >> n;
    string moves;

    string all_moves;

    vpi poses;
    vi rotations;
    int rotation = 0;
    pi pos = {M, M};
    for (int i = 0; i < n; i++) {
        char move;
        cin >> move;
        all_moves += move;
        auto new_pos = get_new_pos(move, pos);
        auto new_rotation = get_new_rotation(move, rotation, pos);
        int idx = positions[new_rotation / 4][new_pos.first][new_pos.second];
        if (idx == -1) {
            poses.push_back(new_pos);
            rotations.push_back(new_rotation);

            positions[new_rotation / 4][new_pos.first][new_pos.second] =
                poses.size() - 1;

            moves += move;
        } else {
            while (poses.size() > idx + 1) {
                positions[rotations.back() / 4][poses.back().first]
                         [poses.back().second] = -1;
                poses.pop_back();
                rotations.pop_back();
            }
            new_pos = poses[idx];
            new_rotation = rotations[idx];
            moves.resize(idx + 1);
        }
        pos = new_pos;
        rotation = new_rotation;
    }

    auto copy_rows = rows;

    for (char move : moves) {
        switch (move) {
            case 'L':
                move_left(rows);
                break;
            case 'P':
                move_right(rows);
                break;
            case 'G':
                move_up(rows);
                break;
            case 'D':
                move_down(rows);
                break;
        }
    }

    print_rows(rows);
}