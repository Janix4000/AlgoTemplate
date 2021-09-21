#include <bits/stdc++.h>
using namespace std;

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
    cerr << '(';
    ___print(x.first);
    cerr << ", ";
    ___print(x.second);
    cerr << ')';
}
template <typename T>
void ___print(const T &x)
{
    int f = 0;
    cerr << '[';
    for (auto &i : x)
        cerr << (f++ ? ", " : ""), ___print(i);
    cerr << "]";
}
// template <typename T, typename Q>
// void ___print(const map<T, Q> &x)
// {
//     int f = 0;
//     cerr << '[';
//     for (auto &i : x)
//         cerr << (f++ ? ", " : ""), cerr << "(", ___print(i.first), cerr << ": ", ___print(i.second), cerr << ")";
//     cerr << "]";
// }
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
template <typename T, typename... Ts>
void __print(T &&t, Ts &&...ts)
{
    ___print(t);
    cerr << ' ';
    __print(ts...);
}

#ifdef DEBUG
#define dbg(x...)                                                             \
    cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #x << "] = ["; \
    _print(x);                                                                \
    cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif