#include <bits/stdc++.h>

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////
template <typename... Ts>
void __print(Ts &&...ts);
#ifdef DEBUG
#include "print.hpp"
#endif // DEBUG
///////////////////////////////////////////////////////////////////////////////////////////////

void solution()
{
    int n;
    cin >> n;
    int k_tries = 0;
    int throw_lvl = -1;
    bool first_checked = false;
    string exc_type = "";
    string exc_msg = "Unhandled Exception";
    bool found = false;
    for (int i = 0; i < n + 1; i++)
    {
        string s;
        getline(cin, s);
        if (s.empty())
        {
            continue;
        }
        s += ' ';
        // cin >> s;
        string word = "";
        vector<string> tokens;
        bool is_string = false;
        for (char c : s)
        {
            if (c == ' ' || c == '\"' || c == ',' || c == ')' || c == '(')
            {
                if (c == '\"')
                {
                    is_string = !is_string;
                    continue;
                }
                if (!is_string)
                {
                    if (word.empty())
                    {
                        continue;
                    }
                    else
                    {
                        tokens.push_back(word);
                        word = "";
                    }
                    continue;
                }
            }
            word += c;
        }

        if (tokens.size() == 1)
        { // try
            k_tries++;
        }
        else if (tokens.size() == 2)
        { // throw EXC
            throw_lvl = k_tries;
            exc_type = tokens[1];
        }
        else if (tokens.size() == 3)
        { // catch EXC msg
            if (k_tries == throw_lvl)
            {
                first_checked = true;
                if (tokens[1] == exc_type && !found)
                {
                    exc_msg = tokens[2];
                    found = true;
                }
                throw_lvl--;
            }
            k_tries--;
        }

        // __print(tokens);
    }
    cout << exc_msg << endl;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;
    // cin >> qs;

    while (qs--)
    {
        solution();
    }
    return 0;
}