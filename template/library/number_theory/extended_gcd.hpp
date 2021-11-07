#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct extended_gcd {
    ll gcd, x, y;
    extended_gcd(ll a, ll b) { gcd = __get_gcd(a, b, x, y); }

   private:
    ll __get_gcd(ll a, ll b, ll &x, ll &y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        }
        ll x1, y1;
        ll gcd = __get_gcd(b, a % b, x1, y1);
        x = y1;
        y = x1 - y1 * (a / b);
        return gcd;
    }
};