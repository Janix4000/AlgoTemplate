#include "bits/stdc++.h"
using namespace std;
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

template <typename T>
void ___print(const SegTree<T> &tree) {
    const int n = tree.size;
    int k = n;
    while (k > 0) {
        cerr << (k == n ? "" : "\n");
        int f = 0;
        for (int i = 0; i < n; i += k) {
            cerr << (f++ ? " " : ""), ___print(tree.tree[i + i + k]);
        }
        k /= 2;
    }
}