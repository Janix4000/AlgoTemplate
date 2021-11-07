#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, b) FOR(i, 0, b)
#define all(x) (x).begin(), (x).end()

template <typename T>
using vec = vector<T>;

using ll = long long;
constexpr ll INF = 1000000000LL;

using vi = vec<ll>;
using vvi = vec<vi>;
using vvvi = vec<vvi>;

map<pair<ll, ll>, ll> cache;

ll ask(ll x, ll y)
{
    ll d;
    if (cache.find({x, y}) == cache.end())
    {
        cout << x << ' ' << y << endl;
        cin >> d;
        cache[{x, y}] = d;
    }
    else
    {
        d = cache[{x, y}];
    }
    return d;
}

void solution()
{
    constexpr ll MIN = 0;
    // constexpr ll MAX = 20 + 1;
    constexpr ll MAX = ll(1e6) + 1;

    int N;
    cin >> N;

    F0R(i, N)
    {
        cache.clear();
        bool found = false;
        ll x = MAX / 2, y = MAX / 2;
        ll left = MIN, right = MAX;
        ll top = MIN, bot = MAX;
        while (true)
        {
            ll xl = left + (right - left) / 3;
            ll xr = left + (2 * (right - left)) / 3;
            if (xl == xr)
            {
                x = xl;
                break;
            }
            else
            {
                ll dl = ask(xl, y);
                if (dl == 0)
                {
                    x = xl;
                    found = true;
                    break;
                }
                ll dr = ask(xr, y);
                if (dr == 0)
                {
                    x = xr;
                    found = true;
                    break;
                }
                if (dl < dr)
                {
                    right = xr;
                }
                else
                {
                    left = xl + 1;
                }
            }
        }

        while (!found)
        {
            ll yt = top + (bot - top) / 3;
            ll yb = top + 2 * (bot - top) / 3;

            ll dl = ask(x, yt);
            if (dl == 0)
            {
                break;
            }
            ll dr = ask(x, yb);
            if (dr == 0)
            {
                break;
            }
            if (dl < dr)
            {
                bot = yb;
            }
            else
            {
                top = yt + 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int qs = 1;
    // cin >> qs;
    while (qs--)
    {
        solution();
    }
}