#include <bits/stdc++.h>
using namespace std;

constexpr int N = int(1e6) + 1;

using ll = long long;
#define int ll

using ull = unsigned long long;
template <typename T>
using vec = vector<T>;
using veci = vec<int>;

ll GCD(ll a, ll b)
{
    while (b != 0)
    {
        ll tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

vec<ll> DIVS(ll a)
{
    vec<ll> divs1;
    vec<ll> divs2;
    for (ll p = 1; p * p <= a; p++)
    {
        if (a % p == 0)
        {
            divs1.push_back(p);
            if (p * p != a)
            {
                divs2.push_back(a / p);
            }
        }
    }
    reverse(divs2.begin(), divs2.end());
    divs1.insert(divs1.end(), divs2.begin(), divs2.end());
    return divs1;
}

ll f(ll a, ll b)
{
    ll res = 0;
    auto divs_vec = DIVS(a);
    list<ll> divs(divs_vec.begin(), divs_vec.end());
    ll gcd = GCD(a, b);
    divs.remove(gcd);
    divs.remove_if([gcd](ll a)
                   { return a % gcd != 0; });
    while (!divs.empty())
    {
        ll new_gcd = *divs.rbegin();
        for (auto it = divs.rbegin(); it != divs.rend(); ++it)
        {
            if (b % *it < b % new_gcd)
            {
                new_gcd = *it;
            }
        }
        ll remainder = b % new_gcd;
        res += remainder / gcd;
        b -= remainder;
        gcd = new_gcd;
        divs.remove(gcd);
        divs.remove_if([gcd](ll a)
                       { return a % gcd != 0; });
    }
    if (gcd == a)
    {
        res += b / gcd;
    }
    return res;
}

ll f_cl(ll a, ll b)
{
    ll res = 0;
    while (b != 0)
    {
        b -= GCD(a, b);
        res += 1;
    }
    return res;
}

int main(void)
{
    int qs = 1;
    // cin >> qs;
    while (qs--)
    {
        ll a, b;
        cin >> a >> b;
        cout << f(a, b);
        // cout << ' ' << f_cl(a, b);
    }
    return 0;
}