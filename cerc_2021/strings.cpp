#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define ZERO (1e-10)
#define INF int(1e9 + 1)
#define CL(A, I) (memset(A, I, sizeof(A)))
#define DEB printf("DEB!\n");
#define D(X) cout << "  " << #X ": " << X << endl;
#define EQ(A, B) (A + ZERO > B && A - ZERO < B)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define IN(n) \
    int n;    \
    scanf("%d", &n);
#define FOR(i, m, n) for (int i(m); i < n; i++)
#define F(n) FOR(i, 0, n)
#define FF(n) FOR(j, 0, n)
#define FT(m, n) FOR(k, m, n)
#define aa first
#define bb second
void ga(int N, int *A) { F(N) scanf("%d", A + i); }
#define MX (106)
#define AL (26)
int g[MX][AL], f[MX], E, q[MX], O[MX];
void ini() {
    E = 1;
    F(AL) g[0][i] = 0;
    CL(f, 0), CL(O, 0);
}
void add(char *s) {
    int L = strlen(s), u = 0, c;
    F(L) {
        if (!g[u][c = s[i] - 97]) {
            g[u][c] = E++;
            F(AL) g[E - 1][i] = 0;
        }
        u = g[u][c];
    }
    O[u] = 1;
}
void bld() {
    int x, r, b = -1, e = 0, u;
    F(AL) if (g[0][i]) f[g[0][i]] = 0, q[e++] = g[0][i];
    while (++b < e) F(AL) {
            x = g[u = q[b]][i], r = g[f[u]][i];
            if (!x)
                g[u][i] = r;
            else {
                q[e++] = x, f[x] = r;
                O[x] |= O[r];
            }
        }
}
#define MM (MX)
void mul(int A[MM][MM], int B[MM][MM], int R[MM][MM], int W, int M) {
    F(W) FF(W) R[i][j] = 0;
    F(W) FF(W) {
        ll D = M * 1ll * M, S = 0;
        ;
        FT(0, W) if ((S += A[i][k] * 1ll * B[k][j]) >= D) S -= D;
        R[i][j] = S % M;
    }
}
void pw(int M[MM][MM], int R[MM][MM], int W, ll k, int MD) {
    static int E[MM][MM], H[MM][MM];
    F(W) FF(W) R[i][j] = E[i][j] = i == j;
    while (k) {
        if (k & 1) mul(E, M, R, W, MD), memcpy(E, R, sizeof(E));
        mul(M, M, H, W, MD);
        memcpy(M, H, sizeof(H));
        k >>= 1;
    }
}
#define MOD 1000000007
ll pw(ll n, ll k) {
    ll r(1);
    while (k) {
        if (k & 1) r *= n, r %= MOD;
        n *= n, n %= MOD;
        k >>= 1;
    }
    return r;
}
char s[MX];
int L, N, Q, M[MX][MX], R[MX][MX];
int main(void) {
    scanf("%d%d", &N, &Q), ini();
    F(Q) {
        scanf("%*d%s", s);
        add(s);
    }
    bld();
    F(E) FF(26) if (O[g[i][j]])++ M[i][E];
    else ++M[i][g[i][j]];
    M[E][E] = 26;
    pw(M, R, E + 1, N, MOD);
    printf("%lld\n", (pw(26, N) - R[0][E] + MOD) % MOD);
    return 0;
}
