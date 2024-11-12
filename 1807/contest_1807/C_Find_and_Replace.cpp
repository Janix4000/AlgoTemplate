#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
#define all(x) (x).begin(), (x).end()


int main() {
     int t;
    cin >> t;


    while(t--) {
        int n;
        cin >> n;

        string s;
        s.reserve(n);
        cin >> s;


        char changed['z' - 'a' + 1] = {};

        changed[s[0] - 'a'] = '0';
        s[0] = '0';
        bool sol = true;

        for (int i = 1; i < n; i++)
        {
            char k;
            char c = s[i];
            if(changed[c - 'a'] == 0) {
                k = s[i-1] != '0' ? '0' : '1';
                changed[c - 'a'] = k;
            } else {
                if(s[i-1] == changed[c - 'a']) {
                     sol = false;
                     break;
                } else {
                    k = changed[c - 'a'];
                }
            }
            s[i] = k;
        }
        
        if(sol) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    
    return 0;
}