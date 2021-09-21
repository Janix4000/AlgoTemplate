using ll = long long;
constexpr ll P = 1000000007;

template <typename ll = long long>
ll powerModT(ll a, ll n, const ll P)
{
    ll res = 1;
    while (n)
    {
        if (n % (ll)2)
        {
            res = (res * a) % P;
        }
        n /= (ll)2;
        a = (a * a) % P;
    }
    return res;
}

template <typename ll = long long>
ll power(ll a, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n % (ll)2)
        {
            res = (res * a);
        }
        n /= (ll)2;
        a = (a * a);
    }
    return res;
}
