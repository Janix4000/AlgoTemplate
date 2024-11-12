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
    string f, s, l;

    cin >> f >> s >> l;

    int trans[26];
    for (int i = 0; i < f.size(); i++) {
        trans[f[i] - 'a'] = i;
    }
    string res;

    for (char c : l) {
        if (isupper(c)) {
            res += s[trans[c - 'A']] - 'a' + 'A';
        } else if (isdigit(c)) {
            res += c;
        } else {
            res += s[trans[c - 'a']];
        }
    }

    cout << res;

    return 0;
}