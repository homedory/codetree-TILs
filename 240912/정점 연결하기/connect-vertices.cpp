#include <iostream>
using namespace std;

#define MAX_N 100005

int n;
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

    if (node1_root > node2_root)
        parent[node1_root] = node2_root;
    else
        parent[node2_root] = node1_root;
}

int main() {
    cin >> n;

    initialize();

    for (int i = 0; i < n-2; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        unionNodes(node1, node2);
    }

    int root1 = findRoot(1);
    int root2;
    for (int i = 2; i <= n; i++) {
        if (findRoot(i) != root1) {
            root2 = findRoot(i);
            break;
        }
    }
    
    cout << root1 << " " << root2;

    return 0;
}