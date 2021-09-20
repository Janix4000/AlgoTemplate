#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

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
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define FOR(i, a, b) for (int i = a; i < (b); ++i)
#define F0R(i, a) for (int i = 0; i < (a); ++i)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; --i)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; --i)
#define trav(a, x) for (auto &a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template <class T>
bool ckmin(T &a, const T &b)
{
    return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void ___print(int x) { cerr << x; }
void ___print(long x) { cerr << x; }
void ___print(long long x) { cerr << x; }
void ___print(unsigned x) { cerr << x; }
void ___print(unsigned long x) { cerr << x; }
void ___print(unsigned long long x) { cerr << x; }
void ___print(float x) { cerr << x; }
void ___print(double x) { cerr << x; }
void ___print(long double x) { cerr << x; }
void ___print(char x) { cerr << '\'' << x << '\''; }
void ___print(const char *x) { cerr << '\"' << x << '\"'; }
void ___print(const string &x) { cerr << '\"' << x << '\"'; }
void ___print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void ___print(const pair<T, V> &x)
{
    cerr << '{';
    ___print(x.first);
    cerr << ", ";
    ___print(x.second);
    cerr << '}';
}
template <typename T>
void ___print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? ", " : ""), ___print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    ___print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
template <typename T>
void __print(T &&t)
{
    ___print(t);
    cerr << '\n';
}
#ifdef DEBUG
#define dbg(x...)                                                             \
    cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #x << "] = ["; \
    _print(x);                                                                \
    cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

vi build(vl &tab)
{
    vector<pair<ll, int>> indVal;
    for (int i = 0; i < tab.size(); i++)
    {
        indVal.pb({tab[i], i});
    }
    sort(indVal.begin(), indVal.end());
    set<int> ind;
    vi res(tab.size());
    for (pair<ll, int> p : indVal)
    {
        auto it = ind.lower_bound(p.second);
        if (it != ind.end())
        {
            res[p.second] = *it;
        }
        else
        {
            res[p.second] = -1;
        }
        ind.insert(p.second);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    vl A = {5, 6, 3, 7, 1, 4, 3, 6, 3};
    __print(build(A));
}