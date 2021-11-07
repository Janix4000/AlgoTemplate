#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct linear_sieve {
    vector<char> is_composite;
    vector<ll> primes;
    linear_sieve(int n) : is_composite(n + 1, false) {
        for (int k = 2; k < n; k++) {
            if (!is_composite[k]) {
                primes.push_back(k);
            }
            for (int i = 0; i < primes.size() && k * primes[i] <= n; i++) {
                is_composite[k * primes[i]] = true;
                if (k % primes[i] == 0) {
                    break;
                }
            }
        }
    }
};