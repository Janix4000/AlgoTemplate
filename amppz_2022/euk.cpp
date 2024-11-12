#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

// C++
#include <algorithm>
#include <array>
#include <bitset>
#include <complex>
#include <deque>
#include <forward_list>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using i32 = int32_t;
using i64 = int64_t;

struct ex_gcd {
    int x, y, gcd;

    ex_gcd(int a, int b) { gcd = _gcd(a, b, x, y); }

    int _gcd(int a, int b, int& x, int& y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        }
        int x1, y1;
        int gcd = _gcd(b, a % b, x1, y1);
        x = y1;
        y = x1 - y1 * (a / b);
        return gcd;
    }
};

struct ld {
    int x, y;
    bool sol;

    ld(int a, int b, int c) {
        auto gcd = ex_gcd(abs(a), abs(b));
        if (c % gcd.gcd) {
            sol = false;
            return;
        }
        x = gcd.x * c / gcd.gcd;
        y = gcd.y * c / gcd.gcd;
        if (a < 0) {
            x = -x;
        }
        if (b < 0) {
            y = -y;
        }
        sol = true;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p, q, n;
        cin >> p >> q >> n;
        int res = 1;
        if (n < p) {
            n += p;
            res = -res;
            if (n < q) {
                n += q;
                res = -res;
            }
        }
        auto sol = ld(p, q, -n);
        // auto sol = ex_gcd(p, q);

        if (!sol.sol) {
            res = 0;
        }

        if (res == 1) {
            if ((sol.y + 1) % p == 0) {
                ;
            } else if ((sol.x + 1) % q == 0) {
                res = -res;
            } else {
                res = 0;
            }

        } else if (res == -1) {
            if ((sol.x + 1) % q == 0) {
                ;
            } else if ((sol.y + 1) % p == 0) {
                res = -res;
            } else {
                res = 0;
            }
        }

        if (res == 1) {
            cout << "P\n";
        } else if (res == -1) {
            cout << "E\n";
        } else {
            cout << "R\n";
        }
    }
}