#include <bits/stdc++.h>
using namespace std;

template <class T, size_t N>
array<T, N> make_array(const T &v)
{
    array<T, N> ret;
    ret.fill(v);
    return ret;
}
class AhoCorasic
{
    static constexpr int N_A = 'z' - 'a' + 1;
    using GoTo = vector<array<int, N_A>>;
    using Fail = vector<int>;
    using Output = vector<int>;
    using Ends = vector<int>;
    using ReFail = vector<Fail>;
    static constexpr int FAIL = -1;
    array<int, N_A> NEW_STATE = make_array<int, N_A>(FAIL);

    GoTo g = {NEW_STATE};
    Output out;
    Fail fail;
    ReFail re_fail;
    Ends ends;
    int last_state = 0;

public:
    AhoCorasic(const vector<string> &words)
    {
        ends.resize(words.size());
        int i = 0;
        for (auto &s : words)
        {
            ends[i++] = add(s);
        }
        const size_t n_states = g.size();
        out.resize(n_states, 0);
        fail.resize(n_states);
        re_fail.resize(n_states);
        for (int j = 0; j < N_A; j++)
        {
            if (g[0][j] == FAIL)
                g[0][j] = 0;
        }
        make_fail(g, fail, out);
    }

    void re_add(int index, int ch = 1)
    {
        int state = ends[index];
        /*for (int i = 0; i < w.size(); i++) {
			state = g[state][w[i] - 'a'];
		}*/
        Fail to_process = re_fail[state];
        out[state] += ch;
        while (!to_process.empty())
        {
            state = to_process.back();
            to_process.pop_back();
            out[state] += ch;
            to_process.insert(to_process.end(), re_fail[state].begin(), re_fail[state].end());
        }
    }

    int count(const string &w)
    {
        int n = 0;
        int state = 0;
        for (int i = 1; i < w.size(); i++)
        {
            while (g[state][w[i] - 'a'] == FAIL)
                state = fail[state];
            state = g[state][w[i] - 'a'];
            n += out[state];
        }
        return n;
    }

private:
    int add(const string &s)
    {
        int state = 0, j = 0;
        while (j < s.size() && g[state][s[j] - 'a'] != FAIL)
        {
            state = g[state][s[j] - 'a'];
            ++j;
        }
        for (; j < s.size(); j++)
        {
            ++last_state;
            g.emplace_back(NEW_STATE);
            g[state][s[j] - 'a'] = last_state;
            state = last_state;
        }
        out.resize(g.size());
        out[state] += 1;
        return state;
    }

    void make_fail(const GoTo &g, Fail &fail, Output &out)
    {
        queue<int> q;
        for (int j = 0; j < N_A; ++j)
        {
            const auto s = g[0][j];
            if (s == 0)
                continue;

            q.push(s);
            set_fail(s, 0);
        }
        while (!q.empty())
        {
            const auto r = q.front();
            q.pop();
            for (int i = 0; i < N_A; i++)
            {
                const auto s = g[r][i];

                if (s == FAIL)
                    continue;

                q.push(s);
                auto state = fail[r];
                while (g[state][i] == FAIL)
                    state = fail[state];
                set_fail(s, g[state][i]);
                out[s] += out[fail[s]];
            }
        }
    }

    void set_fail(int index, int val)
    {
        fail[index] = val;
        re_fail[val].push_back(index);
    }
};