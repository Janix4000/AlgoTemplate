#include <bits/stdc++.h>

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

void solution()
{
    string s;
    cin >> s;
    int res = 0;
    char last = 'a';
    for (char c : s)
    {
        int a = abs(int(last - c));
        res += min(a, 'z' - 'a' + 1 - a);
        last = c;
    }
    cout << res;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;
    // cin >> qs;

    while (qs--)
    {
        solution();
    }
    return 0;
}