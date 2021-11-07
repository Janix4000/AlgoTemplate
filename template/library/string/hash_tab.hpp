#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll power_mod(ll a, ll n, const ll P) {
    ll res = 1ll;
    while (n) {
        if (n % 2ll) {
            res = (res * a) % P;
        }
        n /= 2ll;
        a = (a * a) % P;
    }
    return res;
}

// p = 67, ll(1e9) + 87
// p = 83, ll(1e9) + 123

// ll(1e6) + 3, 19, 43, 49
// q = ll(1e9) + 9, 87, 123

struct HashTab {
    ll p, q;
    vector<ll> tab;
    HashTab(string &text, ll p, ll q) : tab(text.size() + 1), p(p), q(q) {
        ll n = text.size();
        tab[0] = 0;
        for (int i = 0; i < n; ++i) {
            tab[i + 1] = (tab[i] * p + text[i]) % q;
        }
    }

    ll hash(ll beg, ll end) {
        ll n = end - beg;
        ll a = (tab[beg] * power_mod(p, n, q)) % q;
        return (tab[end] - a + q) % q;
    }

    bool same(ll beg0, ll end0, ll beg1, ll end1) {
        return hash(beg0, end0) == hash(beg1, end1);
    }
};

struct Hasher {
    vector<HashTab> hashTabs;
    Hasher(string &text, const vector<ll> &ps, const vector<ll> &qs) {
        for (int i = 0; i < ps.size(); ++i) {
            ll p = ps[i];
            ll q = qs[i];
            hashTabs.emplace_back(text, p, q);
        }
        // for (ll p : ps) {
        //     for (ll q : qs) {
        //         hashTabs.emplace_back(text, p, q);
        //     }
        // }
    }

    bool same(ll beg0, ll end0, ll beg1, ll end1, Hasher &rhs) {
        for (int i = 0; i < hashTabs.size(); i++) {
            ll hash0 = hashTabs[i].hash(beg0, end0);
            ll hash1 = rhs.hashTabs[i].hash(beg1, end1);
            if (hash0 != hash1) {
                return false;
            }
        }
        return true;
    }

    bool same(ll beg0, ll end0, ll beg1, ll end1) {
        return same(beg0, end0, beg1, end1, *this);
    }
};