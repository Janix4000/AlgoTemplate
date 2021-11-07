#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, b) FOR(i, 0, b)
#define all(x) (x).begin(), (x).end()

template <typename T>
using vec = vector<T>;

using ll = long long;
constexpr ll INF = 1000000000LL;

using vi = vec<ll>;
using vvi = vec<vi>;
using vvvi = vec<vvi>;

#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

struct Point
{
    ll x, y;
    bool operator<(const Point &rhs) const
    {
        if (x == rhs.x)
        {
            return y < rhs.y;
        }
        return x < rhs.x;
    }
    Point operator+(const Point &rhs) const
    {
        return {x + rhs.x, y + rhs.y};
    }
    Point operator-() const
    {
        return {-x, -y};
    }
    bool operator==(const Point &rhs) const { return x == rhs.x && y == rhs.y; }
};

void solution()
{
    int n;
    cin >> n;
    Point alice;
    cin >> alice.x >> alice.y;
    alice.x--;
    alice.y--;
    Point bob;
    cin >> bob.x >> bob.y;
    bob.x--;
    bob.y--;

    vec<Point> moves(n);
    random_device rd;
    mt19937 rng(rd());
    F0R(i, n)
    {
        cin >> moves[i].x >> moves[i].y;
    }
    const auto canColide = [&](Point a, Point b) -> bool
    {
        set<Point> left;
        set<Point> right;
        for (auto &move : moves)
        {
            auto p = move + a;
            if (p.x < 0 || p.x >= n || p.y < 0 || p.y >= n)
            {
                continue;
            }
            left.emplace(p);
        }
        left.emplace(a);
        for (auto &move : moves)
        {
            auto p = (-move) + b;
            if (p.x < 0 || p.x >= n || p.y < 0 || p.y >= n)
            {
                continue;
            }
            right.emplace(p);
        }
        right.emplace(b);
        vec<Point> intersect;
        set_intersection(all(left), all(right), back_inserter(intersect));
        return !intersect.empty();
    };
    string res;
    if (canColide(alice, bob))
    {
        res = "Alice wins";
    }
    else
    {
        // vi xs(n);
        // iota(all(xs), 0);
        // xs[bob.x] = n - bob.x - 1;
        // vi ys(n);
        // iota(all(ys), 0);
        // ys[bob.y] = n - bob.y - 1;

        // shuffle(all(xs), rng);
        // shuffle(all(ys), rng);
        bool fucked = true;
        Point p;
        F0R(i, 50)
        {
            do
            {
                p = {uid(0, n - 1), uid(0, n - 1)};
            } while (p == bob);
            if (!canColide(bob, p))
            {
                fucked = false;
                break;
            }
        }
        if (fucked)
        {
            res = "Bob wins";
        }
        else
        {
            res = "tie " + to_string(p.x + 1) + " " + to_string(p.y + 1);
        }
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int qs = 1;
    // cin >> qs;
    while (qs--)
    {
        solution();
    }
}