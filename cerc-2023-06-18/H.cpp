#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;
using ld = long double;

#define all(x) (x).begin(), (x).end()

using pi = pair<int, int>;
using vpi = vector<pi>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    s += 'a';

    string name;
    string price = "";
    int sol = 0;

    bool reading_name = true;
    bool reading_price = false;
    int after_dots = 0;
    bool found_dot = false;

    for (char c : s) {
        bool number = isdigit(c);
        bool letter = isalpha(c);
        bool dot = c == '.';

        if (reading_price && letter) {
            int new_price = stoi(price);
            if (!found_dot || after_dots != 2) {
                new_price *= 100;
            }
            // cerr << "Price: " << new_price << endl;
            sol += new_price;

            after_dots = 0;
            name = "";
            price = "";
            found_dot = false;
        }

        if (reading_name || letter) {
            if (letter) {
                name += c;
            } else {
                reading_name = false;
                reading_price = true;
            }
        }
        if (reading_price) {
            if (number || dot) {
                if (number) {
                    price += c;
                    after_dots++;
                } else {
                    after_dots = 0;
                    found_dot = true;
                }
            } else {
                reading_price = false;
                reading_name = true;
            }
        }
    }

    string s_sol = to_string(sol / 100);

    int k = (3 - s_sol.size() % 3) % 3;
    int idx = 0;
    for (char c : s_sol) {
        cout << c;
        k++;
        if (k == 3 && idx != s_sol.size() - 1) {
            cout << ".";
        }
        k = k % 3;
        idx++;
    }
    if (sol % 100 != 0) {
        cout << ".";
        if (sol % 100 < 10) {
            cout << "0";
        }
        cout << sol % 100;
    }

    cout << endl;

    // cout << sol << endl;

    return 0;
}