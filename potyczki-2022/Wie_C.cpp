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
class StateMachine {
    struct Entry {
        int idx;
        double p;

        bool operator<(const Entry& rhs) const { return idx < rhs.idx; }
    };

    vector<vector<Entry>> from_to;
    vector<vector<Entry>> to_from;

   public:
    bool neutral = false;

    void insert(int from, int to, double p) {
        while (from_to.size() <= from) {
            from_to.emplace_back();
        }
        while (to_from.size() <= to) {
            to_from.emplace_back();
        }

        from_to[from].push_back({to, p});
        to_from[to].push_back({from, p});
    }

    void _sort() {
        for (auto& row : from_to) {
            sort(all(row));
        }
        for (auto& col : to_from) {
            sort(all(col));
        }
    }

    StateMachine operator*(const StateMachine& rhs) const {
        if (neutral) {
            return rhs;
        }
        if (rhs.neutral) {
            return *this;
        }

        StateMachine res;

        for (int i = 0; i < from_to.size(); i++) {
            for (int j = 0; j < rhs.to_from.size(); j++) {
                double p = 0;

                for (int k = 0, r = 0; k < from_to[i].size(); ++k) {
                    while (r < rhs.to_from[j].size() &&
                           rhs.to_from[j][r].idx < from_to[i][k].idx) {
                        ++r;
                    }
                    if (r < rhs.to_from[j].size() &&
                        rhs.to_from[j][r].idx == from_to[i][k].idx) {
                        p += from_to[i][k].p * rhs.to_from[j][r].p;
                    }
                }

                if (p > 0) {
                    res.insert(i, j, p);
                }
            }
        }

        res._sort();

        return res;
    }

    StateMachine operator^(int n) const {
        StateMachine res;
        res.neutral = true;
        StateMachine cur = *this;

        while (n > 0) {
            if (n & 1) {
                res = res * cur;
            }
            cur = cur * cur;
            n >>= 1;
        }

        return res;
    }

    double get(int from, int to) const {
        for (auto& e : from_to[from]) {
            if (e.idx == to) {
                return e.p;
            }
        }
        return 0;
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////

using Pos = array<int8_t, 2>;

using State = vec<Pos>;

State board_to_state(vec<string>& board) {
    State res;
    for (int8_t y = 0; y < board.size(); y++) {
        for (int8_t x = 0; x < board[y].size(); x++) {
            if (board[y][x] == 'O') {
                res.push_back({y, x});
            }
        }
    }
    return res;
}

Pos moves[4] = {Pos{0, 1}, Pos{0, -1}, Pos{1, 0}, Pos{-1, 0}};

vec<State> get_next_states(State& from, int rows, int cols) {
    vec<State> res;

    for (int i = 0; i < from.size(); ++i) {
        auto cand = from[i];

        for (auto move : moves) {
            int8_t y = cand[0] + move[0];
            int8_t x = cand[1] + move[1];

            Pos cpy = {y, x};

            if (y < 0 || y >= rows || x < 0 || x >= cols) {
                continue;
            }

            bool cont = false;

            for (auto other : from) {
                if (other == cpy) {
                    cont = true;
                    break;
                }
            }
            if (cont) {
                continue;
            }

            State to = from;
            to[i] = cpy;
            res.push_back(to);
        }
    }

    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int rows, cols;
    cin >> rows >> cols;

    vec<string> board(rows);
    for (string& s : board) {
        cin >> s;
    }

    cin.get();

    vec<string> dest_board(rows);
    for (string& s : dest_board) {
        cin >> s;
    }

    map<State, int> states;

    queue<State> q;
    q.push(board_to_state(board));
    q.push(board_to_state(dest_board));

    states[board_to_state(board)] = 0;
    states[board_to_state(dest_board)] = 1;

    int counter = 2;

    StateMachine sm;

    while (!q.empty() && states.size() < 5000) {
        State cur = q.front();
        q.pop();

        auto next_states = get_next_states(cur, rows, cols);

        for (auto next_state : next_states) {
            bool cont = states.count(next_state);
            if (!cont) {
                states[next_state] = counter++;
            }
            int from = states[cur];
            int to = states[next_state];
            sm.insert(from, to, 1.0 / next_states.size());

            if (cont) continue;

            q.push(next_state);
        }
    }

    sm._sort();

    sm = sm ^ 100000;

    cout << fixed << setprecision(13) << sm.get(0, 1) << endl;
}