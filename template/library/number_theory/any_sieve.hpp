#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct mobius_sieve
{
    vector<ll> primes;
    vector<char> is_composite;
    vector<ll> mlp_fnc;
    vector<ll> cnt;

    mobius_sieve(int n) : is_composite(n + 1, false), mlp_fnc(n + 1), cnt(n + 1)
    {
        mlp_fnc[1] = 1;
        for (int k = 2; k < n; ++k)
        {
            if (!is_composite[k])
            {
                primes.push_back(k);
                mlp_fnc[k] = 2;
                cnt[k] = 1;
            }
            for (size_t i = 0; i < primes.size() && k * primes[i] <= n; ++i)
            {
                const auto prime = primes[i];
                const auto t = k * prime;
                is_composite[t] = true;
                if (k % prime == 0)
                {
                    mlp_fnc[t] = mlp_fnc[k]; // f(k * p) = f(k / p^cnt(k)) * f(p^{cnt(k) + 1})
                    cnt[t] = cnt[k] + 1;
                    break; // next primes will be no longer the smallest divisors of k * prime
                }
                else
                {
                    mlp_fnc[t] = mlp_fnc[k] * mlp_fnc[prime]; //prime does not divide k
                    cnt[t] = 1;
                }
            }
        }
    }
};