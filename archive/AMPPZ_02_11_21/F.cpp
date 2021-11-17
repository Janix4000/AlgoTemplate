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

struct Time
{
    ll x_diff, v_diff;
    int i0, i1;

    Time(ll x0, ll v0, int i0, ll x1, ll v1, int i1) : i0(i0), i1(i1)
    {
        x_diff = x1 - x0;
        v_diff = v1 - v0;
    }

    bool operator>(const Time &rhs) const
    {
        return -x_diff * rhs.v_diff > -rhs.x_diff * v_diff;
    }
    // bool operator<(const Time &rhs) const
    // {
    //     return -x_diff * rhs.x_diff < -rhs.v_diff * v_diff;
    // }
};

template <typename T>
using min_pq = priority_queue<T, vec<T>, greater<T>>;

struct Drone
{
    int x, v, i;
    int left = -1, right = -1;
    Drone() = default;
    Drone(int x, int v, int i) : x{x}, v{v}, i{i} {}
};

void solution()
{
    min_pq<Time> times;
    int n;
    cin >> n;

    vec<Drone> drones(n);

    vi used(n, false);

    F0R(i, n)
    {
        int x, v;
        cin >> x >> v;
        Drone drone{x, v, i};
        drones[i] = drone;
        if (i > 0)
        {
            drones[i].left = i - 1;
            drones[i - 1].right = i;
        }
    }

    FOR(i, 1, n)
    {
        times.emplace(drones[i - 1].x, drones[i - 1].v, i - 1, drones[i].x, drones[i].v, i);
    }

    set<int> survivors;

    while (!times.empty())
    {
        auto t = times.top();
        times.pop();
        if (used[t.i0] || used[t.i1])
        {
            if (times.empty())
            {
                if (!used[t.i0])
                {
                    survivors.emplace(t.i0);
                }
                if (!used[t.i1])
                {
                    survivors.emplace(t.i1);
                }
            }
            continue;
        }
        if (t.v_diff >= 0)
        {
            survivors.emplace(t.i0);
            survivors.emplace(t.i1);
        }
        else
        {
            int i0 = t.i0;
            int i1 = t.i1;

            auto &l_drone = drones[i0];
            auto &r_drone = drones[i1];

            used[i0] = true;
            used[i1] = true;

            if (r_drone.right != -1)
            {
                drones[r_drone.right].left = l_drone.left;
            }
            if (l_drone.left != -1)
            {
                drones[l_drone.left].right = r_drone.right;
            }

            if (l_drone.left != -1 && r_drone.right != -1)
            {
                times.emplace(drones[l_drone.left].x, drones[l_drone.left].v, l_drone.left, drones[r_drone.right].x, drones[r_drone.right].v, r_drone.right);
            }
        }
    }
    cout << survivors.size() << endl;
    for (int s : survivors)
    {
        cout << s + 1 << ' ';
    }
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