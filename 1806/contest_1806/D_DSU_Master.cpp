#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
#define all(x) (x).begin(), (x).end()

int sol(vi& tab) {
    int n = tab.size();

    

}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vi tab(2 * n);
        for (size_t i = 0; i < 2 * n; i++)
        {
            cin >> tab[i];
        }

        cout << sol(tab) << endl;

        
    }
}