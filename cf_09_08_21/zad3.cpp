#include <bits/stdc++.h>
using namespace std;

constexpr int N = int(1e6) + 1;

using ll = long long;
using ull = unsigned long long;
template <typename T>
using vec = vector<T>;
using veci = vec<int>;

constexpr ll P = 1000000007;

ll power(ll a, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n % 2)
        {
            res = (res * a) % P;
        }
        n /= 2;
        a = (a * a) % P;
    }
    return res;
}

int main(void)
{
    int qs = 1;
    cin >> qs;
    while (qs--)
    {
        ll n, k;
        cin >> n >> k;

        vec<ll> F(n + 1);
        F[0] = 1;
        F[1] = 1;
        for (ll i = 2; i < n + 1; i++)
        {
            F[i] = (F[i - 1] * i) % P;
        }

        auto B = [F](ll n, ll k)
        {
            ll res = F[n];
            res = (res * power(F[k], P - 2)) % P;
            res = (res * power(F[n - k], P - 2)) % P;
            return res;
        };
        ll sum = 0;
        for (ll i = 0; i < (n + 1) / 2; i++)
        {
            sum = (sum + B(n, 2 * i)) % P;
        }
        ll res = 0;
        if (n % 2 == 1)
        {
            res = power(sum + 1, k);
        }
        else
        {
            ll pow = 1;
            res = 1;
            const ll mult = power(2, n);
            for (ll i = 0; i < k; i++)
            {
                res = ((res * sum) % P + pow) % P;
                pow = (pow * mult) % P;
            }
        }
        cout << res << '\n';
    }
    return 0;
}