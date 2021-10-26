#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll get_phi(ll n)
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
