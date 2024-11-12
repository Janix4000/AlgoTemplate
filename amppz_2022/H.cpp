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

#define all(x) x.begin(), x.end()

using P = array<int, 3>;
enum Tfdsfsd { X, T, Idx };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    vector<P> pts(2 * n);

    vector<int> left(n);
    vector<int> right(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pts[2 * i] = {a, 0, i};
        pts[2 * i + 1] = {b, -1, i};
        left[i] = a;
        right[i] = a;
    }

    struct P {
        int x;
        int t;
        int idx;
        int x_other;
        bool deg = false;
        bool operator<(const P& rhs) const {
            if (idx == rhs.idx) {
                return x < rhs.x;
            }

            if(deg && rhs.deg) {
                if(t == rhs.t) {
                    bool xd = idx < rhs.idx ^   

                }
            }

            if (x != rhs.x) {
                return x < rhs.x;
            }

            if (t == rhs.t) {
                if (t == 0) {
                    return x_other > rhs.x_other;
                } else {
                    return x_other < rhs.x_other;
                }
            }

            if()
        }
    }

    auto pred = [&](const P& f, const P& g) {
        if (f[2] == g[2]) {
            return f[1] > g[1];
        }
        if (f[X] == g[X] && f[1] == g[1]) {
            if (f[1] == X) {
                if (right[f[2]] == right[g[2]]) {
                    return f[2] < g[2];
                }
                return right[f[2]] > right[g[2]];
            } else {
                if (left[f[2]] == left[g[2]]) {
                    return f[2] > g[2];
                }
                return left[f[2]] < left[g[2]];
            }
        }
        return f < g;
    };

    sort(all(pts), pred);

    set<P, decltype(pred)> found(pred);

    int res[2] = {-2, -2};

    for (auto& pt : pts) {
        if (pt[1] == 0) {
            found.insert(pt);
        } else {
            P l_pt = {left[pt[2]], 0, pt[2]};
            if (found.find(l_pt) != found.begin()) {
                res[0] = pt[2];
                res[1] = found.begin()->at(2);
                break;
            } else {
                found.erase(l_pt);
            }
        }
    }

    cout << res[0] + 1 << " " << res[1] + 1;

    return 0;
}