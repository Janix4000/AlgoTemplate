#include <bits/stdc++.h>

constexpr int N = int(1e6) + 1;
using ll = long long;
using ull = unsigned long long;

using namespace std;
int main(void)
{
    int n;
    cin >> n;

    int max_count = 0;
    while (true)
    {
        string s;
        cin >> s;
        vector<string> strings;
        int count_cap = count_if(s.begin(), s.end(), [](char c)
                                 { return c < 'a'; });
        max_count = max(max_count, count_cap);
        n -= s.size() + 1;
        if (n <= 0)
        {
            break;
        }
    }

    cout << max_count;
    return 0;
}