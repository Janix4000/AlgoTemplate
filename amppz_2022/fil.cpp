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
using ll = long long;

using vi = vector<int>;
using vvi = vector<vi>;

int flip(int a) { return a == 0 ? 1 : 0; }

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        ll p, q, n;
        cin >> p >> q >> n;

        if (n % __gcd(p, q)) {
            cout << "R\n";
            continue;
        }

        int P[2] = {p, q};

        int init = 0;

        while (n) {
            if (n % P[init] == 0) {
                break;
            }
            if (n > P[init]) {
                n -= P[init] * (n / P[init]);

                if (n < P[init]) }
        }
    }
}