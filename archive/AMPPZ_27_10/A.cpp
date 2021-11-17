#include <bits/stdc++.h>

template <typename... Ts>
void __print(Ts &&...ts) {}
#ifdef DEBUG
#include "print.hpp"
#endif // DEBUG

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

void solution()
{
    int k;
    cin >> k;
    int res = 0;
    if (k > 12)
    {
        res = 0;
    }
    else
    {
        for (int x = 1; x <= 6; ++x)
        {
            int y = k - x;
            if (x > y)
            {
                break;
            }
            if (y > 6)
            {
                continue;
            }
            res++;
        }
    }
    cout << res << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;
    cin >> qs;

    while (qs--)
    {
        solution();
    }
    return 0;
}