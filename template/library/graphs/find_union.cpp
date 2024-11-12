#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

#define all(x) x.begin(), x.end()

using vi = std::vector<int>;

struct find_union {
    vi par, rank;

    find_union(int n) {
        par = rank = vi(n, 0);
        iota(all(par), 0);
    }

    int find(int a) {
        if (par[a] != a) par[a] = find(par[a]);
        return par[a];
    }

    int unions(int a, int b) {
        a = find(a);
        b = find(b);
        if (rank[b] > rank[a]) swap(a, b);
        par[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
        return a;
    }
};

int find_set(int idx, vi &pars) {
    if (pars[idx] != idx) {
        pars[idx] = find_set(pars[idx], pars);
    }
    return pars[idx];
}
int union_sets(int idx, int idy, vi &pars, vi &ranks) {
    idx = find_set(idx, pars);
    idy = find_set(idy, pars);
    if (ranks[idx] > ranks[idy]) {
        swap(idx, idy);
    }
    pars[idx] = idy;
    if (ranks[idx] == ranks[idy]) {
        ranks[idy]++;
    }
    return idy;
}