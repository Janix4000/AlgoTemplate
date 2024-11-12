#include <bits/stdc++.h>

#include <vector>

template <typename... Ts>
void __print(Ts&&... ts) {}
#ifdef DEBUG
#include "print.hpp"
#endif  // DEBUG

using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) ((int)(x).size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

using vs = vector<string>;
using vvs = vector<vs>;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vpi = vector<pi>;

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void solution() {
    int n, k;
    cin >> n >> k;
    vi as(n), bs(k);
    for (size_t i = 0; i < n; i++) {
        cin >> as[i];
    }
    for (size_t i = 0; i < k; i++) {
        cin >> bs[i];
    }

    sort(all(bs), greater{});

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(ans.begin(), ans.end(), as[i]);
        if (it == ans.end()) {
            ans.push_back(as[i]);
        } else {
            *it = as[i];
        }
    }

    vi cs(n + k);

    int idx = 0;
    int j = 0;
    int a = 0;
    for (int i = 0; i < n; i++) {
        if (a < ans.size() && as[i] > ans[a]) {
            if (j < k && bs[j] >= as[i]) {
                cs[idx++] = bs[j++];
                i--;
            } else {
                cs[idx++] = as[i];
            }
        } else {
            while (j < k && bs[j] >= as[i]) {
                cs[idx++] = bs[j++];
            }
            cs[idx++] = as[i];
            a++;
        }
    }
    while (j < k) {
        cs[idx++] = bs[j++];
    }

    for (size_t i = 0; i < n + k; i++) {
        cout << cs[i] << ' ';
    }
    cout << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;
    cin >> qs;

    while (qs--) {
        solution();
    }
    return 0;
}