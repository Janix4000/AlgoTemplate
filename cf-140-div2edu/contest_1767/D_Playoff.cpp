#include <bits/stdc++.h>

using namespace std;


using vi = vector<int>;
using vvi = vector<vi>;




int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s;

    cin >> s;


    int low = 1;
    int high = 1;

    for(char c  : s) {
        if(c == '1') {
            low *= 2;
        } else {
            high *= 2;
        }
    }

    high = int(pow(2, n)) - high + 1;

    for (int i = low; i <= high; i++)
    {
        cout << i << ' ';
    }
    cout << endl;

    
    
}
