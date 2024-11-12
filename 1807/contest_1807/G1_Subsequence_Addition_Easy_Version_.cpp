#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
#define all(x) (x).begin(), (x).end()
using pi = pair<int, int>;

template <typename T>
int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}



int main() {
    int t;
    cin >> t;

    while (t--) {
        int n; 
        cin >>n;
        vi cs(n);
        for (int i = 0; i < n; i++)
        {
            cin >> cs[i];
        }

        if(n == 1) {
            cout << (cs[0] == 1 ? "YES\n" : "NO\n");
            continue;
        }

        if(n == 2) {
            cout << ((cs[0] == 1 && cs[1] == 1) ? "YES\n" : "NO\n");
            continue;
        }

        sort(all(cs));

        vi poss(5001, false);
        poss[1] = 1;
        bool sol = true;
        for (int i = 0; i < n; i++)
        {
            int c = cs[i];
            if(!poss[c]) {
                sol = false;
                break;
            }
            for (int j = 5000; j > 1; j--)
            {
                if(!poss[j]) continue;
                int a = j + c;
                if(a > 5000) break;
                poss[a] = true;
            }
        }

        cout << (sol ? "YES\n" : "NO\n");
        
    }

    return 0;
}