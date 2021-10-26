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
struct Type
{
    char type;
    int val;
    bool operator<(const Type &rhs) const { return val < rhs.val; }
    bool operator>(const Type &rhs) const { return val > rhs.val; }
};

int inv_pow(int pk, int p)
{
    int k = 0;
    while (pk > 1)
    {
        pk /= p;
        k++;
    }
    return k;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void solution()
{
    int P;
    cin >> P;
    string houses;
    houses.reserve(P);
    cin >> houses;
    int p = 2;
    if (P % p != 0)
    {
        for (int k = 3; k * k <= P; k += 2)
        {
            if (P % k == 0)
            {
                p = k;
                break;
            }
        }
        if (p == 2)
        {
            p = P;
        }
    }
    int _n;
    cin >> _n;
    vec<Type> types;
    map<char, int> values;
    F0R(i, _n)
    {
        char c;
        int val;
        cin >> c >> val;
        types.push_back({c, val});
        values[c] = val;
    }
    sort(all(types), greater<Type>{});
    vi used(P, -1);
    ll res = 0;
    auto leader = types.front();
    trav(t, types)
    {
        F0R(i, sz(houses))
        {
            char C = houses[i];
            if (C != t.type || used[i] != -1)
            {
                continue;
            }
            int pk = -1;
            for (int pp = 1; pp < P; pp *= p)
            {
                int k = P / pp;
                bool valid = true;
                F0R(g, k)
                {
                    auto idx = (i + g * pp) % P;
                    const char c = houses[idx];
                    if (c != t.type && c != '?')
                    {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                {
                    pk = pp;
                    break;
                }
            }
            while (pk <= P)
            {
                int k = P / pk;
                int inv_k = inv_pow(k, p) + 1;

                // ll potential_k = (1 - P / pk * p) / (1 - p);
                // ll leader_k = (1 - P / pk) / (1 - p);
                // ll potential_sum = potential_k * t.val;
                // ll leader_sum = leader_k * types.front().val;
                ll potential_sum = k * inv_k * t.val;
                ll lower_sum = (k / p) * (inv_k - 1) * t.val;
                ll leader_sum = (k / p) * (inv_k - 1) * leader.val;
                bool broken = false;
                if (potential_sum + lower_sum < leader_sum)
                {
                    FOR(shift, 1, pk * p)
                    {
                        bool valid = true;
                        F0R(g, k / p)
                        {
                            auto idx = ((i + shift) + g * pk * p) % P;
                            const char c = houses[idx];
                            if (c != '?')
                            {
                                valid = false;
                                break;
                            }
                        }
                        if (valid)
                        {
                            F0R(g, k / p)
                            {
                                auto idx = ((i + shift) + g * pk * p) % P;
                                houses[idx] = types.front().type;
                                used[idx] = 0;
                            }
                            broken = true;
                            res += leader_sum;
                        }
                    }
                }
                if (broken)
                {
                    pk *= p;
                }
                else
                {
                    F0R(g, k)
                    {
                        auto idx = (i + g * pk) % P;
                        houses[idx] = t.type;
                        used[idx] = i;
                    }
                    res += potential_sum;
                    break;
                }
            }
        }
    }
    __print(houses);
    cout << res;
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