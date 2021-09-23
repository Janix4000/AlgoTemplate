#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#include "power.hpp"
vector<ll> get_factorials_mod(ll n, ll P)
{
    vector<ll> factorials(n + 1);
    factorials[0] = 1;
    factorials[1] = 1;
    for (ll k = 2; k <= n; ++k)
    {
        factorials[k] = (factorials[k - 1] * (k % P)) % P;
    }
    return factorials;
}

ll binomial_mod(ll n, ll k, ll P, const vector<ll> &factorials = {})
{
    vector<ll> tmp;
    if (factorials.empty())
    {
        tmp = get_factorials_mod(n, P);
    }
    auto &F = (factorials.empty() ? tmp : factorials);
    ll res = F[n];
    res = (res * power(F[k], P - 2)) % P;
    res = (res * power(F[n - k], P - 2)) % P;
    return res;
}