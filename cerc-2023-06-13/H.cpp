#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;

#define all(x) (x).begin(), (x).end()

#define OVER ((1ll << 32) - 1)

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int gcd = 0;

    for (int i = 0; i < n; i++) {
        gcd = __gcd(unsigned(gcd), unsigned(nums[i]));
    }
    int max_el = *max_element(all(nums)) / gcd;
    int res = (max_el - n - 1) % 2;

    cout << (res ? "Bob" : "Alice") << endl;

    return 0;
}