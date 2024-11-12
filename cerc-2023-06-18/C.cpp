#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;
using ld = long double;

#define all(x) (x).begin(), (x).end()

using pi = pair<int, int>;
using vpi = vector<pi>;

struct Node {
    int count = 0;
    map<pi, Node> children;
};

map<int, int> get_primes(int n) {
    map<int, int> res;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            res[i]++;
            n /= i;
        }
    }
    if (n > 1) res[n]++;
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    Node root;
    vi as(n);
    vector<map<int, int>> primess(n);

    for (int i = 0; i < n; i++) {
        cin >> as[i];
        primess[i] = get_primes(as[i]);

        Node* node = &root;
        for (auto pn : primess[i]) {
            if (pn.second % k == 0) continue;

            node = &node->children[{pn.first, pn.second % k}];
        }
        node->count++;
    }

    ll res = 0;

    for (auto& primes : primess) {
        Node* node = &root;
        bool found = true;
        bool same = true;
        for (auto& pn : primes) {
            int q = pn.second % k;
            int r = (k - q) % k;
            if (q == 0) continue;
            same = same && (q == r);
            auto it = node->children.find({pn.first, r});
            if (it != node->children.end()) {
                node = &it->second;
            } else {
                found = false;
                break;
            }
        }
        if (found) {
            res += node->count - same;
        }
    }

    cout << res / 2 << endl;

    return 0;
}