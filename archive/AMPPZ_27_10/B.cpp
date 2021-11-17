#include <bits/stdc++.h>

template <typename... Ts>
void __print(Ts &&...ts) {}
#ifdef DEBUG
#include "print.hpp"
#endif // DEBUG

using namespace std;

template <typename T>
using vec = vector<T>;

using vi = vec<int>;

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////

void solution()
{
    int N, K, M;
    cin >> N >> K >> M;
    M--;
    vi ings(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> ings[i];
    }

    map<int, vi> tourists;
    for (int i = 0; i < N; ++i)
    {
        tourists[ings[i]].push_back(i);
    }
    vi happines(N, 0);
    int last_t = M % N;
    for (auto &[ing, ts] : tourists)
    {
        int n = ts.size();
        if (n % 2 == 0)
        {
            for (int j = 0; j < n; ++j)
            {
                int base = 0;
                int idx = ts[j];

                if (j % 2 == 0)
                {
                    base = 0;
                }
                else
                {
                    base = M / N;
                    if (idx <= last_t)
                    {
                        base++;
                    }
                }
                happines[idx] = base;
            }
        }
        else
        {
            int cycles = M / N;
            for (int j = 0; j < n; ++j)
            {
                int base = 0;
                int idx = ts[j];
                if (j % 2 == 0)
                {
                    base = cycles / 2;
                    if (cycles % 2 == 1 && idx <= last_t)
                    {
                        base++;
                    }
                }
                else
                {
                    base = (cycles + 1) / 2;
                    if (cycles % 2 == 0 && idx <= last_t)
                    {
                        base++;
                    }
                }

                happines[idx] = base;
            }
        }
    }
    for (int i = 0; i < N - 1; ++i)
    {
        cout << happines[i] << " ";
    }
    cout << happines.back() << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;
    cin >> qs;

    while (qs--)
    {
        solution();
    }
    return 0;
}