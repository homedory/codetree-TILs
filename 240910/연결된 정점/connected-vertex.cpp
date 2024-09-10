#include <iostream>
using namespace std;

#define MAX_N 100005

int n, m;
int parent[MAX_N], node_count[MAX_N];

void initialize() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        node_count[i] = 1;
    }
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
    node_count[node2_root] += node_count[node1_root];
}

int main() {
    cin >> n >> m;
    initialize();

    for (int i = 0; i < m; i++) {
        char operation;
        int a, b;
        cin >> operation;
        if (operation == 'x') {
            cin >> a >> b;
            unionNodes(a, b);
        }
        else if (operation == 'y') {
            cin >> a;
            int root = findRoot(a);
            cout << node_count[root] << "\n";
        }
    }


    return 0;
}