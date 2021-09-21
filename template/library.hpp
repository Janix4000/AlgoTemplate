#include <bits/stdc++.h>
using namespace std;
struct Vec2
{
    int x = 0, y = 0;
    Vec2(int x, int y) : x(x), y(y) {}
    Vec2() = default;
    Vec2 &operator+=(const Vec2 &rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
    Vec2 operator-() const
    {
        return *this * -1;
    }
    Vec2 operator+(const Vec2 &rhs) const
    {
        auto res = *this;
        res += rhs;
        return res;
    }
    Vec2 &operator-=(const Vec2 &rhs)
    {
        return (*this += -rhs);
    }
    Vec2 operator-(const Vec2 &rhs) const
    {
        return *this + (-rhs);
    }
    Vec2 &operator*=(int rhs)
    {
        x *= rhs;
        y *= rhs;
        return *this;
    }
    Vec2 operator*(int rhs) const
    {
        auto res = *this;
        res *= rhs;
        return res;
    }
};

using It = string::iterator;
std::vector<int> get_kmp(It beg, It end)
{
    const size_t size = end - beg;
    std::vector<int> tab(size + 1);
    tab[0] = -1;
    int k = -1;

    for (size_t i = 0; i < size; ++i)
    {
        while (k != -1 && beg[k] != beg[i])
            k = tab[k];
        tab[i + 1] = ++k;
    }
    return tab;
}

template <class T>
struct Edge
{
    Edge(int dest, const T &value = 1) : dest(dest), value(value) {}
    int dest;
    T value;
    operator int() const { return dest; }
};

template <class T>
struct Node
{
    Node() = default;
    Node(const initializer_list<int> &destinations)
    {
        edges.reserve(destinations.size());
        for (int dest : destinations)
        {
            edges.emplace_back(dest);
        }
    }
    vector<Edge<T>> edges;
    bool visited;
    int parent;
    void push_back(int dest, int value = 1) { edges.emplace_back(dest, value); }
    Edge<T> &operator[](size_t idx) { return edges[idx]; }
    auto begin() { return edges.begin(); }
    auto end() { return edges.end(); }
};

template <class T>
using GraphT = vector<Node<T>>;

using Graph = GraphT<int>;

template <typename T>
void ___print(const Edge<T> &edge)
{
    ___print(make_pair(edge.dest, edge.value));
}
template <typename T>
void ___print(const Node<T> &node)
{
    ___print(node.edges);
}
template <typename T>
void ___print(const GraphT<T> &graph)
{
    int f = 0;
    for (auto &node : graph)
        cerr << (f++ ? "\n" : "") << f - 1 << ": ", ___print(node);
}

bool dfs(Graph &graph, int v = 0)
{
    const int n = (int)graph.size();
    vector<char> visited(n, false);
    //TODO to diff function
    function<int(int)> dfs_rec;
    dfs_rec = [&](int v) -> int
    {
        visited[v] = true;
        auto &node = graph[v];
        for (int e : node)
        {
            if (visited[e])
                continue;
            visited[e] = true;
            // pre

            int child_res = dfs_rec(e);
            if (child_res)
            {
                return true;
            }

            //post
        }
        return false;
    };
    for (int v = 0; v < graph.size(); ++v)
    {
        if (!visited[v])
        {
            dfs_rec(v);
        }
    }
    return false;
}

void bfs(Graph &graph, int start)
{
    const int n = (int)graph.size();
    queue<int> q;
    vector<char> visited(n, false);

    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        //process

        auto &node = graph[v];
        for (int e : node)
        {
            if (visited[e])
                continue;
            q.push(e);
            visited[e] = true;
        }
    }
}

template <typename T = long long>
class SegTree
{
private:
    int size = 0;
    vec<T> tree;
    vec<T> bag;
    const T neutral;

public:
    SegTree(int n, const T &neutral = T(0)) : neutral{neutral}
    {
        calculate_size(n);
    }

