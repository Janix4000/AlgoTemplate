#include <bits/stdc++.h>

using namespace std;
constexpr int N = int(1e6) + 1;
using ll = long long;
using ull = unsigned long long;
using Seal = pair<int, int>;

bool can_impr(Seal s1, Seal s2, int a, int b) { 
    int a1 = s1.first, b1 = s1.second, a2 = s2.first, b2 = s2.second;
    bool res = false;
    res = res || (a1 + a2 <= a && max(b1, b2) <= b);
    res = res || (a1 + b2 <= a && max(b1, a2) <= b);
    res = res || (b1 + a2 <= a && max(a1, b2) <= b);
    res = res || (b1 + b2 <= a && max(a1, a2) <= b);

    res = res || (a1 + a2 <= b && max(b1, b2) <= a);
    res = res || (a1 + b2 <= b && max(b1, a2) <= a);
    res = res || (b1 + a2 <= b && max(a1, b2) <= a);
    res = res || (b1 + b2 <= b && max(a1, a2) <= a);

    return res;
}

int main(int argc, const char** argv) {
    int n, a, b;
    cin >> n >> a >> b;
    vector<Seal> seals;
    for (size_t i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        seals.push_back({x, y});
    }
    int max_surface = 0;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) {
            if(can_impr(seals[i], seals[j], a, b)) {
                int new_surface = seals[i].first * seals[i].second + seals[j].first * seals[j].second;
                if (max_surface < new_surface) {
                    max_surface = new_surface;
                }
            }
        }
    }
    std::cout << max_surface << std::endl;
    return 0;
}