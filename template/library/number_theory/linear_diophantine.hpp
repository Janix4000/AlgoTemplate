#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#include "extended_gcd.hpp"

template <typename T>
int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

struct linear_diophantine {
    ll x = 0, y = 0;
    bool solution_exists = true;
    linear_diophantine(ll a, ll b, ll c) {
        auto gcd = extended_gcd(abs(a), abs(b));
        if (c % gcd.gcd) {
            solution_exists = false;
        } else {
            x = gcd.x * c / gcd.gcd;
            y = gcd.y * c / gcd.gcd;
            if (a < 0) {
                x = -x;
            }
            if (b < 0) {
                y = -y;
            }
            solution_exists = true;
        }
    }
};