    SegTree(const vec<T> &tab, const T &neutral = T(0)) : neutral{neutral}
    {
        const int n = (int)tab.size();
        calculate_size(n);
        for (int i = 0; i < n; i++)
        {
            tree[2 * i + 1] = tab[i];
        }
        update_from_roots(0, size);
    }
    void modify(int l, int r, const T &v)
    {
        modify(l, r, 0, size, v);
    }

    T query(int l, int r)
    {
        return query(l, r, 0, size);
    }

private:
    void modify(int l, int r, int b, int e, const T &v)
    {
        if (l >= e || r <= b)
        {
            return;
        }
        if (b >= l && e <= r)
        {
            update_whole_segment(b, e, v);
        }
        else
        {
            propagate_bag(b, e);
            const int be = (e - b) / 2;
            modify(l, r, b, b + be, v);
            modify(l, r, b + be, e, v);
            //MODIFY
            tree[b + e] = tree[b + b + be] + tree[b + be + e];
        }
    }
    void update_whole_segment(int b, int e, const T &v)
    {
        const int n = e - b;
        //MODIFY
        tree[b + e] += n * v;
        bag[b + e] += v;
    }
    T query(int l, int r, int b, int e)
    {
        if (l >= e || r <= b)
        {
            return neutral;
        }
        if (b >= l && e <= r)
        {
            return tree[b + e]; // + (e - b) * bag[b + e];
        }
        else
        {
            int be = (e - b) / 2;
            propagate_bag(b, e);
            const auto left_query = query(l, r, b, b + be);
            const auto right_query = query(l, r, b + be, e);

            // MODIFY
            return left_query + right_query;
        }
    }
    void propagate_bag(int b, int e)
    {
        const int be = (e - b) / 2;
        const int n = e - b;
        if (bag[b + e] != neutral)
        {
            const T add = bag[b + e];
            bag[b + e] = neutral;

            //MODIFY
            tree[b + b + be] += n * add / 2;
            tree[b + be + e] += n * add / 2;

            bag[b + b + be] += add;
            bag[b + be + e] += add;
        }
    }
    void update_from_roots(int l, int r)
    {
        if (r - l > 1)
        {
            int lr = (r - l) / 2;
            update_from_roots(l, l + lr);
            update_from_roots(l + lr, r);
            //MODIFY
            tree[l + r] = tree[l + l + lr] + tree[l + lr + r];
        }
    }
    void calculate_size(int n)
    {
        n -= 1;
        size = 1;
        while (n > 0)
        {
            size *= 2;
            n /= 2;
        }
        const int whole_size = size * 2 - 1;
        tree.clear();
        tree.resize(whole_size, neutral);
        bag.clear();
        bag.resize(whole_size, neutral);
    }
};

template <typename T, size_t N>
class Vector : public array<T, N>
{
    Vector &operator+=(const Vector<T, N> &rhs)
    {
        transform(rhs.begin(), rhs.end(), this->begin(), this->begin(), plus<T>{});
        return *this;
    }
    Vector operator-() const
    {
        return *this * -1;
    }
    Vector operator+(const Vector<T, N> &rhs) const
    {
        auto res = *this;
        res += rhs;
        return res;
    }
    Vector &operator-=(const Vector<T, N> &rhs)
    {
        return (*this += -rhs);
    }
    Vector operator-(const Vector<T, N> &rhs) const
    {
        return *this + (-rhs);
    }
    Vector &operator*=(int rhs)
    {
        transform(rhs.begin(), rhs.end(), this->begin(), this->begin(), multiplies<T>{});
        return *this;
    }
    Vector operator*(int rhs) const
    {
        auto res = *this;
        res *= rhs;
        return res;
    }
};

using ll = long long;
constexpr ll P = 1000000007;

ll power(ll a, ll n, const ll P = P)
{
    ll res = 1;
    while (n)
    {
        if (n % 2)
        {
            res = (res * a) % P;
        }
        n /= 2;
        a = (a * a) % P;
    }
    return res;
}

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