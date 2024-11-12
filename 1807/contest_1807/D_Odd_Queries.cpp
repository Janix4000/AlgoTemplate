#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
#define all(x) (x).begin(), (x).end()

template <typename T, T neutral>  // 0, 1, ..., n-1
struct SegTree {
    vector<T> tree;
    int base;
    T op(const T& a, const T& b) { return (a + b) % 2; }
    SegTree(int n) { calculate_size(n); }
    SegTree(const vector<T>& src) {
        calculate_size(src.size());
        copy(src.begin(), src.end(), tree.begin() + base);
        for (size_t v = base - 1; v; --v)  // only for P-S
            tree[v] = op(tree[2 * v], tree[2 * v + 1]);
    }
    void calculate_size(int n) {
        n -= 1;
        base = 1;
        while (n > 0) {
            base *= 2;
            n /= 2;
        }
        tree.assign(base * 2 + 1, neutral);
    }

    void update(size_t v, T x) {
        v += base;
        tree[v] = x;
        v /= 2;
        while (v) {
            tree[v] = op(tree[2 * v], tree[2 * v + 1]);
            v /= 2;
        }
    }

    T query(size_t l, size_t r) {  // inclusive
        T result = neutral;
        l += base - 1;
        r += base + 1;
        while (r - l > 1) {
            if (!(l & 1)) result = op(result, tree[l + 1]);
            if (r & 1) result = op(result, tree[r - 1]);
            l /= 2;
            r /= 2;
        }
        return result % 2;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vi as(n);
        for (int i = 0; i < n; i++)
        {
            cin >> as[i];
        }

        SegTree<int, 0> tree(as);


        for (int i = 0; i < q; i++)
        {
            int l, r, k;
            cin >> l >> r >> k;

            l--; r--;

            k = k % 2;

            int res = tree.query(0, l-1) + tree.query(r+1, n-1) + ((r - l + 1) % 2) * k;
            res = res  %2 ;

            cout << (res ? "YES\n" : "NO\n");

        }
        

        
    }

    return 0;
}