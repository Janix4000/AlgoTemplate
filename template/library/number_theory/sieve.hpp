#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void get_sieve(const ll max_prime, vector<char> &is_prime)
{
    is_prime.resize(max_prime + 1);
    fill(is_prime.begin(), is_prime.end(), true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= max_prime; i++)
    {
        if (is_prime[i])
        {
            for (ll j = i * i; j <= max_prime; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
}

vector<char> get_sieve(const ll max_prime)
{
    vector<char> is_prime(max_prime + 1, true);
    get_sieve(max_prime, is_prime);
    return is_prime;
}