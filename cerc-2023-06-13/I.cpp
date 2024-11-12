#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

#define all(x) (x).begin(), (x).end()

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;

    cin >> a;
    vi as(a);
    for (int i = 0; i < a; i++) {
        cin >> as[i];
    }

    cin >> b;
    vi bs(b);
    for (int i = 0; i < b; i++) {
        cin >> bs[i];
    }

    sort(all(as));
    sort(all(bs));

    int res = 0;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (abs(as[i] - bs[j]) <= 1) {
                res++;
                bs[j] = 1000;
                break;
            }
        }
    }

    cout << res << endl;

    return 0;
}