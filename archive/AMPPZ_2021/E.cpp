#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, b) FOR(i, 0, b)
#define all(x) (x).begin(), (x).end()

template <typename T>
using vec = vector<T>;
using vi = vec<ll>;

using ll = long long;

enum Status { Infected, Clear, Uknown, Quarantine, Count };

struct Node {
    set<int> ids;
    set<int> nbors;
    bool is_last = false;
    Status status = Uknown;
};

struct solution {
    int nStatus[Status::Count] = {};
    set<int> potInfected;
    vi pToNode;
    vi pToStatus;
    vec<Node> nodes;
    int getInfected(int idx) {
        if (potInfected.find(idx) != potInfected.end()) {
            return idx;
        } else {
            auto it = potInfected.upper_bound(idx);
            if (it != potInfected.end()) {
                return *it;
            } else {
                return *potInfected.begin();
            }
        }
    }

    void infectNode(int nodeId) {
        auto& node = nodes[nodeId];
        if (node.status == Infected) {
            return;
        }
        for (int id : node.ids) {
            changeStatus(id, Infected);
        }
        if (!node.is_last && node.nbors.size() == 1) {
            infectNode(*node.nbors.begin());
        }
    }
    void clearNode(int nodeId) {
        auto& node = nodes[nodeId];
        if (node.status == Clear) {
            return;
        }
        for (int id : node.ids) {
            changeStatus(id, Clear);
        }
        if (!node.is_last) {
            for (int nborId : node.nbors) {
                clearNode(nborId);
            }
        }
    }

    int addMeet() {
        nodes.emplace_back();
        return nodes.size() - 1;
    }

    void changeStatus(int id, Status status) {
        if (pToStatus[id] == status) {
            return;
        }
        nStatus[pToStatus[id]]--;
        nStatus[status]++;
        pToStatus[id] = status;
        if (status == Uknown) {
            potInfected.emplace(id);
        }
        if (status == Infected) {
            potInfected.emplace(id);
            infectNode(pToNode[id]);
        }
        if (status == Clear) {
            potInfected.erase(id);
            clearNode(pToNode[id]);
        }
        if (status == Quarantine) {
            potInfected.erase(id);
            auto& node = nodes[pToNode[id]];
            node.ids.erase(id);
            infectNode(pToNode[id]);
        }
    }

    void movePersonTo(int id, int nodeId) {
        Node& node = nodes[nodeId];
        node.ids.push_back(id);
        Status status = pToStatus[id];
        if (status == Clear) {
            if (node.ids.size() == 1) {
                node.status = Clear;
            } else {
                changeStatus(id, node.status);
            }
        }
        if (status == Uknown) {
            if (node.status == Clear) {
                node.status = Uknown;
            }
            if (node.status ==) }

        int lastNodeId = pToNode[id];
        auto& lastNode = nodes[lastNodeId];
        lastNode.ids.erase(id);
        if (lastNode.ids.empty() && lastNode.nbors.empty()) {
            removeNode(lastNodeId);
        }
    }

    int n, shift = 0;
    int decode(int p) { return ((p - 1 + shift) % n); }
    solution() {
        int k;
        cin >> n >> k;
        pToNode.resize(n);
        pToStatus.resize(n, Uknown);
        iota(all(pToNode), 0);
        F0R(i, n) {
            Node node;
            node.is_last = true;
            node.ids.emplace(i);
            changeStatus(i, Uknown);
        }
        F0R(i, k) {
            char a;
            cin >> a;
            if (a == 'K') {
                int c;
                cin >> c;
                int idNode = addMeet();
                F0R(j, c) {
                    int p;
                    cin >> p;
                    int idx = decode(p);
                    movePersonTo(idx, idNode);
                }
            } else if (a == 'N') {
                int p;
                cin >> p;
                int idx = decode(p);
                changeStatus(idx, Clear);
            } else if (a == 'P') {
                int p;
                cin >> p;
                int idx = decode(p);
                changeStatus(idx, Quarantine);
            } else if (a == 'Q') {
                if (nStatus[Infected] || nStatus[Uknown]) {
                    int p;
                    cin >> p;
                    int idx = getInfected(decode(p));
                    shift = idx + 1;
                    cout << "NIE " << idx + 1 << '\n';

                } else {
                    cout << "TAK\n";
                    shift = 0;
                }
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qs = 1;  //
    cin >> qs;

    while (qs--) {
        solution();
    }
}