#include <bits/stdc++.h>

using namespace std;

using ll = long long;
// using vi = vector<int>;
using vl = vector<ll>;
using vvl = vector<vl>;
#define all(x) (x).begin(), (x).end()

int main() {
    int t;
    cin >> t;

    while (t--) {
       int n, m;
       cin >> n >> m;
        vvl cards(m, vl(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> cards[j][i];
            }
        }

        ll sol = 0;

        for (int i = 0; i < m; i++)
        {
            auto& row = cards[i];
            sort(all(row));

            vl cum(n);
            for (int j = 0; j < n; j++)
            {
                cum[j] = row[j] - row[0];
            }
            partial_sum(all(cum), cum.begin());
            ll partial = cum.back();
            for (int j = 1; j < n; j++)
            {
                ll a = cum.back() - cum[j - 1];
                ll b = ((n - j) * (row[j] - row[0]));
                partial += a - b;
            }

            sol += partial;
            


        }

        cout << sol << endl;


        

    }

    return 0;
}