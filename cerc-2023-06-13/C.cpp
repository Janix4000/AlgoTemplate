#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;

#define all(x) (x).begin(), (x).end()

#define OVER ((1ll << 32) - 1)

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L;
    cin >> L;

    string s;
    vi cs;
    ll iters = 1;
    ll sum = 0;
    int overflowing = 0;
    bool over = false;
    for (int i = 0; i < L; i++) {
        string s;
        cin >> s;
        int counter = 1;
        if (s == "for") {
            cin >> counter;
            cs.push_back(counter);
            if (iters * counter > OVER || overflowing > 0) {
                overflowing++;
            } else {
                iters *= counter;
            }
        } else if (s == "end") {
            if (overflowing > 0) {
                overflowing--;
            } else {
                iters /= cs.back();
            }
            cs.pop_back();
        } else if (s == "add") {
            if (overflowing > 0) {
                over = true;
            } else {
                sum += iters;
            }
            if (sum > OVER) {
                over = true;
            }
        }
    }

    if (over) {
        cout << "OVERFLOW!!!" << endl;
        return 0;
    }
    cout << sum << endl;

    return 0;
}