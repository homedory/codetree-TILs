#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 10005

int uf[MAX_N];
int n, m;
char type[MAX_N];

void initialize() {
    for (int i = 1; i <= n; i++)
        uf[i] = i;
}

int find(int node) {
    if (node == uf[node])
        return node;
    
    return uf[node] = find(uf[node]);
}

void unionNodes(int node1, int node2) {
    int uf1 = find(node1);
    int uf2 = find(node2);
    uf[uf1] = uf2;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> type[i];
    }

    vector <tuple<int,int,int>> edges;
    for (int i = 0; i < m; i++) {
        int node1, node2, weight;
        cin >> node1 >> node2 >> weight;
        edges.push_back({weight, node1, node2});
    }

    initialize();

    sort(edges.begin(), edges.end());

    int weight_sum = 0;
    int edge_count = 0;
    for (auto e : edges) {
        int node1, node2, weight;
        tie(weight, node1, node2) = e;

        if (type[node1] == type[node2] || find(node1) == find(node2))
            continue;
        
        unionNodes(node1, node2);
        weight_sum += weight;
        edge_count++;
    }

    cout << ((edge_count == n-1) ? weight_sum : -1);
    
    return 0;
}