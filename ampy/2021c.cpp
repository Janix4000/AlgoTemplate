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

using vs = vector<string>;
using vvs = vector<vs>;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vpi = vector<pi>;

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

ll _mergeSort(vi& arr, vi& temp, int left, int right);
ll merge(vi& arr, vi& temp, int left, int mid, int right);
 
ll mergeSort(vi& arr)
{
    vi temp(arr.size());
    return _mergeSort(arr, temp, 0, arr.size() - 1);
}
 
ll _mergeSort(vi& arr, vi& temp, int left, int right)
{
    ll mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}
 
ll merge(vi& arr, vi& temp, int left, int mid, int right)
{
    int i = left, j = mid, k = left;
    ll inv_count = 0;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
    return inv_count;
}

void solution() {
    int n; cin >> n;
    vvi in(2, vi(n));
    vvi tg(2, vi(n));

    for (size_t k = 0; k < 2; k++)
    {
        for (size_t i = 0; i < n; i++)
        {
            cin >> in[k][i];
        }
    }
    for (size_t k = 0; k < 2; k++)
    {
        for (size_t i = 0; i < n; i++)
        {
            cin >> tg[k][i];
        }
    }
    map<pi, vi> ids;
    for (size_t i = 0; i < n; i++)
    {
        int a = tg[0][i];
        int b = tg[1][i];
        if(i % 2) swap(a, b);
        ids[{a, b}].push_back(i);
    }
    vi res(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int a = in[0][i];
        int b = in[1][i];
        if(i % 2) swap(a, b);
        auto it = ids.find({a, b}); 
        if(it == ids.end() || it->second.empty()) {
            res.clear();
            break;
        }
        int idx = it->second.back();
        it->second.pop_back();
        res[i] = idx;
    }


    if(res.empty()) {
        cout << -1 << endl;
    } else {
        cout << mergeSort(res) << endl;
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
    return 0;
}