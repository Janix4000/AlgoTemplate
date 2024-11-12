#include <bits/stdc++.h>

using namespace std;

struct P {
    int x, y;
};

int32_t main() {
    int n;

    cin >> n;

    for (int _ = 0; _ < n; _++) {
        P a, b, c;

        cin.get();
        cin.get();

        cin >> a.x >> a.y;
        cin >> b.x >> b.y;
        cin >> c.x >> c.y;

        int h = true;

        if(a.x == b.x && a.y == c.y) h = false;
        if(b.x == a.x && b.y == c.y) h = false;
        if(c.x == b.x && c.y == a.y) h = false;

        if(a.y == b.y && a.x == c.x) h = false;
        if(b.y == a.y && b.x == c.x) h = false;
        if(c.y == b.y && c.x == a.x) h = false;

        cout << (h ? "YES" : "NO") << endl;
    }
}
