#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int g = 0;
        int m = 0;
        for (size_t i = 0; i < n; i++) {
            int a;
            cin >> a;
            g = gcd(a, g);
            m = max(m, a);
        }
        cout << m / g << '\n';
    }
}