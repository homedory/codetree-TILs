#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 100005

int n, m, k;
int parent[MAX_N], node_count[MAX_N];

void initailize() {
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

    if (node1_root != node2_root) {
        node_count[node2_root] += node_count[node1_root];
        node_count[node1_root] = 0;
    }

    parent[node1_root] = node2_root;
}

int main() {
    cin >> n >> m;
    initailize();

    for (int i = 0; i < m; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        unionNodes(node1, node2);
    }

    int A_node, B_node;
    cin >> A_node >> B_node >> k;

    int A_root = findRoot(A_node);
    int B_root = findRoot(B_node);

    int ans = node_count[A_root];

    vector <int> separated_node_count;
    for (int i = 1; i <= n; i++) {
        int root = findRoot(i);
        if (root == A_root || root == B_root || node_count[root] == 0)
            continue;
        
        separated_node_count.push_back(node_count[i]);
    }

    sort(separated_node_count.begin(), separated_node_count.end(), greater<int>());

    int idx = 0;
    while(idx < separated_node_count.size()) {
        ans += separated_node_count[idx];

        idx++;
        if (idx >= k)
            break;
    }

    cout << ans;


    return 0;
}