#include <bits/stdc++.h>

template <typename... Ts>
void __print(Ts &&...ts) {}
#ifdef DEBUG
#include "print.hpp"
#endif  // DEBUG

using namespace std;

template <class T>
using pq_max = priority_queue<T>;
template <class T>
using pq_min = priority_queue<T, vector<T>, greater<T>>;

#define FOR(i, a, b) for (int i = a; i < (b); ++i)
#define F0R(i, a) for (int i = 0; i < (a); ++i)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; --i)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; --i)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define all(x) x.begin(), x.end()

#define GET_FOR(_1, _2, _3, NAME, ...) NAME
#define loop(...) GET_FOR(__VA_ARGS__, FOR, F0R)(__VA_ARGS__)

#define GET_FORd(_1, _2, _3, NAME, ...) NAME
#define loopr(...) GET_FOR(__VA_ARGS__, FORd, F0Rd)(__VA_ARGS__)

#define sz(x) ((int)(x).size())

using ll = long long;
template <typename T>
using vec = vector<T>;
template <typename T, size_t N>
using arr = array<T, N>;

using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

using pi = pair<int, int>;
using pl = pair<ll, ll>;

///////////////////////////////////////////////////////////////////////////////////////////////
template <typename T = long long>
class SegTree {
   public:
    int size = 0;
    vec<T> tree;
    vec<T> bag;
    const T neutral = T(0);

   public:
    SegTree(int n) { calculate_size(n); }

    SegTree(const vec<T> &tab) {
        const int n = (int)tab.size();
        calculate_size(n);
        for (int i = 0; i < n; i++) {
            tree[2 * i + 1] = tab[i];
        }
        update_from_roots(0, size);
    }
    void modify(int l, int r, const T &v) { modify(l, r, 0, size, v); }

    T query(int l, int r) { return query(l, r, 0, size); }

    T find(T val) {}

    T find(int b, int e, T val) {
        const int be = (e - b) / 2;
        if (b == e - 1) {
            return b;
        }
        if (tree[b + b + be] <= val) {
            return find(b, b + be, val);
        } else {
            return find(b + be, e, val);
        }
    }

   private:
    void modify(int l, int r, int b, int e, const T &v) {
        if (l >= e || r <= b) {
            return;
        }
        if (b >= l && e <= r) {
            update_whole_segment(b, e, v);
        } else {
            propagate_bag(b, e);
            const int be = (e - b) / 2;
            modify(l, r, b, b + be, v);
            modify(l, r, b + be, e, v);
            // MODIFY
            tree[b + e] = tree[b + b + be] + tree[b + be + e];
        }
    }
    void update_whole_segment(int b, int e, const T &v) {
        const int n = e - b;
        // MODIFY
        tree[b + e] += n * v;
        bag[b + e] += v;
    }
    T query(int l, int r, int b, int e) {
        if (l >= e || r <= b) {
            return neutral;
        }
        if (b >= l && e <= r) {
            return tree[b + e];  // + (e - b) * bag[b + e];
        } else {
            int be = (e - b) / 2;
            propagate_bag(b, e);
            const auto left_query = query(l, r, b, b + be);
            const auto right_query = query(l, r, b + be, e);

            // MODIFY
            return left_query + right_query;
        }
    }
    void propagate_bag(int b, int e) {
        const int be = (e - b) / 2;
        const int n = e - b;
        if (bag[b + e] != neutral) {
            const T add = bag[b + e];
            bag[b + e] = neutral;

            // MODIFY
            tree[b + b + be] += n * add / 2;
            tree[b + be + e] += n * add / 2;

            bag[b + b + be] += add;
            bag[b + be + e] += add;
        }
    }
    void update_from_roots(int l, int r) {
        if (r - l > 1) {
            int lr = (r - l) / 2;
            update_from_roots(l, l + lr);
            update_from_roots(l + lr, r);
            // MODIFY
            tree[l + r] = tree[l + l + lr] + tree[l + lr + r];
        }
    }
    void calculate_size(int n) {
        n -= 1;
        size = 1;
        while (n > 0) {
            size *= 2;
            n /= 2;
        }
        const int whole_size = size * 2;
        tree.clear();
        tree.resize(whole_size, neutral);
        bag.clear();
        bag.resize(whole_size, neutral);
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////

class Solution {};

struct dfs {
    vvi &graph;
    unordered_map<int, vec<arr<int, 3>>> &qs;
    vi &tab;
    set<pi> cnt;
    vi cs_to_a;
    vi lookup;
    vi ans;
    SegTree<int> stree;
    dfs(vvi &graph, unordered_map<int, vec<arr<int, 3>>> &qs, vi &tab)
        : graph(graph), qs(qs), stree(graph.size()), tab(tab) {
        int n = sz(graph);
        lookup = vi(n, 0);
        ans = vi(sz(qs));
        cs_to_a = vi(n, -1);
        dfs_rec(0);
    }

    void dfs_rec(int v) {
        int n = sz(graph);
        int a = tab[v] - 1;
        int k = lookup[a];
        if (auto it = cnt.find({k, a}); it != cnt.end()) {
            cnt.erase(it);
        }
        cnt.emplace(k + 1, a);
        cs_to_a[k + 1] = v;
        lookup[a]++;
        stree.modify(k, n, -1);
        stree.modify(k + 1, n, 1);
        for (auto [idx, l, k] : qs[v]) {
            int to_remove = stree.query(0, l + 1);
            int to_find = to_remove + k;
            int cs = stree.find(to_find);
            int res = cs_to_a[cs];
            ans[idx] = res;
        }

        for (int e : graph[v]) {
            dfs_rec(e);
            cs_to_a[k + 1] = v;
        }

        lookup[a]--;
        cnt.erase({k + 1, a});
        cnt.emplace(k, a);
        stree.modify(k + 1, n, -1);
        stree.modify(k, n, 1);
    }
};

void solution() {
    int n, q;
    cin >> n >> q;

    vi tab(n);
    loop(i, n) {
        int a;
        cin >> a;
        a--;
        tab[i] = a;
    }
    vvi graph(n, vi());
    loop(i, 1, n) {
        int p;
        cin >> p;
        p--;
        graph[p].push_back(i);
    }
    unordered_map<int, vec<arr<int, 3>>> qs;
    loop(i, q) {
        int v, l, k;
        cin >> v >> l >> k;
        v--;
        qs[v].push_back({i, l, k});
    }

    auto d = dfs(graph, qs, tab);

    for (int res : d.ans) {
        cout << res + 1 << '\n';
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;
    cin >> qs;

    while (qs--) {
        solution();
    }

    // Solution solution;
    return 0;
}