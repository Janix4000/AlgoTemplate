#include <bits/stdc++.h>
using namespace std;

constexpr int N = int(1e5) + 1;

using ll = long long;
using ull = unsigned long long;
template <typename T>
using vec = vector<T>;
using veci = vec<int>;

int main(void)
{
    int qs = 1;
    cin >> qs;
    while (qs--)
    {
        int n, k;
        cin >> n >> k;
        vec<pair<ll, int>> to_sort(n);
        for (int i = 0; i < n; i++)
        {
            cin >> to_sort[i].first;
            // scanf("%lld", &(to_sort[i].first));
            to_sort[i].second = i;
        }
        sort(to_sort.begin(), to_sort.end());
        int count = 0;
        for (int i = 0; i < n; ++i)
        {
            count++;
            for (; i < n; ++i)
            {
                if (i == n - 1)
                {
                    break;
                }
                if (to_sort[i].second > to_sort[i + 1].second)
                {
                    break;
                }
            }
        }
        cout << (count <= k ? "YES" : "NO") << '\n';
    }
    return 0;
}