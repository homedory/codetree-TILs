#include <iostream>
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
    int node1_parent = findRoot(node1);
    int node2_parent = findRoot(node2);

    parent[node1_parent] = node2_parent;
}

int main() {
    cin >> n >> m;

    initialize();

    int operation_count = 0;
    int edge_count = 0;
    for (int i = 0; i < m; i++) {
        int node1, node2;
        cin >> node1 >> node2;

        if (findRoot(node1) == findRoot(node2))
            operation_count++;
        else {
            unionNodes(node1, node2);
            edge_count++;
        }
    }
    if (n-1-edge_count > 0)
        operation_count += (n - 1 - edge_count);

    cout << operation_count;
    
    return 0;
}