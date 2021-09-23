#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll get_totient(ll n)
{
    ll res = n;
    for (ll k = 2; k * k <= n; ++k)
    {
        if (n % k == 0)
        {
            res = (res / k) * (k - 1);
            while (n % k == 0)
            {
                n /= k;
            }
        }
    }
    if (n > 1)
    {
        res = (res / n) * (n - 1);
    }
    return res;
}

vector<ll> get_totients_up_to(ll n)
{
    vector<ll> totients(n + 1);
    iota(totients.begin(), totients.end(), 0);
    for (ll k = 2; k <= n; ++k)
    {
        if (k == totients[k])
        {
            for (int j = k; j <= n; j += k)
            {
                totients[j] = (totients[j] / k) * (k - 1);
            }
        }
    }
    return totients;
}