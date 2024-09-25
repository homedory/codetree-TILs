#include <iostream>
using namespace std;

#define MAX_N 100000

int n;
int uf[MAX_N+1], node_count[MAX_N+1];

void initialize() {
    for (int i = 1; i <= MAX_N; i++) {
        uf[i] = i;
        node_count[i] = 1;
    }
}

int find(int node) {
    if (node == uf[node])
        return node;

    return uf[node] = find(uf[node]);
}

void unionNodes(int node1, int node2) {
    int node1_root = find(node1);
    int node2_root = find(node2);

    if (node1_root == node2_root)
        return;

    uf[node1_root] = node2_root;
    node_count[node2_root] += node_count[node1_root];
}

int main() {
    cin >> n;
    initialize();

    for (int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        unionNodes(a, b);
        cout << node_count[find(a)] << "\n";
    }
    
    return 0;
}