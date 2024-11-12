#include <bits/stdc++.h>

#include <vector>

template <typename... Ts>
void __print(Ts &&...ts) {}
#ifdef DEBUG
#include "print.hpp"
#endif  // DEBUG

using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) ((int)(x).size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

using pi = pair<int, int>;
using pl = pair<ll, ll>;

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

class Solution {};

// using El = array<int, 3>;
// El e = {-1, -1, -1};
// El op(El& a, El& b) {
//     array<int, 6> c = {a[0], a[1], a[2], b[0], b[1], b[2]};
//     sort(all(c), greater<>{});
//     return {c[0], c[1], c[2]};
// }
// struct SegmentPointTree {
//     vector<El> tree;
//     size_t base;
//     SegmentPointTree(int n) {
//         base = 1 << int(log2(n - 1) + 1);
//         tree = {base * 2 + 1, e};
//     }
//     void update(size_t l, size_t r, El x) { // inclusive
//         l += base - 1;
//         r += base + 1;
//         while(r - l > 1) {
//             if(!(l & 1)) tree[l + 1] = op(tree[l+1], x);
//             if((r & 1)) tree[r - 1] = op(tree[r-1], x);
//             l /= 2;
//             r /= 2;
//         }
//     }
//     El get(int v) { // [0, n-1]
//         v += base; El rr = e;
//         while(v) {
//             rr = op(rr, tree[v]); v /= 2;
//         }
//         return rr;
//     }
// };

template <typename T>
using vec = vector<T>;

// using El = int;
// El e = 0;
// El op(const El &a, const El &b) { return a + b; }
// El op_pow(const El &a, size_t n) { return a * n; }
// class SegTree {
//    public:
//     size_t base = 0;
//     vec<El> tree, bag;
//     SegTree(size_t n) {
//         base = 1 << int(log2(n - 1) + 1);
//         tree = bag = vec<El>(base * 2 + 1, e);
//     }
//     void modify(int l, int r, const El &v) { modify(l, r, 0, base, v); }
//     El query(int l, int r) { return query(l, r, 0, base); }

//    private:
//     void modify(int l, int r, int beg, int end, const El &v) {
//         if (l >= end || r <= beg) {
//             return;
//         }
//         if (beg >= l && end <= r) {
//             update_whole_segment(beg, end, v);
//         } else {
//             propagate_bag(beg, end);
//             const int be = (end - beg) / 2;
//             modify(l, r, beg, beg + be, v);
//             modify(l, r, beg + be, end, v);
//             tree[beg + end] = op(tree[beg + beg + be], tree[beg + be + end]);
//         }
//     }
//     void update_whole_segment(int beg, int end, const El &v) {
//         const int n = end - beg;
//         tree[beg + end] = op(tree[beg + end], op_pow(v, n));
//         bag[beg + end] = op(bag[beg + end], v);
//     }
//     El query(int l, int r, int beg, int end) {
//         if (l >= end || r <= beg) {
//             return e;
//         }
//         if (beg >= l && end <= r) {
//             return tree[beg + end];  // + (end - beg) * bag[beg + end];
//         } else {
//             int be = (end - beg) / 2;
//             propagate_bag(beg, end);
//             const auto left_query = query(l, r, beg, beg + be);
//             const auto right_query = query(l, r, beg + be, end);

//             return op(left_query, right_query);
//         }
//     }
//     void propagate_bag(int beg, int end) {
//         const int be = (end - beg) / 2;
//         const int n = end - beg;
//         if (bag[beg + end] != e) {
//             const El add = bag[beg + end];
//             bag[beg + end] = e;

//             El bagged_add = op_pow(add, n / 2);
//             tree[beg + beg + be] = op(tree[beg + beg + be], bagged_add);
//             tree[beg + be + end] += op(tree[beg + be + end], bagged_add);

//             bag[beg + beg + be] = op(bag[beg + beg + be], add);
//             bag[beg + be + end] = op(bag[beg + be + e], add);
//         }
//     }
// };

struct A {
    int &a;
    A(int &a) : a(a) {}
};

using El = int;
El e = 0;
El op(const El &a, const El &b) { return a + b; }
El op_pow(const El &a, size_t n) { return a * n; }
class SegTree {
   public:
    size_t base = 0;
    vec<El> tree, bag;
    SegTree(size_t n) {
        base = 1 << int(log2(n - 1) + 1);
        tree = bag = vec<El>(base * 2 + 1, e);
    }
    void modify(int l, int r, const El &v) {
        modify(l, r, 0, base, v);
    }                                                        // r exclusive
    El query(int l, int r) { return query(l, r, 0, base); }  // r exclusive

   private:
    void modify(int l, int r, int beg, int end, const El &v) {
        if (beg + end == 9) {
            int a = 1;
        }
        if (l >= end || r <= beg) {
            return;
        }
        if (beg >= l && end <= r) {
            update_whole_segment(beg, end, v);
        } else {
            propagate_bag(beg, end);
            const int be = (end - beg) / 2;
            modify(l, r, beg, beg + be, v);
            modify(l, r, beg + be, end, v);
            tree[beg + end] = op(tree[beg + beg + be], tree[beg + be + end]);
        }
    }
    void update_whole_segment(int beg, int end, const El &v) {
        const int n = end - beg;
        tree[beg + end] = op(tree[beg + end], op_pow(v, n));
        bag[beg + end] = op(bag[beg + end], v);
    }
    El query(int l, int r, int beg, int end) {
        if (l >= end || r <= beg) {
            return e;
        }
        if (beg >= l && end <= r) {
            return tree[beg + end];
        } else {
            int be = (end - beg) / 2;
            propagate_bag(beg, end);
            const auto left_query = query(l, r, beg, beg + be);
            const auto right_query = query(l, r, beg + be, end);

            return op(left_query, right_query);
        }
    }
    void propagate_bag(int beg, int end) {
        const int be = (end - beg) / 2;
        if (bag[beg + end] != e) {
            const El add = bag[beg + end];
            El bagged_add = op_pow(add, (end - beg) / 2);

            bag[beg + end] = e;
            tree[beg + beg + be] = op(tree[beg + beg + be], bagged_add);
            tree[beg + be + end] += op(tree[beg + be + end], bagged_add);

            bag[beg + beg + be] = op(bag[beg + beg + be], add);
            bag[beg + be + end] = op(bag[beg + be + end], add);
        }
    }
};

void solution() {
    // int n;
    // cin >> n;

    // SegmentPointTree tree(n);

    // for (int i = 0; i < n; i++) {
    //     int rad, s;
    //     cin >> rad >> s;
    //     int l = max(0, i - rad);
    //     int r = min(n - 1, i + rad);

    //     El el = {s, -1, -1};
    //     tree.update(l, r, el);
    // }

    // int rr = 0;
    // for (int i = 0; i < n; i++) {
    //     auto el = tree.get(i);
    //     if (el[2] == -1) continue;
    //     rr = max(rr, el[0] + el[1] + el[2]);
    // }

    // cout << rr << endl;

    SegTree tree(10);

    tree.modify(0, 10, 1);
    tree.modify(0, 5, 1);

    cout << tree.query(0, 10) << endl;
    cout << tree.query(0, 0) << endl;
    cout << tree.query(0, 5) << endl;
    cout << tree.query(5, 10) << endl;
    cout << tree.query(10, 10) << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;
    // cin >> qs;

    while (qs--) {
        solution();
    }

    return 0;
}