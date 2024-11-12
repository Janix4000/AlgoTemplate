#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;

#define all(x) (x).begin(), (x).end()

#define OVER ((1ll << 32) - 1)

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L;
    cin >> L;

    vi lefts(L), rights(L);

    for (int i = 0; i < L; i++) {
        string s;
        cin >> s;
        int left = 0, right = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == ')') {
                if (right > 0) {
                    right--;
                } else {
                    left++;
                }
            } else {
                right++;
            }
        }
        lefts[i] = left;

        int left_ = 0, right_ = 0;
        for (int j = s.size() - 1; j >= 0; j--) {
            if (s[j] == '(') {
                if (left_ > 0) {
                    left_--;
                } else {
                    right_++;
                }
            } else {
                left_++;
            }
        }
        rights[i] = right_;
    }

    map<int, int> ls, rs;
    int zs = 0;
    for (int i = 0; i < L; i++) {
        if (lefts[i] == 0 && rights[i] == 0) {
            zs++;
        } else if (lefts[i] > 0 && rights[i] == 0) {
            ls[lefts[i]]++;
        } else if (rights[i] > 0 && lefts[i] == 0) {
            rs[rights[i]]++;
        }
    }

    ll res = 0;
    res += zs * 1ll * zs;
    for (auto l : ls) {
        if (rs.find(l.first) != rs.end()) res += l.second * 1ll * rs[l.first];
    }
    // for (auto r : rs) {
    //     if (ls.find(r.first) != ls.end()) res += r.second * ls[r.first];
    // }

    cout << res << endl;

    return 0;
}