#include <vector>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

struct get_scc {
    vi scc;
    vi in, low, vis, stack;
    int scc_n = 0, t = 0;

    get_scc(vvi& graph) {
        int n = graph.size();
        in = low = scc = vi(n, -1);
        vis = vi(n, false);

        for (int v = 0; v < n; v++)
            if (in[v] == -1) tarjan(v, graph);
    }

    void tarjan(int v, vvi& graph) {
        low[v] = in[v] = t++;
        stack.push_back(v);
        vis[v] = true;
        for (int u : graph[v]) {
            if (in[u] == -1) {
                tarjan(u, graph);
                low[v] = min(low[v], low[u]);
            } else if (vis[u])
                low[v] = min(low[v], in[u]);
        }
        if (low[v] == in[v]) {
            for (;;) {
                int u = stack.back();
                stack.pop_back();
                vis[u] = false;
                scc[u] = scc_n;
                if (u == v) break;
            }
            scc_n++;
        }
    }
};

struct two_sat {
    vvi graph;
    vi value;
    two_sat(int n_vars) {
        graph = vvi(2 * n_vars);
        value = vi(n_vars);
    }
    bool neg(int a) { return a < 0; }
    void add_constr(int a, int b) {
        graph[2 * abs(a) + neg(a)].push_back(2 * b + 1 - neg(b));
        graph[2 * abs(b) + neg(b)].push_back(2 * a + 1 - neg(a));
    }
    bool solve(int n_vars) {
        auto scc = get_scc(graph);
        vi v, c;
        v = c = vi(scc.scc_n, -1);
        for (int i = 0; i < n_vars; ++i)
            if (scc.scc[2 * i] == scc.scc[2 * i + 1]) return false;
        for (int i = 0; i < 2 * n_vars; ++i) v[scc.scc[i]] = i;
        for (int i = 0; i < scc.scc_n; ++i)
            if (c[i] == -1) {
                c[i] = 1;
                c[scc.scc[v[i] ^ 1]] = 0;
            }
        for (int i = 0; i < n_vars; ++i) value[i] = c[scc.scc[2 * i + 1]];
        return true;
    }
};

// 2SAT usage:
// 1) n = 2*variables
// 2) REP(i,n) g[i].clear();
// 3) add_constr(...) //np. add_constr(zm1, 1, zm2, 0) = ((NOT zm1) OR zm2)
// 4) solve_2sat();
void add_constr(int a, bool neg_a, int b, bool neg_b) {
    g[2 * a + neg_a].push_back(2 * b + 1 - neg_b);
    g[2 * b + neg_b].push_back(2 * a + 1 - neg_a);
}
bool solve_2sat() {
    tarjan_scc();
    int v[scc_n], c[scc_n];
    REP(i, (n / 2)) if (scc[2 * i] == scc[2 * i + 1]) return false;
    REP(i, n) v[scc[i]] = i;
    REP(i, scc_n) c[i] = -1;
    REP(i, scc_n) if (c[i] == -1) {
        c[i] = 1;
        c[scc[v[i] ^ 1]] = 0;
    }
    REP(i, (n / 2)) value[i] = c[scc[2 * i + 1]];
    return true;
}