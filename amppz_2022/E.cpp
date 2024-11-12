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

enum Op { _or, _xor, _and };
map<string, Op> ops = {{"XOR", _xor}, {"OR", _or}, {"AND", _and}};

map<string, int> v2i;
int last_v2i = 0;

struct v {
    static vector<v> G;
    bool fix;
    string fixed_string;
    int x;
    Op op;
    int y;

    char val = 0;

    int value(int i) {
        if (fix) return fixed_string[i] - '0';

        if (val != 0) {
            return val - '0';
        }

        int a = v::G[x].value(i);
        int b = v::G[y].value(i);

        int res = 0;
        switch (op) {
            case _or:
                res = a | b;
                break;
            case _xor:
                res = a ^ b;
                break;
            case _and:
                res = a & b;
                break;
        }

        val = (res + '0');

        return res;
    }
};
vector<v> v::G;

int S(int j) {
    int ret = 0;
    for (int i = 1; i < v::G.size(); ++i) {
        ret += v::G[i].value(j);
    }
    return ret;
}

void reset_mem() {
    for (auto& v : v::G) {
        v.val = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    v::G.resize(n + 1);

    auto t = v();
    t.fix = true;
    t.fixed_string = string(m, '0');
    v::G[0] = t;
    v2i["?"] = last_v2i++;

    while (n--) {
        string name, _, a, op, b;
        cin >> name >> _ >> a;
        auto t = v();
        if ('0' == a[0] || '1' == a[0]) {
            t.fix = true;
            t.fixed_string = a;
        } else {
            cin >> op >> b;
            t.fix = false;
            t.x = v2i[a];
            t.op = ops[op];
            t.y = v2i[b];
        }
        v2i[name] = last_v2i++;
        v::G[v2i[name]] = t;
    }

    string r = "";
    reset_mem();
    for (int i = 0; i < m; ++i) {
        v::G[0].fixed_string[i] = '0';
        int a = S(i);
        reset_mem();
        v::G[0].fixed_string[i] = '1';
        int b = S(i);
        reset_mem();
        if (b < a)
            r += "1";
        else
            r += "0";
    }
    cout << r << '\n';

    r = "";
    for (int i = 0; i < m; ++i) {
        v::G[0].fixed_string[i] = '0';
        int a = S(i);
        reset_mem();
        v::G[0].fixed_string[i] = '1';
        int b = S(i);
        reset_mem();
        if (b > a)
            r += "1";
        else
            r += "0";
    }
    cout << r << '\n';
}