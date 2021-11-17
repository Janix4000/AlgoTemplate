#include <bits/stdc++.h>

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////
struct FU
{
    vector<int> par;
    vector<int> rank;
    FU(int n) : par(n), rank(n, 0)
    {
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
        }
    }
    int find(int a)
    {
        if (a != par[a])
        {
            par[a] = find(par[a]);
        }
        return par[a];
    }
    void un(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (rank[a] > rank[b])
        {
            par[b] = a;
        }
        else
        {
            par[a] = b;
            if (rank[a] == rank[b])
            {
                rank[b]++;
            }
        }
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////

void solution()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> cs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cs[i];
    }
    FU fu(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        fu.un(a, b);
    }
    map<int, vector<int>> groups;
    for (int i = 0; i < n; ++i)
    {
        groups[fu.par[i]].push_back(i);
    }
    int res = 0;
    for (auto &[par, group] : groups)
    {
        map<int, int> gcs;
        for (int i : group)
        {
            gcs[cs[i]] = gcs[cs[i]] + 1;
        }
        int maxc = 0;
        for (auto &[c, k] : gcs)
        {
            maxc = max(k, maxc);
        }
        res += group.size() - maxc;
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