#include <bits/stdc++.h>

using namespace std;


using vi = vector<int>;
#define all(x) (x).begin(), (x).end()

using ll = long long;

int main() {

    int k;
    cin >> k;

    while (k--)
    {
        int n, m;
        cin >> n >> m;
        vi lims(n, n);
        for (size_t i = 0; i < m; i++)
        {
            int a, b;

            cin >> a >> b;
            int lim = max(a, b) - 1;
            int idx = min(a, b) - 1;

            lims[idx] = min(lims[idx], lim);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            lims[i] = min(lims[i], lims[i + 1]);
        }


        ll sol = 0;
        for (size_t i = 0; i < n; i++)
        {
            sol += lims[i] - i;
        }
        
        cout << sol << endl;
    }
    
    
}