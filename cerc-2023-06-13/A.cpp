#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;
    // cin >> qs;

    while (qs--) {
        unsigned price, den;
        cin >> price >> den;
        int best = 10;
        for (unsigned i = 1; i < 10; ++i) {
            if ((i * price % 10) == den || (i * price) % 10 == 0) {
                best = min(best, (int)i);
                break;
            }
        }
        cout << best << endl;
    }

    return 0;
}