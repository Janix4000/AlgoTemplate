#include <bits/stdc++.h>

template <typename... Ts>
void __print(Ts &&...ts) {}
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
#define trav(a, x) for (auto &a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

#define IN(n) \
    int n;    \
    cin >> n;

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

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

int sgn(int a) { return a < 0 ? -1 : (a > 0 ? 1 : 0); }

class MKAverage {
   public:
    int m, k;
    int n = 0;
    int sum = 0;

    array<multiset<int>, 3> sets;
    queue<int> order;

    MKAverage(int m, int k) : m(m), k(k) {}

    void addElement(int num) {
        auto &[a, b, c] = sets;
        order.push(num);
        while (sz(a) + sz(b) + sz(c) >= m) {
            int el = order.front();
            for (auto &s : sets) {
                if (auto it = s.find(el); it != s.end()) {
                    s.erase(it);
                    if (&s == &b) {
                        sum -= *it;
                    }
                }
            }
            order.pop();
        }

        if (b.empty() || num < *b.begin()) {
            a.insert(num);
        } else if (c.empty() || num < *c.begin()) {
            b.insert(num);
            sum += num;
        } else {
            c.insert(num);
        }

        while (sz(a) > k) {
            auto it = next(a.end(), -1);
            b.insert(*it);
            sum += *it;
            a.erase(it);
        }
        while (sz(c) > k) {
            auto it = c.begin();
            b.insert(*it);
            sum += *it;
            c.erase(it);
        }
        while (sz(b) > m - 2 * k) {
            auto it = b.begin();
            if (sz(a) < k) {
                a.insert(*it);
            } else {
                it = next(b.end(), -1);
                c.insert(*it);
            }
            sum -= *it;
            b.erase(it);
        }
    }

    int calculateMKAverage() {
        auto &[a, b, c] = sets;
        if (a.size() + b.size() + c.size() < m) {
            return -1;
        } else {
            return sum / (m - 2 * k);
        }
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // ["MKAverage","addElement","addElement","calculateMKAverage","addElement","addElement","calculateMKAverage","addElement","addElement","calculateMKAverage","addElement"]
    // [[3,1],[3],[51],[],[56],[79],[],[99],[0],[],[91]]
    int m = 3, k = 1;

    MKAverage *obj = new MKAverage(m, k);
    obj->addElement(3);
    obj->addElement(1);
    __print(obj->calculateMKAverage());
    obj->addElement(10);
    __print(obj->calculateMKAverage());
    obj->addElement(5);
    obj->addElement(5);
    obj->addElement(5);
    __print(obj->calculateMKAverage());

    return 0;
}