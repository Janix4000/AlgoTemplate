#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;
using ld = long double;

#define all(x) (x).begin(), (x).end()

using pi = pair<int, int>;
using vpi = vector<pi>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    ll best = ll(1e12);

    int left = 0;
    int right = 0;
    vpi blocked_segs;
    for (int i = 0; i < m; i++) {
        int pos;
        cin >> pos;
        if (pos == right) {
            if (i == m - 1) {
                blocked_segs.push_back({left, right});
            } else {
                right++;
            }
        } else {
            blocked_segs.push_back({left, right});
            left = pos + 1;
            right = pos + 1;
        }
    }

    if (blocked_segs.size() && blocked_segs[0].first == 0) {
        cout << -1 << endl;
        return 0;
    }

    vpi segs;
    int left = 0;
    for (auto blocked : blocked_segs) {
        segs.push_back({left, blocked.first - 1});
        left = blocked.second + 1;
    }
    segs.push_back({left, n - 1});

    return 0;
}