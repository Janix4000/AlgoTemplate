#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct aho_corrasic {
    static constexpr int N_WORDS = int('z' - 'a' + 1);
    static constexpr int FAIL = -1;
    static constexpr int START_STATE = 0;
    struct Transition : public array<int, N_WORDS> {
        Transition(int next_state = FAIL)    { fill(next_state); }
        int &operator[](char idx) {
            return array<int, N_WORDS>::operator[](idx - 'a');
        }
        int operator[](char idx) const {
            return array<int, N_WORDS>::operator[](idx - 'a');
        }
    };
    using GoTo = vector<Transition>;
    using Fail = vector<int>;
    using Output = vector<vector<string>>;

    GoTo g;
    Fail f;
    Output o;

    void add_key(const string &key) {
        auto state = START_STATE;
        for (auto c : key) {
            auto &node = g[state];
            const int next_state = node[c];
            if (next_state == FAIL || next_state == START_STATE) {
                state = (int)g.size();
                node[c] = state;
                g.emplace_back();
                o.emplace_back();
            } else {
                state = next_state;
            }
        }
        o[state].push_back(key);
    }

    void construct_trie(const vector<string> &keywords) {
        for (auto &key : keywords) {
            add_key(key);
        }
    }

    void construct_failure() {
        const auto &start = g.front();
        queue<int> q;
        for (char c = 'a'; c <= 'z'; ++c) {
            if (start[c] != START_STATE) {
                auto next_state = start[c];
                q.push(next_state);
                f[next_state] = START_STATE;
            }
        }
        while (!q.empty()) {
            const auto &node = g[q.front()];
            q.pop();
            for (char c = 'a'; c <= 'z'; ++c) {
                auto next_state = node[c];
                if (next_state != FAIL) {
                    q.push(next_state);
                    auto state = f[next_state];
                    while (state == FAIL) {
                        state = f[state];
                    }
                    f[next_state] = g[state][c];
                    o[next_state].assign(o[f[next_state]].begin(),
                                         o[f[next_state]].end());
                }
            }
        }
    }

    void query(const string &txt) {
        auto state = START_STATE;
        for (auto c : txt) {
            const auto next_state = g[state][c];
            if (next_state == FAIL) {
                state = f[state];
            } else {
                state = next_state;
            }
        }
        for (auto &key : o[state]) {
            cout << key << ' ';
        }
        cout << endl;
    }

    aho_corrasic(const vector<string> &keywords) {
        g.emplace_back(START_STATE);
        construct_trie(keywords);
        construct_failure();
    }
};