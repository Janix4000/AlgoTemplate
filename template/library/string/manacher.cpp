#include <string>
#include <vector>

using namespace std;
using vi = std::vector<int>;

// sh = 0 dla palindromow nieparzystych, 1 dla parzystych
// aaaa -> sh=0 [1, 2, 2, 1] sh=1 [0, 1, 2, 1]
vi manacher(const string& w, int sh) {
    int g = 0;
    int n = w.size();
    vi p(n);
    p[0] = 1 - sh;
    for (int i = 1; i < n; i++) {
        p[i] = 2 * g - i >= 0 ? max(min(p[2 * g - i], p[g] + g - i), 0) : 0;
        while (i >= p[i] + sh && i + p[i] < n &&
               w[i + p[i]] == w[i - p[i] - sh])
            p[g = i]++;
    }
}