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

    int n;
    cin >> n;
    vector<string> s(n);

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int res = 0;
    char c = 'a';
    int k = s[0].size();
    bool breaking = false;
    for (int i = 0; i < k; i++) {
        c = s[0][i];
        for (int j = 1; j < n; j++) {
            if (s[j][i] != c) {
                breaking = true;
                break;
            }
        }
        if (breaking) break;
        res++;
    }

    cout << res << endl;
    return 0;
}