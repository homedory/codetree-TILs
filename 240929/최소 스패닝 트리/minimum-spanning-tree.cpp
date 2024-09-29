#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 10005

int n, m;
int uf[MAX_N];

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
    int uf_node1 = find(node1);
    int uf_node2 = find(node2);

    uf[uf_node1] = uf_node2;
}

int main() {
    cin >> n >> m;
    initialize();

    vector <tuple<int,int,int>> edges;
    for (int i = 0; i < m; i++) {
        int node1, node2, weight;
        cin >> node1 >> node2 >> weight;
        edges.push_back({weight, node1, node2});
    }

    sort(edges.begin(), edges.end());

    int weight_sum = 0;
    for (auto e : edges) {
        int node1, node2, weight;
        tie(weight, node1, node2) = e;

        if (find(node1) == find(node2))
            continue;
        
        unionNodes(node1, node2);
        weight_sum += weight;
    }

    cout << weight_sum;


    return 0;
}