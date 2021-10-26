#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct phi_sieve
{
	vector<ll> primes;
	vector<char> is_composite;
	vector<ll> phi;

	phi_sieve(int n) : is_composite(n + 1, false), phi(n + 1)
	{
		phi[1] = 1;
		for (int k = 2; k < n; ++k)
		{
			if (!is_composite[k])
			{
				primes.push_back(k);
				phi[k] = k - 1; //k is primes
			}
			for (int i = 0; i < primes.size() && k * primes[i] <= n; ++i)
			{
				auto prime = primes[i];
				is_composite[k * prime] = true;
				if (k % prime == 0)
				{
					phi[k * prime] = phi[k] * prime; //prime divides k
					break;
				}
				else
				{
					phi[k * prime] = phi[k] * phi[prime]; //prime does not divide k
				}
			}
		}
	}
};