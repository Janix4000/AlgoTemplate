#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

void solution()
{
    int n;
    cin >> n;
    vector<int> cards(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cards[i];
    }
    sort(all(cards));
    vector<char> used(n, 0);
    int best_res = 0;
    for (int i = 0; i < n; i++)
    {
        int c = cards[i];
        if (used[i])
        {
            continue;
        }
        used[i] = true;
        int res = cards[i];
        for (int k = i + 1; k < n; ++k)
        {
            res += (cards[k] / c) * c;
            if (cards[k] % c == 0)
            {
                used[k] = 0;
            }
        }
        if (res > best_res)
        {
            best_res = res;
        }
    }
    cout << best_res << endl;
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