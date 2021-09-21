#include <bits/stdc++.h>
using namespace std;

template <class T>
struct Edge
{
    /////////////////////////////////////////////////////////////////////////////////////
    int dest;
    T value;
    /////////////////////////////////////////////////////////////////////////////////////

    Edge(int dest, const T &value = 1) : dest(dest), value(value) {}
    operator int() const { return dest; }
};

template <class T>
struct Node
{
    /////////////////////////////////////////////////////////////////////////////////////
    vector<Edge<T>> edges;
    bool visited;
    int parent;
    /////////////////////////////////////////////////////////////////////////////////////

    Node() = default;
    Node(const initializer_list<int> &destinations)
    {
        edges.reserve(destinations.size());
        for (int dest : destinations)
        {
            edges.emplace_back(dest);
        }
    }
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