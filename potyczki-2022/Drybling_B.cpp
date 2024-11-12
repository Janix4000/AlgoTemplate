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

constexpr int P = int(1e9) + 7;

struct Cache {
    Cache() {
        pot_l[1] = 1;
        fill(all(pot_p), 0);
        fill(all(pot_p), 0);
    }

    array<int, 1210> pot_l;
    array<int, 1210> pot_p;
    int sol = 0;
    int len = 2;

    Cache(const string& s) : Cache() {
        auto rhs = get_perfect_drybls(s);
        pot_l = rhs.pot_l;
        pot_p = rhs.pot_p;
        sol = rhs.sol;
        len = rhs.len;
    }

    static Cache get_perfect_drybls(const string& s, Cache cache = Cache()) {
        for (char c : s) {
            if (c == 'L') {
                for (int i = 1; i <= cache.len; i++) {
                    cache.pot_p[i - 1] =
                        (cache.pot_p[i - 1] + cache.pot_l[i]) % P;
                }
                int N = cache.pot_l.size();

                cache.len++;
                rotate(cache.pot_l.rbegin() + N - cache.len,
                       cache.pot_l.rbegin() + N - cache.len + 1,
                       cache.pot_l.rend());
                cache.pot_l.front() = 0;
            } else {
                cache.sol = (cache.sol + cache.pot_p[0]) % P;
                for (int i = 1; i <= cache.len; i++) {
                    cache.pot_l[i] = (cache.pot_p[i - 1] + cache.pot_l[i]) % P;
                }
                rotate(cache.pot_p.begin(), cache.pot_p.begin() + 1,
                       cache.pot_p.begin() + cache.len);
                cache.pot_p[cache.len - 1] = 0;
            }
        }

        return cache;
    }
};

int get_perfect_drybls(const string& s) {
    int n = int(s.size());
    int n_l = count(all(s), 'L');
    int n_lp = min(n_l, n - n_l);

    vi pot_l(n_lp + 2);
    vi pot_p(n_lp + 2);

    pot_l[1] = 1;

    int sol = 0;

    for (char c : s) {
        if (c == 'L') {
            for (int i = 1; i <= n_lp; i++) {
                pot_p[i - 1] = (pot_p[i - 1] + pot_l[i]) % P;
            }
            rotate(pot_l.rbegin(), pot_l.rbegin() + 1, pot_l.rend());
            pot_l.front() = 0;
        } else {
            sol = (sol + pot_p[0]) % P;
            for (int i = 1; i <= n_lp; i++) {
                pot_l[i] = (pot_p[i - 1] + pot_l[i]) % P;
            }
            rotate(pot_p.begin(), pot_p.begin() + 1, pot_p.end());
            pot_p.back() = 0;
        }
    }

    return sol;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vec<string> ss(n);
    for (string& s : ss) {
        cin >> s;
    }

    for (string& l : ss) {
        for (string& r : ss) {
            cout << get_perfect_drybls(l + r) << ' ';
        }
        cout << endl;
    }
}