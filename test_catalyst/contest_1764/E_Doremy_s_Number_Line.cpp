#include <functional>
#include <iostream>
#include <vector>

using namespace std;
// #define int long long
using vi = vector<int>;
#define all(x) (x).begin(), (x).end()

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi as(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> as[i];
        }

        as.back() = -1;
        sort(all(as), greater<>{});
        int prev = as[0];
        int res = 0;
        for (int v = 1; v < n + 1; v++) {
            if (prev != as[v]) {
                const int t = v * (n - v);
                res = max({v / 2, t, res});
                prev = as[v];
            }
        }
        cout << res << endl;
    }
}