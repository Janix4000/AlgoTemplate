#include <bits/stdc++.h>

template <typename... Ts>
void __print(Ts &&...ts) {}
#ifdef DEBUG
#include "print.hpp"
#endif  // DEBUG

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

template <typename T>
using vec = vector<T>;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T>
using pq_max = priority_queue<T>;
template <class T>
using pq_min = priority_queue<T, vector<T>, greater<T>>;

#define FOR(i, a, b) for (int i = a; i < (b); ++i)
#define F0R(i, a) for (int i = 0; i < (a); ++i)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; --i)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; --i)
#define trav(a, x) for (auto &a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

#define IN(n) \
    int n;    \
    cin >> n;

#define all(x) x.begin(), x.end()

template <class T>
bool ckmin(T &a, const T &b) {
    return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
    return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
T max(T a, T b, T c) {
    return max(max(a, b), c);
}
template <typename T, typename... Ts>
T max(T a, Ts... as) {
    return max(a, max(as...));
}
template <typename T>
T min(T a, T b, T c) {
    return min(min(a, b), c);
}
template <typename T, typename... Ts>
T min(T a, Ts... as) {
    return min(a, min(as...));
}
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

class Robot {
   public:
    int x = 0, y = 0;
    int width, height;
    string dir = "East";
    bool first = true;
    map<string, pi> mvs = {
        {"East", {1, 0}},
        {"West", {-1, 0}},
        {"North", {0, 1}},
        {"South", {0, -1}},
    };
    map<string, string> nxtDir = {
        {"East", "North"},
        {"North", "West"},
        {"West", "South"},
        {"South", "East"},
    };
    Robot(int width, int height) : width(width), height(height) {}

    bool canMove(int x_mv, int y_mv) {
        int x = this->x + x_mv;
        int y = this->y + y_mv;
        return x >= 0 && x < width && y >= 0 && y < height;
    }

    void move(int num) {
        first = false;
        num = num % (2 * width + 2 * height - 4);
        auto [x_mv, y_mv] = mvs.at(dir);
        while (canMove(x_mv, y_mv) && num) {
            x += x_mv;
            y += y_mv;
            num--;
        }
        if (num) {
            this->dir = nxtDir.at(dir);
            move(num);
        }
    }

    vector<int> getPos() { return {x, y}; }

    string getDir() {
        if (x == 0 && y == 0 && !first) {
            dir = "South";
        }
        return dir;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}