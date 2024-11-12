#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;
using ld = long double;

#define all(x) (x).begin(), (x).end()

double pi = 3.1415926536;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<double> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(all(a), greater<double>());
    double times = 1;

    double sol = 0;

    for (int i = 0; i < n; i++) {
        sol += a[i] * a[i] * times;
        times *= -1;
    }

    cout << fixed << setprecision(12) << sol * pi << endl;

    return 0;
}