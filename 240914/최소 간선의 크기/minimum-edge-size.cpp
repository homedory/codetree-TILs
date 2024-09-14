#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 100005

int n, m;
int parent[MAX_N];

void initialize() {
    for (int i = 1; i <= n; i++) 
        parent[i] = i;
}

int findRoot(int node) {
    if (parent[node] == node)
        return node;
    
    return parent[node] = findRoot(parent[node]);
}

void unionNodes(int node1, int node2) {
    int node1_root = findRoot(node1);
    int node2_root = findRoot(node2);

    parent[node1_root] = node2_root;
}

int main() {
    int a, b;
    vector <tuple<int,int,int>> edge;

    cin >> n >> m;
    cin >> a >> b;

    initialize();
    for (int i = 0; i < m; i++) {
        int node1, node2, satisfaction;
        cin >> node1 >> node2 >> satisfaction;
        edge.push_back({-satisfaction, node1, node2});
    }

    sort(edge.begin(), edge.end());

    for (auto e : edge) {
        auto [satisfaction, node1, node2] = e;
        satisfaction = -satisfaction;

        unionNodes(node1, node2);
        if (findRoot(a) == findRoot(b)) {
            cout << satisfaction;
            return 0;
        }
    }

    return 0;
}