#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;



int main() {
    int n;
    cin >> n;
    map<string, int> names;

    int next_id = 0;

    vi g(n, -1);

    vi ticks(n, 0);

    for (size_t i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;

        int a_i = names.count(a) ? names[a] : next_id++;
        names[a] = a_i;
        
        int b_i = names.count(b) ? names[b] : next_id++;
        names[b] = b_i;

        g[a_i] = b_i;
        ticks[a_i]++;
    }

    queue<int> q;

    for (int v = 0; v < n; v++)
    {
        if(ticks[v]) continue;
        q.push(v);
    }
    if(q.empty()) {
        q.push(0);
    }

    vi taken(n, 0);

    vi leftovers;

    int sol = 0;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        int e = g[v];
        if(taken[v]) continue;
        if(taken[e]) {
            taken[v] = true;
            leftovers.push_back(v);
            continue;
        }
        taken[v] = true;
        taken[e] = true;
        if(g[e] != v) sol++;
        q.push(g[e]);
    }

    for (int v = 0; v < n; v++)
    {
        if()
    }
    
    
    
    
    
}