#include <bits/stdc++.h>

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

struct Exp
{
    int k;
    double p;
    bool operator<(const Exp &rhs) const
    {
        return k < rhs.k;
    }
};

void solution()
{
    int n, m;
    cin >> n >> m;
    vector<int> tab(n);
    int most_right = n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a != i + 1)
        {
            most_right = i;
        }
    }
    double fail_chance = (most_right == n ? 0 : 1);
    for (int i = 0; i < m; i++)
    {
        int k;
        double p;
        cin >> k >> p;
        if (k > most_right)
        {
            fail_chance *= (1 - p);
        }
    }
    cout
        << 1 - fail_chance << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;
    cin >> qs;

    cout << setprecision(10);

    while (qs--)
    {
        solution();
    }
    return 0;
}