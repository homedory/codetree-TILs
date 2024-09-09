#include <iostream>
using namespace std;

#define MAX_N 100005

int n, m;
int parent[MAX_N];

int find(int node) {
    if (parent[node] == node)
        return node;
    
    return parent[node] = find(parent[node]);
}

void unioNodes(int node1, int node2) {
    int node1_parent = find(node1);
    int node2_parent = find(node2);

    if (node1_parent == node2_parent)
        return;
    
    parent[node1_parent] = node2_parent;
}

void init() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}

int main() {
    cin >> n >> m;

    init();
    
    for (int i = 0; i < m; i++) {
        int operation, node1, node2;
        cin >> operation >> node1 >> node2;

        if (operation == 0) 
            unioNodes(node1, node2);
        
        else 
            cout << ((find(node1) == find(node2)) ? 1 : 0) << "\n";
    }


    return 0;
}