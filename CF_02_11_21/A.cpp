#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, b) FOR(i, 0, b)

using ll = long long;
template <typename T>
using vec = vector<T>;
using vi = vec<int>;
using vvi = vec<vi>;
using viii = vec<vvi>;

void solution()
{
    string s;
    cin >> s; // aaabababbbbbabbbabbbaaaabbaaa
    if (s.front() != s.back())
    {
        auto it = find(all(s), s.front() == 'a' ? 'b' : 'a');
        auto rev_it = find(allr(s), s.back() == 'a' ? 'b' : 'a');
        if (it - s.begin() < rev_it - s.rbegin())
        {
            fill(s.begin(), it, s.front() == 'a' ? 'b' : 'a');
        }
        else
        {
            fill(s.rbegin(), rev_it, s.back() == 'a' ? 'b' : 'a');
        }
    }
    cout << s << endl;
}

int main()
{
    int qs = 1;
    cin >> qs;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (qs--)
    {
        solution();
    }
}