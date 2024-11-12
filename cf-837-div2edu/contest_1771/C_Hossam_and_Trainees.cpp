#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
#define all(x) (x).begin(), (x).end()

using ll = long long;

int main() {
    int k;
    cin >> k;

    vi primes = {2, 3, 5};

    {
        int p = 5;
        while (p * p <= int(1e9) + 20) {
            p += 2;
            bool cont = false;
            for (int h : primes) {
                if (p % h == 0) {
                    cont = true;
                    break;
                }
            }
            if (cont) {
                continue;
            }
            primes.push_back(p);
        }
    }

    while (k--) {
        int n;
        cin >> n;

        vi t(n);

        bool sol = false;

        for (size_t i = 0; i < n; i++) {
            cin >> t[i];
        }

        sort(all(t));

        // cerr << primes.back() << endl;for

        set<int> used_primes;

        for (int el : t) {
            for (int p : primes) {
                if (p * 1ll * p > el) {
                    break;
                }
                if (el % p == 0) {
                    if (used_primes.count(p)) {
                        sol = true;
                        break;
                    }
                    used_primes.insert(p);
                    while (el % p == 0) {
                        el /= p;
                    }
                }
            }
            if (el != 1) {
                if (used_primes.count(el)) {
                    sol = true;
                    break;
                }
                used_primes.insert(el);
            }

            if (sol) {
                break;
            }
        }

        cout << (sol ? "YES" : "NO") << endl;
    }
}