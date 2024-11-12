#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
#define all(x) (x).begin(), (x).end()

char farest(char minc, char maxc, char l, char r) {
    if ('9' - minc > maxc - '0') {
        return '9';
    }
    return '0';
}

char best(int l, int r, char minc, char maxc) {
    int best = 0;
    char res = 0;
    for (char k = l; k < r + 1; k++) {
        int cand = max({abs(maxc - k), abs(k - minc), r - k, k - l});
        if (best < cand) {
            best = cand;
            res = k;
        }
    }

    return res;
}

string solution(string& l, string& r) {
    int nl = l.size();
    int nr = r.size();

    if (nl != nr) {
        if (nl > 1) {
            l.front() = '9';
            l.back() = '0';
            return l;
        } else {
            if (r.size() > 3) {
                return "90";
            } else {
                int ll = stoi(l);
                int rr = stoi(r);
                int best = 0;
                int res = 0;
                for (int k = ll; k <= rr; k++) {
                    int cand = abs(k / 10 - (k % 10));
                    if (cand > best) {
                        best = cand;
                        res = k;
                    }
                    return to_string(res);
                }
            }
        }
    }

    if (l.size() == 1 || l == r) return l;

    char minc = '9' + 1;
    char maxc = '0' - 1;

    for (int i = 0; i < l.size(); i++) {
        minc = min({minc, l[i], r[i]});
        maxc = max({maxc, l[i], r[i]});

        if (l[i] == r[i]) continue;

        int n = l.size() - i;
        if (n >= 3) {
            l[l.size() - 2] = '0';
            l[l.size() - 2] = '9';
            return l;
        }
        if (n <= 2) {
            int ll = stoi(l.substr(i, n));
            int rr = stoi(r.substr(i, n));
            int best = 0;
            int res = 0;
            for (int k = ll; k <= rr; k++) {
                char a = k / 10 + '0';
                char b = (k % 10) + '0';
                int cand = abs(a - b);
                if (i != 0) {
                    cand = max({cand, abs(minc - a), abs(minc - b),
                                abs(maxc - b), abs(maxc - a)});
                }
                if (cand > best) {
                    best = cand;
                    res = k;
                }
            }
            string sres = to_string(res);
            while (sres.size() < n) {
                sres = '0' + sres;
            }
            return l.substr(0, i) + sres;
        }
    }
    return l;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string l, r;
        cin >> l >> r;

        cout << solution(l, r) << endl;
    }

    return 0;
}