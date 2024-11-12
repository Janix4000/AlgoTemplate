#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
#define all(x) (x).begin(), (x).end()

int sol(vi& tab) {
    sort(all(tab));


    if (tab.size() == 1) {
        return tab[0] == 0 ? 1 : 0;
    } 

    int zeros = count(all(tab), 0);
    if(zeros <= (tab.size() + 1) / 2) {
        return 0;
    }

    int ones = count(all(tab), 1);
    if(ones == 0) {
        return 1;
    }
    if(ones + zeros == tab.size()) {
        return 2;
    }

    return 1;

}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vi tab(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> tab[i];
        }

        cout << sol(tab) << endl;

        
    }
}