#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;
using ld = long double;

#define all(x) (x).begin(), (x).end()

using pi = pair<int, int>;
using vpi = vector<pi>;

using It = string::iterator;
std::vector<int> get_kmp(It beg, It end) {
    const size_t size = end - beg;
    std::vector<int> tab(size + 1);
    tab[0] = -1;
    int k = -1;

    for (size_t i = 0; i < size; ++i) {
        while (k != -1 && beg[k] != beg[i]) k = tab[k];
        tab[i + 1] = ++k;
    }
    return tab;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    auto kmp = get_kmp(all(s));

    map<int, int> counter;
    for (int i = 0; i < kmp.size(); ++i) {
        if (kmp[i] == 0) continue;
        counter[kmp[i]]++;
    }

    for (int i = 0; i < kmp.size(); i++) {
        cerr << kmp[i] << " ";
    }
    cerr << endl;

    int a = kmp.back();

    map<int, int> sol;
    int prev = 0;

    while (a != -1) {
        sol[a] = prev + counter[a];
        prev = sol[a];
        a = kmp[a];
    }

    sol.erase(0);

    cout << sol.size() + 1 << endl;

    for (auto [k, v] : sol) {
        cout << k << " " << v + 1 << endl;
    }
    cout << s.size() << " " << 1 << endl;

    return 0;
}