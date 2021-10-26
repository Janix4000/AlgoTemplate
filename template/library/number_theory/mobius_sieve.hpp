#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct mobius_sieve
{
    vector<ll> primes;
    vector<char> is_composite;
    vector<ll> mobius;

    mobius_sieve(int n) : is_composite(n + 1, false), mobius(n + 1)
    {
        mobius[1] = 1;
        for (int k = 2; k < n; ++k)
        {
            if (!is_composite[k])
            {
                primes.push_back(k);
                mobius[k] = -1; //k is prime
            }
            for (size_t i = 0; i < primes.size() && k * primes[i] <= n; ++i)
            {
                const auto prime = primes[i];
                const auto t = k * prime;
                is_composite[t] = true;
                if (k % prime == 0)
                {
                    mobius[t] = 0; //prime^2 divides k * prime
                    break;         // next primes will be no longer the smallest divisors of k * prime
                }
                else
                {
                    mobius[t] = mobius[k] * mobius[prime]; //prime does not divide k
                }
            }
        }
    }
};