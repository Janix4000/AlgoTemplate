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
using vl = vector<ll>;
using vvl = vector<vl>;

using pi = pair<int, int>;
using pl = pair<ll, ll>;

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

void solution() {
    int n;
    cin >> n;
    string cities;
    cities.reserve(n + 1);
    cin >> cities;
    int l = 0;
    int r = 0;
    pq_max<int> singles;
    pq_max<int> doubles;
    int begin = 0;
    for (; begin < n; ++begin) {
        char c = cities[begin];
        if (c == '1') {
            break;
        }
        l++;
    }
    if (l == n) {
        cout << "0\n";
        return;
    }
    singles.push(l);
    int end = n - 1;
    for (; end >= 0; --end) {
        char c = cities[end];
        if (c == '1') {
            break;
        }
        r++;
    }
    singles.push(r);
    end++;

    int consecutive = 0;
    loop(i, begin, end) {
        char c = cities[i];
        if (c != '0') {
            if (consecutive != 0) {
                if (consecutive == 1) {
                    singles.push(consecutive);
                } else {
                    doubles.push(consecutive);
                }
                consecutive = 0;
            }
        } else {
            consecutive++;
        }
    }

    int result = 0;
    int day = 0;
    while (!singles.empty() || !doubles.empty()) {
        int s = singles.empty() ? 0 : singles.top();
        int d = doubles.empty() ? 0 : doubles.top();
        int cities_single = max(0, s - day);
        int cities_double = max(0, d - 2 * day);
        if (cities_single > cities_double && cities_single) {
            result += cities_single;
            singles.pop();
        } else if (cities_double > cities_single && cities_double) {
            result++;
            singles.push(d - day - 1);
            doubles.pop();
        } else {
            break;
        }
        day++;
    }

    cout << n - result << '\n';
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