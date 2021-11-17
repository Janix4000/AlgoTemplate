#include <bits/stdc++.h>

template <typename... Ts>
void __print(Ts &&...ts) {}
#ifdef DEBUG
#include "print.hpp"
#endif // DEBUG

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

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define beg begin

template <class T>
bool ckmin(T &a, const T &b)
{
    return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
T max(T a, T b, T c) { return max(max(a, b), c); }
template <typename T, typename... Ts>
T max(T a, Ts... as) { return max(a, max(as...)); }
template <typename T>
T min(T a, T b, T c) { return min(min(a, b), c); }
template <typename T, typename... Ts>
T min(T a, Ts... as) { return min(a, min(as...)); }
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

void solution()
{
    int D, T;
    cin >> D >> T;
    vi days(D);
    F0R(i, D)
    {
        cin >> days[i];
    }
    vpi teams(T);
    F0R(i, T)
    {
        cin >> teams[i].first >> teams[i].second;
    }
    // sort(all(teams));
    vvi sh(D, vi(T, 0));
    F0R(d, D)
    {
        F0R(t, min(T, days[d]))
        {
            if (d == 0)
            {
                sh[d][t] = 1;
            }
            else
            {
                sh[d][t] = 1 + sh[d - 1][t];
            }
        }
    }
    vi slots;
    F0R(t, T)
    {
        F0R(d, D)
        {
            if (sh[d][t] != 0)
            {
                if (d + 1 == D || sh[d + 1][t] == 0)
                {
                    slots.push_back(sh[d][t]);
                }
            }
        }
    }
    sort(all(slots), greater<int>{});
    slots.erase(slots.begin() + min(T, (int)slots.size()), slots.end());
    auto max_slot = slots[0];
    vvi dp(T, vi(max_slot + 1, 0));
    F0R(t, T) {
        auto team = teams[t];
        auto time = team.first;
        auto income = team.second;
        F0R(is, int(slots.size())) {
            F0R(s, is) {

            }
        }
    }

    __print(sh);
    __print(slots);

    // vec<vvi> dp(D, vvi(T, vi(T, 0)));
    // F0R(t, T)
    // {
    //     auto team = teams[t];
    //     auto time = team.first;
    //     auto income = team.second;
    //     F0R(d, D)
    //     {
    //         F0R(col, min(T, days[d]))
    //         {
    //             if (sh[d][col] < time)
    //             {
    //                 dp[d][t][col] = t == 0 ? 0 : dp[d][t - 1][col];
    //             }
    //             else
    //             {
    //                 if (t == 0)
    //                 {
    //                     dp[d][t][col] = income;
    //                 }
    //                 else
    //                 {
    //                     int candidate = 0;
    //                     if (d - t >= 0)
    //                     {
    //                         candidate = dp[d - t][t - 1][col];
    //                     }
    //                     dp[d][t][col] = max(dp[d][t - 1][col], candidate + income);
    //                 }
    //             }
    //         }
    //     }
    // }
    // __print(dp);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;
    // cin >> qs;

    while (qs--)
    {
        solution();
    }
    return 0;
}