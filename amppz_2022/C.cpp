#ifdef __APPLE__

// C
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

#else

#include <bits/stdc++.h>

#endif

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string a, b;
    a.reserve(2 * n);
    b.reserve(2 * n);
    cin >> a >> b;

    int c[2][2] = {};

    for (int i = 0; i < 2 * n; i++) {
        int l = a[i] - '0';
        int r = b[i] - '0';

        c[l][r]++;
    }

    int res[2] = {};

    for (int i = 0; i < n; i++) {
        if (c[1][1]) {
            c[1][1]--;
            res[0]++;
        } else if (c[1][0]) {
            c[1][0]--;
            res[0]++;
        } else if (c[0][1]) {
            c[0][1]--;
        } else if (c[0][0]) {
            c[0][0]--;
        }

        if (c[1][1]) {
            c[1][1]--;
            res[1]++;
        } else if (c[0][1]) {
            c[0][1]--;
            res[1]++;
        } else if (c[1][0]) {
            c[1][0]--;
        } else if (c[0][0]) {
            c[0][0]--;
        }
    }

    if (res[0] == res[1]) {
        cout << "Draw\n";
    } else if (res[0] > res[1]) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }

    return 0;
}