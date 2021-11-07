#include "bits/stdc++.h"
using namespace std;

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
