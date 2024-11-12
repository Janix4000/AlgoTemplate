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

using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> nums(n);
    map<int, int> nums_idx;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        nums_idx[nums[i]] = i;
    }

    vi visited = vi(n, false);

    vvi graph = vvi(n);

    bool err = false;

    for (int i = 0; i < n; i++) {
        int k = nums[i];

        if (auto it = nums_idx.find(a - k); it != nums_idx.end()) {
            graph[i].push_back(it->second);
        }
        if (auto it = nums_idx.find(b - k); it != nums_idx.end()) {
            graph[i].push_back(it->second);
        }
    }

    vi res(n, 0);

    queue<int> q;
    for (int i = 0; i < graph.size(); i++) {
        if (graph[i].size() == 1) {
            q.push(i);
        }
    }

    bool errrr = false;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (visited[v]) {
            continue;
        }

        visited[v] = true;
        bool err = true;
        for (int e : graph[v]) {
            if (visited[e]) {
                continue;
            }
            visited[e] = true;
            err = false;
            if (b - nums[e] == nums[v]) {
                res[e] = 1;
                res[v] = 1;
            }

            for (int b : graph[e]) {
                if (visited[b]) continue;
                q.push(b);
                break;
            }
        }

        if (err) {
            errrr = true;
            break;
        }
    }

    if (errrr ||
        !all_of(begin(visited), end(visited), [](int k) { return k; })) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
    }

    return 0;
}