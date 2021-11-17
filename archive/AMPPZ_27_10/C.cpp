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
    int R1, P1, S1;
    int R2, P2, S2;
    cin >> R1 >> P1 >> S1;
    cin >> R2 >> P2 >> S2;

    int res = 0;
    if(R2 >= S1) {
        res += R2 - S1;
        R2 -= S1;
        S1 = 0;
    }
    if(P2 >= R1) {
        res += P2 - R1;
        P2 -= R1;
        R1 = 0;
    }
    if(S2 >= P1) {
        res += S2 - P1;
        S2 -= P1;
        P1 = 0;
    }



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