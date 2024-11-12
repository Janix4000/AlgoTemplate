#include <bits/stdc++.h>

using namespace std;


using vi = vector<int>;
#define all(x) (x).begin(), (x).end()

int main() {

    int k;
    cin >> k;

    while (k--)
    {
        int n;
        cin >> n;
        vi t(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> t[i];
        }
        sort(all(t));

        int mint = t.front();
        int maxt = t.back();



        int mins = 0, maxs=0;
        for (size_t i = 0; i < n; i++)
        {
            if(t[i] == mint) {
                mins++;
            }
            if(t[i] == maxt) {
                maxs++;
            }
        }
        // cerr << mins  << ' ' << maxs << endl;
        if(maxt == mint) {
            cout << (mins-1) * 1ll * maxs << endl;
        } else {
            cout << mins * 1ll *  maxs * 2 << endl;
        }
        /* code */
    }
    
    
}