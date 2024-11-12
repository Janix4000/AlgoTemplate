#include <bits/stdc++.h>

using namespace std;


int main() {
    int t;
    cin >> t;

    while(t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int dx = c- a;
        int dy = d - b;


        int res = 0;

        if(dy < 0) {
            res = -1;
        } else {
            if(dx < 0) {
                res = dy + dy - dx;
            } else {
                if(dx > dy) {
                    res = -1;
                } else {
                    res = dy + (dy - dx);
                }
            }
        }
        cout << res << endl;
    }
}