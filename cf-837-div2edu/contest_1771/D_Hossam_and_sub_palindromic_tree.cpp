#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
#define all(x) (x).begin(), (x).end()

using ll = long long;
using pi = pair<int, int>;

struct Node
{
    int from, to, next, prev;

    bool operator>(const Node& rhs) const {
        return true;
    }
    bool operator<(const Node& rhs) const {
        return true;
    }
};


int main()
{

    int k;
    cin >> k;


    while (k--)
    {
       int n;
       cin >> n;

       string s; 
       s.reserve(n);
       cin >> s;

        vvi G(n);
        for (size_t i = 0; i < n -1; i++)
        {
            int a, b;
            cin >> a >> b;
            G[a-1].push_back(b-1);
            G[b-1].push_back(a-1);
        }

        vvi dp(n, vi(n, -1));
        vvi vis(n, vi(n, false));

        queue<Node> q;

        for (int i = 0; i < n; i++)
        {
            q.push(Node{i, i, -1, -1});
        }

        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            vis[node.from][node.to] = true;

            if(node.from == node.to) {
                dp[node.from][node.to] = 1;
            } else {
                if(s[node.from] == s[node.to]) {
                    if(node.next == node.to) {
                        dp[node.from][node.to] = 2;
                    } else {
                        dp[node.from][node.to] = dp[node.next][node.prev] + 2;
                    }
                } else {
                    dp[node.from][node.to] = max(dp[node.from][node.prev], dp[node.next][node.to]);
                }
            }
            for(int e : G[node.to]) {
                if(vis[node.from][e]) {
                    continue;
                }
                vis[node.from][e] = true;
                int nxt = node.from == node.to ? e : node.next;
                q.push(Node{node.from, e, nxt, node.to});
            }
        }

        int sol = 0;

        for (int v = 0; v < n; v++)
        {
            for (int e = 0; e < n; e++)
            {
                sol = max(sol, dp[e][v]);
            }
        }

        cout << sol << endl;
    }
}