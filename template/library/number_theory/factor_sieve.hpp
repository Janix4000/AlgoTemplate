#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void get_factor_sieve(const ll max_prime, vector<ll> &first_factors) {
    first_factors.resize(max_prime + 1);
    fill(first_factors.begin(), first_factors.end(), -1);
    first_factors[0] = first_factors[1] = 1;
    for (ll i = 2; i * i <= max_prime; i++) {
        if (first_factors[i] == -1) {
            for (ll j = i; j <= max_prime; j += i) {
                if (first_factors[j] == -1) {
                    first_factors[j] = i;
                }
            }
        }
    }
}

vector<ll> get_factor_sieve(const ll max_prime) {
    vector<ll> first_factors(max_prime + 1, -1);
    get_factor_sieve(max_prime, first_factors);
    return first_factors;
}