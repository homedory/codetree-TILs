#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 100005

int n, m;
int parent[MAX_N];
vector <int> k_array;

void initialize() {
    for (int i = 0; i <= n; i++) 
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

    if (node1_root < node2_root)
        parent[node2_root] = node1_root;
    else
        parent[node1_root] = node2_root;
}

int main() {
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        k_array.push_back(k);
    }

    initialize();

    int ans = 0;
    for (auto k : k_array) {
        int position = findRoot(k);
        if (position <= 0)
            break;
        ans++;
        unionNodes(position-1, position);
    }

    cout << ans;

    return 0;
}