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
    int r, d, n;
    cin >> r >> d >> n;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int x, y, r0;
        cin >> x >> y >> r0;

        int r2 = (x * x + y * y);

        if (r2 >= (r - d + r0) * (r - d + r0) && r2 <= (r - r0) * (r - r0)) {
            res++;
        }
    }
    cout << res;
    return 0;
}