#include <iostream>
using namespace std;

#define MAX_N 100005

int n, m, k;
int parent[MAX_N];

int findParent(int node) {
    if (parent[node] == node)
        return node;
    
    return parent[node] = findParent(parent[node]);
}

void unionNodes(int node1, int node2) {
    int node1_parent = findParent(node1);
    int node2_parent = findParent(node2);

    if (node1_parent == node2_parent)
        return;
    
    parent[node1_parent] = node2_parent;
}

void initialize() {
    for (int i = 1; i <= n; i++)
        parent[i] = i;
}

int main() {
    cin >> n >> m >> k;

    initialize();

    for (int i = 0; i < m; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        unionNodes(node1, node2);
    }

    int node, root;
    cin >> node;
    root = findParent(node);
    for (int i = 0; i < k-1; i++) {
        cin >> node;
        if (root != findParent(node)) {
            cout << 0;
            return 0; 
        }
    }

    cout << 1;
    
    return 0;
}