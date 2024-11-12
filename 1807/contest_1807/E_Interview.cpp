#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
#define all(x) (x).begin(), (x).end()



int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vi as(n);

        for (int i = 0; i < n; i++)
        {
            cin >> as[i];
        }
        
        vi cs(n + 1, 0);

        partial_sum(all(as), cs.begin() + 1);

        int l=0, r=n;

        while(r-l > 1) {
            int m = (r - l + 1) / 2 + l;
            int k = m - l;

            cout << "? " << k << ' ';
            for (int i = l; i < m; i++)
            {
                cout << i + 1 << ' ';
            }
            cout << endl << endl;

            int mass;
            cin >> mass;

            if(mass != cs[m] - cs[l]) {
                r = m;
            } else {
                l = m;
            }
        }
        cout << "! " << l + 1 << endl << endl;

        

        
    }

    return 0;
}