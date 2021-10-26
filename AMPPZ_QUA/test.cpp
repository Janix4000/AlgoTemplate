#include <bits/stdc++.h>
#ifndef DEBUG
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#endif // !DEBUG

template <typename... Ts>
void __print(Ts &&...ts);
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
struct aho_corrasic
{
    static constexpr int N_WORDS = int('z' - 'a' + 1);
    static constexpr int FAIL = -1;
    static constexpr int START_STATE = 0;
    struct Transition : public array<int, N_WORDS>
    {
        Transition(int next_state = FAIL)
        {
            fill(next_state);
        }
        int &operator[](char idx) { return array<int, N_WORDS>::operator[](idx - 'a'); }
        int operator[](char idx) const { return array<int, N_WORDS>::operator[](idx - 'a'); }
    };
    using GoTo = vector<Transition>;
    using Fail = vector<int>;
    using Output = vector<vector<string>>;

    GoTo g;
    Fail f;
    Output o;

    void add_key(const string &key)
    {
        auto state = 0;
        for (auto c : key)
        {
            auto &node = g[state];
            const int next_state = node[c];
            if (next_state == FAIL || next_state == 0)
            {
                state = (int)g.size();
                node[c] = state;
                g.emplace_back();
                o.emplace_back();
            }
            else
            {
                state = next_state;
            }
        }
        o[state].push_back(key);
    }

    void construct_trie(const vector<string> &keywords)
    {
        for (auto &key : keywords)
        {
            add_key(key);
        }
    }

    void construct_failure()
    {
        f.resize(g.size(), 0);
        const auto &start = g.front();
        queue<int> q;
        for (char c = 'a'; c <= 'z'; ++c)
        {
            if (start[c] != 0)
            {
                auto next_state = start[c];
                q.push(next_state);
                f[next_state] = 0;
            }
        }
        while (!q.empty())
        {
            const auto beg_state = q.front();
            const auto &node = g[beg_state];
            q.pop();
            for (char c = 'a'; c <= 'z'; ++c)
            {
                auto next_state = node[c];
                if (next_state != FAIL)
                {
                    q.push(next_state);
                    auto state = f[beg_state];
                    while (g[state][c] == FAIL)
                    {
                        state = f[state];
                    }
                    f[next_state] = g[state][c];
                    o[next_state].insert(o[next_state].end(), o[f[next_state]].begin(), o[f[next_state]].end());
                }
            }
        }
    }

    void print() const
    {
        for (int state = 0; state < (int)g.size(); state++)
        {
            cerr << state << ": ";
            for (char c = 'a'; c <= 'z'; ++c)
            {
                if (g[state][c] == 0 || g[state][c] == FAIL)
                {
                    continue;
                }
                cerr << c << ": " << g[state][c] << ", ";
            }
            cerr << endl;
        }
        for (int state = 0; state < (int)g.size(); state++)
        {
            cerr << "f[" << state << "]: " << f[state] << endl;
        }
    }
    void print_dot() const
    {
        cerr << "digraph G {\n";
        for (int state = 0; state < (int)g.size(); state++)
        {
            for (char c = 'a'; c <= 'z'; ++c)
            {
                if (g[state][c] == 0 || g[state][c] == FAIL)
                {
                    continue;
                }
                cerr << "\t" << state << "->" << g[state][c] << "[label=\" " << c << " \"]\n";
            }
        }
        for (int state = 0; state < (int)g.size(); state++)
        {
            cerr << "\t" << state << "->" << f[state] << "[color=\"#ff000044\",constraint=false]\n";
        }
        cerr << "}\n";
    }
    void query(const string &txt)
    {
        auto state = 0;
        for (auto c : txt)
        {
            while (g[state][c] == FAIL)
            {
                state = f[state];
            }
            state = g[state][c];
            for (auto &key : o[state])
            {
                cout << key << ' ';
            }
            if (!o[state].empty())
            {
                cout << endl;
            }
        }
    }

    aho_corrasic(const vector<string> &keywords)
    {
        g.emplace_back(0);
        o.emplace_back();
        construct_trie(keywords);
        construct_failure();
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////

void solution()
{
    vec<string> keywords = {"e", "he", "she", "hehehr", "teshe", "eteshe", "her", "heht"};
    // vec<string> keywords = {"he", "her", "she", "his", "hers"};
    aho_corrasic aho(keywords);
    aho.print_dot();
    aho.query("shersshehise");
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