#include <functional>
#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;
#define all(x) (x).begin(), (x).end()
using ll = long long;

ll fact(ll n, ll p) {
    ll res = 1;
    for (ll i = 2; i <= n; i++) {
        res = (res * i) % p;
    }
    return res;
}

ll power_mod(ll a, ll n, const ll P) {
    ll res = 1;
    while (n) {
        if (n % (ll)2) {
            res = (res * a) % P;
        }
        n /= (ll)2;
        a = (a * a) % P;
    }
    return res;
}

vector<ll> get_factorials_mod(ll n, ll P) {
    vector<ll> factorials(n + 1);
    factorials[0] = 1;
    factorials[1] = 1;
    for (ll k = 2; k <= n; ++k) {
        factorials[k] = (factorials[k - 1] * (k % P)) % P;
    }
    return factorials;
}

ll binomial_mod(ll n, ll k, ll P, const vector<ll> &factorials = {}) {
    vector<ll> tmp;
    if (factorials.empty()) {
        tmp = get_factorials_mod(n, P);
    }
    auto &F = (factorials.empty() ? tmp : factorials);
    ll res = F[n];
    res = (res * power_mod(F[k], P - 2, P)) % P;
    res = (res * power_mod(F[n - k], P - 2, P)) % P;
    return res;
}

//

int main() {
    ll n, p;
    cin >> n >> p;

    ll res = n % p;
    ll k = n / 2 + 1;
    res = (res * fact(k - 2, p)) % p;
    res = (res * 2) % p;

    ll rest = 0;

    auto factorials = get_factorials_mod(n - k, p);

    ll base = 1;
    base =

        for (ll i = 0; i <= n - k; i++) {
        ll add = binomial_mod(n - k, i, p, factorials) *rest = (rest +)
    }
}