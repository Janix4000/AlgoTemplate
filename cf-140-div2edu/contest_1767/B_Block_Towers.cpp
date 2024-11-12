#include <bits/stdc++.h>

using namespace std;


using vi = vector<int>;

struct P {
    int x, y;
};

int32_t main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vi tab(n);

        for (int i = 0; i < n; i++)
        {
            cin >> tab[i];
        }

        sort(tab.begin() + 1, tab.end());

        for (int i = 1; i < n; i++)
        {
            if(tab[i] > tab[0]) {
                tab[0] += (tab[i] - tab[0] + 1) / 2;
            }
        }
        cout << tab[0] << endl;        
        

    }




}
