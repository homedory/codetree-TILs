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
    int node1_root = findRoot(node1);
    int node2_root = findRoot(node2);

    parent[node1_root] = node2_root;
}

int main() {
    cin >> n >> m;

    initialize();
    
    for (int i = 1; i <= m; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        if (findRoot(node1) == findRoot(node2)) {
            cout << i;
            return 0;
        }
        unionNodes(node1, node2);
    }

    cout << "happy";

    return 0;
}