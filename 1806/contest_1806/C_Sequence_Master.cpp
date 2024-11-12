#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
#define all(x) (x).begin(), (x).end()

int sol(vi& tab) {
    int n = tab.size() / 2;

    if(n == 1) {
        return abs(tab[0] - tab[1]);
    }
    if(n == 2) {
        int sol = 0;
        for (int i = 0; i < n *2; i++)
        {
            sol += abs(tab[i] -2 );
        }
        int alt_sol = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            alt_sol += abs(tab[i]);
        }
        return min(sol, alt_sol);
    }
    int sol = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        sol += abs(tab[i]);
    }
    return sol;


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