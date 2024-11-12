#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;
using ld = long double;

#define all(x) (x).begin(), (x).end()

using pi = pair<int, int>;
using vpi = vector<pi>;

int n_pref(int a, int b) {
    int c = a ^ b;
    return __builtin_clz(c);
}

template <class T>
using pq_min = priority_queue<T, vector<T>, greater<T>>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi as(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
    }

    int cost = 0;

    pq_min<pi> pq;

    int idx = 0;
    for (int i = 1; i < n; i++) {
        pq.push({as[i] ^ as[0], i});
    }

    while (pq.size()) {
        auto [pref, i] = pq.top();
        pq.pop();

        cost += as[idx] ^ as[i];
        vi kkk;
        if (pq.size() && pq.top().first != 32) {
            while (pq.size() && pq.top().first == pref) {
                auto [_pref, j] = pq.top();
                kkk.push_back(j);
                pq.pop();
            }

            for (int j : kkk) {
                pq.push({n_pref(as[i], as[j]), j});
            }
        }

        idx = i;
    }

    cout << cost << endl;

    return 0;
}